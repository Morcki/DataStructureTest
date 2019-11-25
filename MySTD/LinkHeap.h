#pragma once
#ifndef LINKHEAP_H
#define LINKHEAP_H
template<class T,typename Tw>
class HNode {
	T value;
	Tw weight;
	HNode<T,Tw>* left;
	HNode<T,Tw>* right;
	HNode() :value(0),weight(0) left(0), right(0) {};
	HNode(T data.Tw w) :value(data), weight(w), left(0), right(0) {};
	~HNode() { delete left; delete right; };
};
template<class T,typename Tw>
class MaxHeap // not completed yet
{
public:
	MaxHeap();
	~MaxHeap();
	bool empty();
	void insert(T value,Tw w);
	HNode<T,Tw>* Max();
	HNode<T,Tw>* delMax();
private:
	HNode<T,Tw> *root;
	int size;
	void swim(HNode<T,Tw> *p);
	void sink(HNode<T, Tw> *p);
};
template<class T, typename Tw>
MaxHeap<T,Tw>::MaxHeap()
{
	root = 0;
	size = 0;
}
template<class T, typename Tw>
MaxHeap<T,Tw>::~MaxHeap()
{
	delete root;
}
template<class T, typename Tw>
inline bool MaxHeap<T, Tw>::empty()
{
	return size > 0 ? 0 : 1;
}
template<class T, typename Tw>
void MaxHeap<T,Tw>::insert(T value,Tw w)
{
	HNode<T,Tw>* node = new HNode<T,Tw>(value, w);
	if (!root) {
		root = node;
		return;
	}

}
template<class T, typename Tw>
void MaxHeap<T, Tw>::swim(HNode<T, Tw> *p)
{

}
#endif // !LINKHEAP_H
