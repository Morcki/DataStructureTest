#pragma once
#ifndef CLIST_H
#define CLIST_H
#include <stdlib.h>
#include <iostream>
template<class T>
class CList { // circle linked-list
private:
	class Node
	{
	public:
		T value;
		Node* left;
		Node* right;
		Node() : value(0), left(nullptr), right(nullptr) {};
		Node(T data) : value(data), left(nullptr), right(nullptr) {};
		~Node() { delete left; delete right; };
	};
	Node *head;
	int len;
public:
	CList<T>();
	~CList<T>();
	inline bool empty(); // Returns whether the list is empty(1) or not(0)
	inline int size(); // Returns the number of elements in the list
	T front(); // Returns the value of the first element in the list
	T back(); // Returns the value of the last element in the list 
	void push_front(T value); // Adds a new element ¡®value¡¯ at the beginning of the list 
	void push_back(T value); // Adds a new element ¡®value¡¯ at the end of the list
	T pop_front();  // Removes the first element of the list, and reduces size of the list by 1
	T pop_back(); // Removes the last element of the list, and reduces size of the list by 1
	void insert_by_pos(int pos, T value); // Inserts new elements in the list before the element at a specified position
	void insert_by_val(T val, T value); // Inserts new elements in the list before the element of a specified value
	void reverse(); // Reverses the list
	void clear(); // remove all the elements of the list container, thus making it size 0
};

#endif

template<class T>
CList<T>::CList()
{
	head = new Node();
	len = 0;
}

template<class T>
CList<T>::~CList()
{
	delete head;
}

template<class T>
inline bool CList<T>::empty()
{
	return len>0?0:1;
}

template<class T>
inline int CList<T>::size()
{
	return len;
}

template<class T>
inline T CList<T>::front()
{
	if (len == 0) {
		printf("Empty CList!\n");
		exit(1);
	}
	return head->left->value;
}

template<class T>
inline T CList<T>::back()
{
	if (len == 0) {
		printf("Empty CList!\n");
		exit(1);
	}
	return head->right->value;
}

template<class T>
void CList<T>::push_front(T value)
{
	Node *node = new Node(value);
	if (len == 0) {
		node->left = node->right = head;
		head->left = head->right = node;
	}
	else {
		node->right = head->left;
		node->right->left = node;
		head->left = node;
	}
	len++;
}

template<class T>
void CList<T>::push_back(T value)
{
	Node *node = new Node(value);
	if (len == 0) {
		node->left = node->right = head;
		head->left = head->right = node;
	}
	else {
		node->left = head->right;
		node->left->right = node;
		head->right = node;
	}
	len++;
}

template<class T>
T CList<T>::pop_front()
{
	if (len == 0) {
		printf("Empty CList!\n");
		exit(1);
	}
	else if (len == 1) {
		Node *node = head->left;
		head->left = head->right = nullptr;
		len--;
		return node->value;
	}
	else {
		Node *node = head->left;
		head->left = node->right;
		head->left->left = head;
		len--;
		return node->value;
	}
	
}

template<class T>
T CList<T>::pop_back()
{
	if (len == 0) {
		printf("Empty CList!\n");
		exit(1);
	}
	else if (len == 1) {
		Node *node = head->right;
		head->left = head->right = nullptr;
		len--;
		return node->value;
	}
	else {
		Node *node = head->right;
		head->right = node->left;
		head->right->right = head;
		len--;
		return node->value;
	}
}

template<class T>
void CList<T>::insert_by_pos(int pos, T value)
{
	if (pos > len) {
		printf("pos[%d] > len[%d]", pos, len);
		exit(1);
	}
	if (pos == 1) {
		push_front(value);
		return;
	}
	else {
		Node *node = new Node(value);
		Node *cur = head->left;
		while (--pos)
		{
			cur = cur->right;
		}
		node->left = cur->left;
		node->right = cur;
		cur->left->right = node;
		cur->left = node;
		len++;
	}
	
}

template<class T>
void CList<T>::insert_by_val(T val, T value)
{
	if (len == 0) {
		printf("Empty CList!\n");
		exit(1);
	}
	if (head->left->value == val) {
		insert_by_pos(1,value);
		return;
	}
	Node *node = new Node(value);
	Node *cur = head->left;
	while (!(cur==head))
	{
		if (cur->value == val) {
			node->left = cur->left;
			node->right = cur;
			cur->left->right = node;
			cur->left = node;
			len++;
			return;
		}
		cur = cur->right;
	}
	printf("val not in CList!\n");
	exit(1);

}

template<class T>
void CList<T>::reverse()
{
	
}
