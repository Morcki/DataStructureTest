#pragma once
#ifndef ARRHEAP_H
#define ARRHEAP_H
#include <vector>
#include "assert.h"
using namespace std;
template<class T>
struct Less
{
	bool operator () (const T& left, const T& right) const {
		return left < right;
	}
};
template<class T>
struct Greater
{
	bool operator () (const T& left, const T& right) const {
		return left > right;
	}
};

template<class T,class cmp=Less<T>>
class ArrHeap { // Min Heap(default)
public:
	ArrHeap() {};
	ArrHeap(T *p, int n);
	~ArrHeap();
	int size();
	bool empty();
	void push(T value);
	void pop();
	T top();

private:
	vector<T> _a;
	void siftup(int cur);
	void siftdown();

};


#endif // !ARRHEAP_H

template<class T, class cmp>
ArrHeap<T, cmp>::ArrHeap(T *p, int n)
{
	while (n--)
	{
		push(*p++);
	}
}

template<class T, class cmp>
ArrHeap<T, cmp>::~ArrHeap()
{
	vector<T>().swap(_a); // 不能用clear，clear无法清除vector所占用内存。
}

template<class T, class cmp>
inline int ArrHeap<T, cmp>::size()
{
	return _a.size();
}

template<class T, class cmp>
inline bool ArrHeap<T, cmp>::empty()
{
	return _a.empty();
}

template<class T, class cmp>
void ArrHeap<T, cmp>::push(T value)
{
	_a.push_back(value);
	siftup(_a.size() - 1);
}

template<class T, class cmp>
void ArrHeap<T, cmp>::pop()
{
	assert(!_a.empty());
	swap(_a[0],_a[_a.size()-1]);
	_a.pop_back();
	siftdown();
}

template<class T, class cmp>
T ArrHeap<T, cmp>::top()
{
	assert(!_a.empty());
	return _a[0];
}

template<class T, class cmp>
void ArrHeap<T, cmp>::siftup(int cur)
{
	cmp c;
	int parent = (cur - 1) >> 1;
	while (parent>=0)
	{
		if (c(_a[cur], _a[parent])) {
			swap(_a[cur], _a[parent]);
			cur = parent;
			parent = (cur - 1) >> 1;
		}
		else {
			break;
		}

	}
}

template<class T, class cmp>
void ArrHeap<T, cmp>::siftdown()
{
	// siftdown the first value in vector(_a) [root node]
	cmp c;
	int parent = 0; // root = 0
	int child = parent * 2 + 1; // left child
	while (child < _a.size())
	{
		if ((child+1)<_a.size() && c(_a[child + 1], _a[child])) {
			child++;
		}
		if (c(_a[child], _a[parent])) {
			swap(_a[child], _a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
