#pragma once
#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <stdlib.h>
#include <iostream>
template<class T>
class SNode {
public:
	T value;
	SNode* next;
	SNode() : value(0), next(nullptr) {};
	SNode(T data) : value(data), next(nullptr) {};
	~SNode() { delete next; };
};
template<class T>
class Stack {
private:
	
	SNode<T> *head;
	int len;
public:
	char tag;
	Stack<T>();
	Stack<T>(char p);
	~Stack<T>();
	inline int size();
	inline bool empty();
	SNode<T>* top();
	void push(T value);
	T pop();
};
#endif

template<class T>
inline int Stack<T>::size()
{
	return len;
}

template<class T>
inline bool Stack<T>::empty()
{
	return len > 0 ? 0 : 1;
}

template<class T>
inline SNode<T>* Stack<T>::top()
{
	if ((len == 0)||(!head->next)) {
		printf("Empty Satck!\n");
		exit(1);
	}
	return head->next;
}

template<class T>
void Stack<T>::push(T value)
{
	SNode<T> *node = new SNode<T>(value);
	if ((len == 0)||(!head->next)) {
		head->next = node;
	}
	else {
		node->next = head->next;
		head->next = node;
	}
	len++;
}

template<class T>
T Stack<T>::pop()
{
	if (len == 0) {
		printf("Empty Stack!\n");
		exit(1);
	}
	SNode<T> *node = head->next;
	head->next = node->next;
	len--;
	return node->value;
}

template<class T>
Stack<T>::Stack()
{
	head = new SNode<T>();
	len = 0;
}

template<class T>
Stack<T>::Stack(char p)
{
	head = new SNode<T>();
	len = 0;
	tag = p;
}

template<class T>
Stack<T>::~Stack()
{
	delete head;
}
