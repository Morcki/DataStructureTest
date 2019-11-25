#pragma once
#ifndef LINKDEQUE_H
#define LINKDEQUE_H
#include <stdlib.h>
#include <iostream>
template<class T>
class DNode
{
public:
	T value;
	DNode<T> *left;
	DNode<T> *right;
	DNode() :value(0), left(0), right(0) {};
	DNode(T data) :value(data), left(0), right(0) {};
};
template<class T>
class LinkDeque { //  double linked-queue
private:
	
	DNode<T> *first;
	DNode<T> *last;
	int len;
public:
	LinkDeque();
	~LinkDeque();
	inline int size();
	inline bool empty();
	void push_front(T value);
	void push_back(T value);
	T pop_front();
	T pop_back();
	DNode<T>* front();
	DNode<T>* back();
};
#endif // !LINKDEQUE_H

template<class T>
inline LinkDeque<T>::LinkDeque()
{
	
	first = last = new DNode<T>();
	len = 0;
}

template<class T>
inline LinkDeque<T>::~LinkDeque()
{
	if (first == last) {//empty
		delete first;
	}
	else {
		delete first;
		delete last;
	}
	
}

template<class T>
inline int LinkDeque<T>::size()
{
	return len;
}

template<class T>
inline bool LinkDeque<T>::empty()
{
	return len > 0 ? 0 : 1;
}

template<class T>
void LinkDeque<T>::push_front(T value)
{
	DNode<T> *node = new DNode<T>(value);
	if (first == last) {//empty
		node->left = first;
		first->right = node;
		last = node;
	}
	else {
		node->left = first;
		node->right = first->right;
		first->right->left = node;
		first->right = node;
	}
	len++;
}

template<class T>
void LinkDeque<T>::push_back(T value)
{
	DNode<T> *node = new DNode<T>(value);
	if (first == last) {//empty
		node->left = first;
		first->right = node;
		last = node;
	}
	else {
		node->left = last;
		last->right = node;
		last = node;
	}
	len++;
}

template<class T>
T LinkDeque<T>::pop_front()
{
	if (first == last) {//empty
		printf("Empty Deque!\n");
		exit(1);
	}
	else if (first->right == last) {
		DNode<T> *node = first->right;
		first->right = nullptr;
		last = first;
		len--;
		return node->value;
	}
	else {
		DNode<T> *node = first->right;
		first->right = node->right;
		len--;
		return node->value;
	}
	
}

template<class T>
T LinkDeque<T>::pop_back()
{
	if (first == last) {//empty
		printf("Empty Deque!\n");
		exit(1);
	}
	else {
		DNode<T> *node = last;
		last = node->left;
		last->right = nullptr;
		len--;
		return node->value;
	}
	
}

template<class T>
DNode<T>* LinkDeque<T>::front()
{
	if (first == last) {
		printf("Empty Deque!\n");
		exit(1);
	}
	else {
		return first->right;
	}
	
}

template<class T>
DNode<T>* LinkDeque<T>::back()
{
	if (first == last) {
		printf("Empty Deque!\n");
		exit(1);
	}
	else {
		return last;
	}
}
