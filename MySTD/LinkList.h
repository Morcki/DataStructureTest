#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdlib.h>
#include <iostream>
template <class T>
class LinkList { // single linked-list
private:
	class Node
	{
	public:
		T value;
		Node *next;
		Node():value(0),next(nullptr) {};
		Node(T data):value(data),next(nullptr) {};
		~Node() { delete next; };
	};
	Node *head;
	int len;
public:
	LinkList<T>();
	~LinkList<T>();
	inline int size(); // Returns the number of elements in the list
	bool empty(); // Returns whether the list is empty(1) or not(0)
	T front(); // Returns the value of the first element in the list
	T back(); // Returns the value of the last element in the list 
	void push_front(T value); // Adds a new element ¡®value¡¯ at the beginning of the list 
	void push_back(T value); // Adds a new element ¡®value¡¯ at the end of the list
	T pop_front(); // Removes the first element of the list, and reduces size of the list by 1
	T pop_back(); // Removes the last element of the list, and reduces size of the list by 1
	void insert_by_pos(int pos, T value); // Inserts new elements in the list before the element at a specified position
	void insert_by_val(T val, T value); // Inserts new elements in the list before the element of a specified value
	void reverse(); // Reverses the list
	void clear(); // remove all the elements of the list container, thus making it size 0
};
template<class T>
LinkList<T>::LinkList()
{
	// initial head node
	head = new Node();
	// LinkList length is Zero
	len = 0;
}
template<class T>
LinkList<T>::~LinkList()
{
	// destroy head node
	delete head;
}
template<class T>
inline int LinkList<T>::size()
{
	return len;
}
template<class T>
bool LinkList<T>::empty()
{
	return len > 0 ? 0 : 1;
}
template<class T>
inline T LinkList<T>::front()
{
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	return head->next->value;
}
template<class T>
inline T LinkList<T>::back()
{
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	Node *cur = head->next;
	while (cur->next)
	{
		cur = cur->next;
	}
	return cur->value;
}
template<class T>
void LinkList<T>::push_front(T value)
{
	// initial new node
	Node *node = new Node(value);
	if (head->next) {
		node->next = head->next;
		head->next = node;
	}
	else {
		head->next = node;
	}
	// size extends 1
	len++;
}
template<class T>
void LinkList<T>::push_back(T value)
{
	// initial new node
	Node *node = new Node(value);
	// current node
	Node *cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = node;
	// size extends 1
	len++;
}
template<class T>
T LinkList<T>::pop_front()
{
	// empty list
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	Node *node = head->next;
	head->next = node->next;
	// size reduces 1
	len--;
	return node->value;
}
template<class T>
T LinkList<T>::pop_back()
{
	// empty list
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	// use pre,cur to loop list
	Node *pre = head;
	Node *cur = head->next;
	while (cur->next) {
		pre = cur;
		cur = cur->next;
	}
	pre->next = nullptr;
	// size reduces 1
	len--;
	return cur->value;
}
template<class T>
void LinkList<T>::insert_by_pos(int pos, T value)
{
	if (pos > len) {
		printf("pos[%d] > LinkList length[%d]!\n", pos, len);
		exit(1);
	}
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	Node *node = new Node(value);
	Node *cur = head;
	while (--pos)
	{
		cur = cur->next;
	}
	node->next = cur->next;
	cur->next = node;
	len++;
}
template<class T>
void LinkList<T>::insert_by_val(T val, T value)
{
	if (!head->next) {
		printf("Empty LinkList!\n");
		exit(1);
	}
	Node *node = new Node(value);
	Node *pre = head;
	Node *cur = head->next;
	while (cur->next)
	{
		if (cur->value == val) {
			pre->next = node;
			node->next = cur;
			len++;
			return;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	printf("val not in LinkList!\n");
	exit(1);
}
template<class T>
inline void LinkList<T>::reverse()
{
	if ((!head->next)||len==1) {
		return;
	}
	Node *pre = head;
	Node *cur = head->next;
	Node *dump = nullptr;
	while (cur->next)
	{
		dump = cur->next;
		cur->next = pre;
		pre = cur;
		cur = dump;
	}
	cur->next = pre; // connect tail
	head->next->next = nullptr; // cut loop
	head->next = cur; // convert head
}
template<class T>
void LinkList<T>::clear()
{
	if (!head->next) {
		return;
	}
	delete head;
	head = new Node();
	len = 0;
}
#endif