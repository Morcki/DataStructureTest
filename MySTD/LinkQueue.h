#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <stdlib.h>
#include <iostream>
template<class T>
class QNode {
public:
	T value;
	QNode *next;
	QNode() :value(0), next(nullptr) {};
	QNode(T data) :value(data), next(nullptr) {};
	~QNode() { delete next; };
};
template<class T>
class Queue { // linked queue
private:
	class Head {
	public:
		QNode<T> *left;
		QNode<T> *right;
		Head() :left(nullptr), right(nullptr) {};
		~Head() { delete left; delete right; };
	};
	int len;
	Head *head;
public:
	Queue();
	~Queue();
	inline int size();
	inline bool empty();
	void enqueue(T value);
	T dequeue();
	QNode<T>* front();
	QNode<T>* rear();
	T first();
	T last();
	void clear();
};
#endif

template<class T>
inline Queue<T>::Queue()
{
	len = 0;
	head = new Head();
}

template<class T>
inline Queue<T>::~Queue()
{
	delete head;
}

template<class T>
inline int Queue<T>::size()
{
	return len;
}

template<class T>
inline bool Queue<T>::empty()
{
	return len > 0 ? 0 : 1;
}

template<class T>
void Queue<T>::enqueue(T value)
{
	QNode<T> *node = new QNode<T>(value);
	if ((len == 0)|| ((head->left == nullptr) && (head->right == nullptr))) {
		head->left = head->right = node;
	}
	else { 
		head->right->next = node;
		head->right = node;
	}
	len++;
}
template<class T>
T Queue<T>::dequeue() {
	if ((len == 0) || ((head->left == nullptr) && (head->right == nullptr))) {
		printf("Empty Queue!\n");
		exit(1);
	}
	if (head->left == head->right) {
		QNode<T> *node = head->left;
		head->left = head->right = nullptr;
		len--;
		return node->value;
	}
	else {
		QNode<T> *node = head->left;
		head->left = node->next;
		len--;
		return node->value;
	}
	
}
template<class T>
inline QNode<T>* Queue<T>::front()
{
	return head->left;
}
template<class T>
inline QNode<T>* Queue<T>::rear()
{
	return head->right;
}
template<class T>
inline T Queue<T>::first()
{
	if ((len == 0) || ((head->left == nullptr) && (head->right == nullptr))) {
		printf("Empty Queue!");
		exit(1);
	}
	return head->left->value;
}
template<class T>
inline T Queue<T>::last()
{
	if ((len == 0) || ((head->left == nullptr) && (head->right == nullptr))) {
		printf("Empty Queue!");
		exit(1);
	}
	return head->right->value;
}
template<class T>
void Queue<T>::clear() {
	delete head;
	head = new Head();
	len = 0;
}