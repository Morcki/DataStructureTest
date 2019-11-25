#pragma once
#ifndef DLINKLIST_H
#define DLINKLIST_H
#include <stdlib.h>
#include <iostream>
template<class T>
class DLinkList { // double linked-list
private:
	class Node {
	public:
		T value;
		Node *pre;
		Node *pos;
		Node():value(0), pre(nullptr), pos(nullptr) {};
		Node(T data):value(data), pre(nullptr), pos(nullptr) {};
		~Node() { delete pre; delete pos; };
	};
	Node *head;
	int len;
public:
	DLinkList();
	~DLinkList();
	int size(); // Returns the number of elements in the list
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
inline DLinkList<T>::DLinkList()
{
	head = new Node();
	len = 0;
}

template<class T>
inline DLinkList<T>::~DLinkList()
{
	delete head;
}
template<class T>
inline bool DLinkList<T>::empty()
{
	return len>0?0:1;
}
template<class T>
T DLinkList<T>::front()
{
	if (len == 0) {
		printf("Empty DLinkList!\n");
		exit(1);
	}
	return head->pos->value;
}
template<class T>
T DLinkList<T>::back()
{
	if (len == 0) {
		printf("Empty DLinkList!\n");
		exit(1);
	}
	Node *cur = head->pos;
	while (cur->pos)
	{
		cur = cur->pos;
	}
	return cur->value;
}
template<class T>
inline int DLinkList<T>::size()
{
	return len;
}
template<class T>
void DLinkList<T>::push_front(T value)
{
	Node *node = new Node(value);
	if (len == 0) {
		head->pos = node;
		node->pre = head;
	}else{
		node->pos = head->pos;
		node->pre = head;
		head->pos->pre = node;
		head->pos = node;
	}
	len += 1;
}

template<class T>
void DLinkList<T>::push_back(T value)
{
	Node *node = new Node(value);
	if (len == 0) {
		head->pos = node;
		node->pre = head;
	}
	else {
		Node *cur = head->pos;
		while (cur->pos)
		{
			cur = cur->pos;
		}
		cur->pos = node;
		node->pre = cur;
	}
	len += 1;
}

template<class T>
T DLinkList<T>::pop_front()
{
	if (len == 0) {
		printf("Empty DLinkList!\n");
		exit(1);
	}
	else if (len == 1) {
		Node *node = head->pos;
		head->pos = nullptr;
		len -= 1;
		return node->value;
	}
	else {
		Node *node = head->pos;
		head->pos = node->pos;
		node->pos->pre = head;
		len--;
		return node->value;
	}
}

template<class T>
T DLinkList<T>::pop_back()
{
	if (len == 0) {
		printf("Empty DLinkList!\n");
		exit(1);
	}
	else {
		Node *cur = head->pos;
		while (cur->pos)
		{
			cur = cur->pos;
		}
		cur->pre->pos = nullptr;
		len--;
		return cur->value;
	}
}

template<class T>
void DLinkList<T>::insert_by_pos(int pos, T value)
{
	if (len == 0) {
		printf("Empty DLinkList!");
		exit(1);
	}
	if (pos > len) {
		printf("pos[%d] > len[%d]", pos, len);
		exit(1);
	}
	Node *node = new Node(value);
	Node *cur = head->pos;
	while (--pos)
	{
		cur = cur->pos;
	}
	node->pre = cur->pre;
	node->pos = cur;
	cur->pre->pos = node;
	cur->pre = node;
	len++;
}

template<class T>
void DLinkList<T>::insert_by_val(T val, T value)
{
	if (len == 0) {
		printf("Empty DLinkList!");
		exit(1);
	}
	Node *cur = head->pos;
	while (cur->pos)
	{
		if (cur->value == val) {
			Node *node = new Node(value);
			node->pre = cur->pre;
			node->pos = cur;
			cur->pre->pos = node;
			cur->pre = node;
			len++;
			return;
		}
		cur = cur->pos;
	}
	printf("val not in DLinkList!");
	exit(1);
}

template<class T>
inline void DLinkList<T>::reverse()
{
	if (len == 0) {
		printf("Empty DLinkList!");
		exit(1);
	}
	else if (len == 1) {
		return;
	}
	Node *dump;
	Node *cur = head->pos;
	while (cur->pos)
	{
		dump = cur->pos;
		cur->pos = cur->pre;
		cur->pre = dump;
		cur = dump;
	}
	cur->pos = cur->pre;
	cur->pre = head;
	head->pos->pos = nullptr;
	head->pos = cur;
}

template<class T>
inline void DLinkList<T>::clear()
{
	delete head;
	head = new Node();
	len = 0;
}

#endif // !DLINKLIST_H  