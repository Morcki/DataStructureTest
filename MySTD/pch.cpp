// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"

// In general, ignore this file, but keep it around if you are using pre-compiled headers.

Hannota::Hannota(int n)
{
	num = n;
	int i = n;
	A = new Stack<int>('A'); // base
	B = new Stack<int>('B'); // surport
	C = new Stack<int>('C'); // target
	while (i)
	{
		A->push(i--);
	}
}

Hannota::~Hannota()
{
	delete A;
	delete B;
	delete C;
}

void Hannota::play()
{
	move(num,A, B, C);
}

void Hannota::move(int n,Stack<int> *base, Stack<int> *surport, Stack<int> *target)
{
	if ((n==0)||(base->empty())) {
		return;
	}
	move(n-1,base, target, surport);
	int i = base->pop();
	printf("%c->%c : %d\n",base->tag,target->tag,i);
	target->push(i);
	move(n-1,surport, base, target);
}

void Test::hannotaTest(int n)
{
	printf("Hannota Test Workplace:\n");
	printf("=======================\n");
	printf("Plates Numbers : %d\n",n);
	Hannota han = Hannota(n);
	han.play();
	printf("=======================\n");
}

void Test::linkdequeTest()
{
	/*
	LinkDeque Test:

	function:
	push_front
	push_back
	front
	back
	pop_front
	pop_back
	*/
	printf("Linked-deque Test Workplack:\n");
	printf("============================\n");
	double a[] = { 10.5,11.7,24.3,8.8,-5,14.3 };
	LinkDeque<double> d;
	for (int i = 0; i < 6; i++) {
		if (i % 2) {
			d.push_front(a[i]);
		}
		else
		{
			d.push_back(a[i]);
		}
	}
	printf("Deque Size             : %d\n", d.size());
	printf("Deque front node value : %f\n", d.front()->value);
	printf("Deque back node value  : %f\n", d.back()->value);
	printf("Deque normal order     :\n");
	while (!d.empty())
	{
		printf("%.1f ", d.pop_front());
	}
	for (int i = 0; i < 6; i++) {
		if (i % 2) {
			d.push_front(a[i]);
		}
		else
		{
			d.push_back(a[i]);
		}
	}
	printf("\nDeque reverse order     :\n");
	while (!d.empty())
	{
		printf("%.1f ", d.pop_back());
	}
	printf("\n============================\n");
}

void Test::linkbintreeTest()
{
	/*
	LinkBinTree Test:

	function:
	insert_node
	delete_node
	preorder
	inorder
	postorder
	bf_traversal
	df_traversal

	Test Tree: (Binary Search Tree)         _
						5                   |
					/       \               |
				   3         7              |
				/     \    /   \           h=5
			   1       4  6     8           |
			 /   \                \         |
			0     2                9        |
									\       |
									10      -
	*/
	printf("Linked Binary Search Tree Test Workplack:\n");
	printf("=========================================\n");
	LinkBinTree<int> b;
	Queue<int> *q;
	const int p[] = {5,3,7,1,4,6,8,0,2,9,10};
	b.creat_sbt(p, 11);
	//b.delete_node(7);
	printf("Tree Height : %d\n", b.treeheight());
	q = b.preorder();
	printf("preorder:\n");
	while (!q->empty())
	{
		printf("%d ", q->dequeue());
	}
	q = b.inorder();
	printf("\ninorder:\n");
	while (!q->empty())
	{
		printf("%d ", q->dequeue());
	}
	q = b.postorder();
	printf("\npostorder:\n");
	while (!q->empty())
	{
		printf("%d ", q->dequeue());
	}
	q = b.bf_traversal();
	printf("\nBreadth-first traversal:\n");
	while (!q->empty())
	{
		printf("%d ", q->dequeue());
	}
	q = b.df_traversal();
	printf("\nDepth-first traversal:\n");
	while (!q->empty())
	{
		printf("%d ", q->dequeue());
	}
	printf("\n=========================================\n");
}

void Test::huffmantreeTest()
{
	/*
	HuffmanTree Test:
			 forest
		   1 2 2 3 6
		   A B C D E
			 HMtree
			   14
			 /    \
			6      8
			E    /   \
				3     5
			   / \   / \
			  1   2 2   3
			  A   B C   D
	*/
	printf("Huffman Tree Test Workplace:\n");
	printf("============================\n");
	int v[5] = { 2,3,6,1,2 };
	char tag[] = "ABCDE";
	LinkHM<char>* hm = new LinkHM<char>();
	hm->creat(tag, v, 5);
	printf("WPL : %d\n", hm->WPL());
	printf("============================\n");
}

void Test::heapTest()
{
	printf("Heap Test Workplace:\n");
	printf("====================\n");
	int a[] = { 10,1,13,12,16,18,15,17,14,19 };
	ArrHeap<int> ah(a,10);
	ah.push(15);
	printf("Heap Size : %d\n", ah.size());
	printf("Heap Top  : %d\n", ah.top());
	printf("Heap Content : \n");
	while (!ah.empty())
	{
		printf("%d ", ah.top());
		ah.pop();
	}
	printf("\n====================\n");
}
