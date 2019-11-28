#pragma once
#ifndef LINKBINTREE_H
#define LINKBINTREE_H
#include <stdlib.h>
#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
#include <cmath>
enum Tag { left, right };
template<class T>
class TNode {
public:
	T value;
	TNode *left;
	TNode *right;
	TNode() :value(0), left(nullptr), right(nullptr) {};
	TNode(T data) :value(data), left(nullptr), right(nullptr) {};
	~TNode() { delete left; delete right; };
};
template<class T>
class LinkBinTree {
public:
	LinkBinTree();
	~LinkBinTree();
	void creat_cbt(const T *p,int len); // creat complete binary tree
	void creat_sbt(const T *p, int len); // creat search binary tree
	int treeheight();
	bool insert_node(T value); // type must be search binary tree
	TNode<T>* find(T value); // type must be search binary tree
	bool delete_node(T value); // type must be search binary tree
	Queue<T>* preorder();
	Queue<T>* inorder();
	Queue<T>* postorder();
	Queue<T>* bf_traversal(); // breadth-first traversal
	Queue<T>* df_traversal(); // deepth-first traversal
private:
	
	class TagNode{
	public:
		TNode<T> *node;
		Tag tag;
		TagNode() :node(nullptr) {};
		TagNode(TNode<T>* p,Tag t) :node(p),tag(t) {};
		~TagNode() { delete node; };
	};
	int getTreeHeight();
	TNode<T> *root;
	int size;
	char type[10]; // CBT,SBT(default)
};
#endif // !LINKBINTREE_H

template<class T>
LinkBinTree<T>::LinkBinTree()
{
	root = nullptr;
	size = 0;
}

template<class T>
inline LinkBinTree<T>::~LinkBinTree()
{
	delete root;
}

template<class T>
void LinkBinTree<T>::creat_cbt(const T *p, int len)
{
	if (len <= 0) {
		printf("Invalid len[%d]", len);
		exit(1);
	}
	strcpy(type, "CBT"); // complete binary tree
	Queue<TNode<T>*> q;
	TNode<T> *cur;
	root = new TNode<T>(*p++);
	q.enqueue(root);
	size++;
	while (!q.empty())
	{
		cur = q.dequeue();
		if (size < len) {
			cur->left = new TNode<T>(*p++);
			size++;
		}
		else {
			break;
		}
		if (size < len) {
			cur->right = new TNode<T>(*p++);
			size++;
		}
		else {
			break;
		}
		q.enqueue(cur->left);
		q.enqueue(cur->right);
	}
}

template<class T>
void LinkBinTree<T>::creat_sbt(const T *p, int len)
{
	if (len <= 0) {
		printf("Invalid len[%d]", len);
		exit(1);
	}
	strcpy_s(type,"SBT"); // search binary tree
	while (len--)
	{
		insert_node(*p++);
	}
}

template<class T>
int LinkBinTree<T>::treeheight()
{
	if (!strcmp(type, "CBT")) {
		return floor(log(size) / log(2)) + 1;
	}
	else if (!strcmp(type, "SBT")) {
		return getTreeHeight();
	}
	else {
		printf("Invalid type[%s]!",type);
		exit(1);
	}
}
template<class T>
int LinkBinTree<T>::getTreeHeight() { // using breadth-first traversal
	int height = 0;
	bool ldeep = 0;
	if (!root) {
		return height;
	}
	Queue<TNode<T>*> q;
	q.enqueue(root);
	TNode<T>* cur;
	while (!q.empty())
	{
		height++;
		for (int i = q.size(); i > 0; i--) {
			cur = q.dequeue();
			if (cur->left) {
				q.enqueue(cur->left);
			}
			if (cur->right) {
				q.enqueue(cur->right);
			}
		}
	}
	return height;
}

template<class T>
bool LinkBinTree<T>::insert_node(T value)
{
	TNode<T> *node = new TNode<T>(value);
	if (!root){
		root = node;
		size++;
		return true;
	}
	TNode<T> *cur = root;
	TNode<T> *parent = new TNode<T>();
	while (cur)
	{
		if (value < cur->value) {
			parent = cur;
			cur = cur->left;
		}
		else if (value > cur->value)
		{
			parent = cur;
			cur = cur->right;
		}
		else {
			return false;
		}
	}
	if (value < parent->value) {
		parent->left = node;
	}
	else {
		parent->right = node;
	}
	size++;
	return true;
}

