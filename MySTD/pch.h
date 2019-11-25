// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H
#include <cstring>
#include <iostream>
#include "LinkStack.h"
#include "LinkDeque.h"
#include "LinkBinTree.h"
#include "HuffmanTree.h"
// TODO: add headers that you want to pre-compile here
class Hannota {
public:
	Hannota(int n);
	~Hannota();
	void play();

private:
	int num;
	Stack<int> *A;
	Stack<int> *B;
	Stack<int> *C;
	void move(int n,Stack<int> *base,Stack<int> *surport,Stack<int> *target);
};
class Test {
public:
	void hannotaTest(int n);
	void linkdequeTest();
	void linkbintreeTest();
	void huffmantreeTest();
};


#endif //PCH_H
