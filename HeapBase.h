#ifndef HEAPBASE_H
#define HEAPBASE_H

#include "ItemType.h"

const int MAX_SIZE = 100;

class HeapBase {
protected:
	HeapBase() :logSize(0) {}
	
	//virtual methods
	virtual void insert(int priority, string data) = 0;
	virtual void fixHeap(int index) = 0;

	//static methods
	static int Parent(int index) { return (index - 1) / 2; };
	static int Left(int index) { return 2 * index + 1; };
	static int Right(int index) { return 2 * index + 2; };

	//d'tor
	virtual ~HeapBase() {}

	//data members
	ItemType items[MAX_SIZE];
	int logSize;
};



#endif