template<class T>
TNode<T>* LinkBinTree<T>::find(T value)
{
	TNode<T> *cur = root;
	while (cur)
	{
		if (value < cur->value) {
			cur = cur->left;
		}
		else if (value > cur->value) {
			cur = cur->right;
		}
		else {
			return cur;
		}
	}
	return cur;
}

template<class T>
bool LinkBinTree<T>::delete_node(T value)
{
	TNode<T> *node = new TNode<T>(value);
	TNode<T> *cur = root;
	TNode<T> *parent = root;
	while (cur)
	{
		if (value < cur->value) {
			parent = cur;
			cur = cur->left;
		}
		else if (value  > cur->value) {
			parent = cur;
			cur = cur->right;
		}
		else
		{
			if (cur == root) { // delete root
				root = nullptr;
			}
			else if (!cur->left) { // left child is empty
				if (parent->left == cur) { // parent->left == cur
					parent->left = cur->right;
				}
				else // parent->right == cur
				{
					parent->right = cur->right;
				}
			}
			else if (!cur->right) { // right child is empty
				if (parent->left == cur) { // parent->left == cur
					parent->left = cur->left;
				}
				else // parent->right == cur
				{
					parent->right = cur->left;
				}
			}
			else { // left & right child both exist
				TNode<T> *del = cur->right;
				parent = cur;
				while (del->left) // search for min-value node of right-child tree
				{
					parent = del;
					del = del->left;
				}
				cur->value = del->value; // replace delete-node with min-value node 
				if (parent == cur) {
					parent->right = del->right;
				}
				else {
					parent->left = del->right; // delete min-value node 
				}
			}
			size--;
			return true;
		}
	}
	return false;
}

template<class T>
Queue<T>* LinkBinTree<T>::preorder()
{
	Queue<T> *t = new Queue<T>();
	if (!root) {
		return t;
	}
	Stack<TNode<T>*> s;
	s.push(root);
	TNode<T> *cur = root;
	while (!s.empty()) {
		t->enqueue(cur->value);
		if (cur->right) {
			s.push(cur->right);
		}
		if (cur->left) {
			cur = cur->left;
		}
		else {
			cur = s.pop();
		}
	}
	return t;
}

template<class T>
Queue<T>* LinkBinTree<T>::inorder()
{
	Queue<T> *t = new Queue<T>();
	if (!root) {
		return t;
	}
	Stack<TNode<T>*> s;
	TNode<T> *cur = root;
	while (!s.empty() || cur)
	{
		if (cur) {
			s.push(cur);
			cur = cur->left;
		}
		else {
			cur = s.pop();
			t->enqueue(cur->value);
			cur = cur->right;
		}
	}
	return t;
}

template<class T>
Queue<T>* LinkBinTree<T>::postorder()
{
	Queue<T> *t = new Queue<T>();
	if (!root) {
		return t;
	}
	TagNode *dump;
	Stack<TagNode*> s;
	TNode<T> *cur = root;
	while (!s.empty() || cur)
	{
		while (cur)
		{
			TagNode *tagcur = new TagNode(cur, Tag::left);
			s.push(tagcur);
			cur = cur->left;
		}
		dump = s.pop();
		if (dump->tag == Tag::left) {
			dump->tag = Tag::right;
			s.push(dump);
			cur = dump->node->right;
		}
		else {
			t->enqueue(dump->node->value);
			cur = nullptr;
		}

	}
	return t;
}

template<class T>
Queue<T>* LinkBinTree<T>::bf_traversal()
{
	Queue<T> *t = new Queue<T>();
	Queue<TNode<T>*> q;
	TNode<T>* cur = root;
	q.enqueue(cur);
	while (!q.empty())
	{
		cur = q.dequeue();
		t->enqueue(cur->value);
		if (cur->left) {
			q.enqueue(cur->left);
		}
		if (cur->right) {
			q.enqueue(cur->right);
		}
	}
	return t;
}

template<class T>
Queue<T>* LinkBinTree<T>::df_traversal()
{
	Queue<T> *t = new Queue<T>();
	Stack<TNode<T>*> s;
	TNode<T> *cur = root;
	s.push(cur);
	while (!s.empty())
	{
		cur = s.pop();
		t->enqueue(cur->value);
		if (cur->right) {//late
			s.push(cur->right);
		}
		if (cur->left) {//first
			s.push(cur->left);
		}
	}
	return t;
}
