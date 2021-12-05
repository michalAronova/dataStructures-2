#ifndef HEAP_H
	#define HEAP_H

#include "MaxHeap.h"
#include "MinHeap.h"

class Heap {
	Heap();
	Heap(const Heap&);
	~Heap();

	void insert();

private:
	MaxHeap maxHeap;
	MinHeap minHeap;
	int logSize;
	int physSize;
};

#endif
