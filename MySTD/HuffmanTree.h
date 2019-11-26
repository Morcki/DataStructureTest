#pragma once
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <queue>
using namespace std;
template<class T,typename Tw>
class HMnode
{
public:
	T value;
	Tw weight;
	HMnode<T, Tw> *left;
	HMnode<T, Tw> *right;
	HMnode() :value(0), weight(0), left(0), right(0) {};
	HMnode(T data,Tw w) :value(data), weight(w), left(0), right(0) {};
	friend HMnode<T, Tw> operator + (const HMnode<T, Tw> left, const HMnode<T, Tw> right) {
		HMnode<T, Tw> *sumnode = new HMnode<T, Tw>(0, left.weight + right.weight);
		return *sumnode;
	}
	friend bool operator < (const HMnode<T,Tw> left,const HMnode<T, Tw> right) {
		return left.weight < right.weight;
	}
	friend bool operator > (const HMnode<T, Tw> left, const HMnode<T, Tw> right) {
		return left.weight > right.weight;
	}
};

template<class T,typename Tw=int>
class LinkHM
{
public:
	HMnode<T, Tw>* root;
	LinkHM();
	~LinkHM();
	void creat(T * value, Tw * w, int n);
	Tw WPL();
private:
	int size;
	int height;
	void select(priority_queue<HMnode<T, Tw>, vector<HMnode<T, Tw>>, greater<HMnode<T, Tw>>>* pri_q);
};
template<class T, typename Tw>
LinkHM<T, Tw>::LinkHM()
{
	root = new HMnode<T,Tw>();
	size = 0;
	height = 0;
}
template<class T, typename Tw>
LinkHM<T, Tw>::~LinkHM()
{
	delete root;
}

template<class T, typename Tw>
void LinkHM<T, Tw>::creat(T * value, Tw * w, int n)
{
	if (n < 2) {
		printf("forest size[%d] < 2!", n);
		exit(1);
	}
	// 优先级队列不能传入HMnode<T,Tw>*指针，否则比较优先级会以指针大小进行比较，不会重载运算符
	priority_queue<HMnode<T, Tw>, vector<HMnode<T, Tw>>, greater<HMnode<T, Tw>>> pri_q;
	while (n--)
	{
		HMnode<T, Tw>* node = new HMnode<T,Tw>(*value++,*w++);
		pri_q.push(*node);
	}
	while (pri_q.size()>1)
	{
		select(&pri_q);
	}
	*root = pri_q.top();
	pri_q.pop();
	size = n;
	height = n - 1;
}

template<class T, typename Tw>
Tw LinkHM<T, Tw>::WPL()
{
	int h = -1;
	Tw wpl = 0;
	if (!root) {
		return wpl;
	}
	queue<HMnode<T, Tw>*> q;
	q.push(root);
	HMnode<T, Tw>* cur;
	while (!q.empty())
	{
		h++;
		for (int i = q.size(); i > 0; i--) {
			cur = q.front();
			q.pop();
			if (cur->left)
			{
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
			if ((!cur->left) && (!cur->right)) {
				wpl += cur->weight * h;
			}
		}
	}
	return wpl;
}

template<class T,typename Tw>
void LinkHM<T, Tw>::select(priority_queue<HMnode<T, Tw>, vector<HMnode<T, Tw>>, greater<HMnode<T, Tw>>> *pri_q)
{
	if (pri_q->size() < 2) {
		printf("forest size[%d] < 2!", pri_q->size());
		exit(1);
	}
	HMnode<T, Tw> *m1 = new HMnode<T, Tw>();
	HMnode<T, Tw> *m2 = new HMnode<T, Tw>();
	*m1 = pri_q->top();
	pri_q->pop();
	*m2 = pri_q->top();
	pri_q->pop();
	HMnode<T, Tw> s = *m1 + *m2;
	s.left = m1;
	s.right = m2;
	pri_q->push(s);
}

#endif // !HUFFMANTREE_H
