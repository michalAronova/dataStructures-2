#ifndef MAXHEAP_H
	#define MAXHEAP_H

#include "ItemType.h"

class MaxHeap {
public:
	MaxHeap() : _heap(nullptr), _logSize(0), _physSize(0) {};
	MaxHeap(const MaxHeap&);
	~MaxHeap();

	void insert(ItemType*);
	void reAlloc(ItemType* heap[], int newSize);
	ItemType& Max();
	ItemType DeleteMax();
	void FixHeap(int);

	int Parent(int index) { return (index - 1) / 2; };
	int Left(int index) { return 2 * index + 1; };
	int Right(int index) { return 2 * index + 2; };

private:
	ItemType** _heap;
	int _logSize;
	int _physSize;
};

#endif