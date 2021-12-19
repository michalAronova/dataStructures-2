#ifndef DOUBLEHEAP_H
	#define DOUBLEHEAP_H

#include "ItemType.h"
const int MAX_SIZE = 100;

class DoubleHeap {
	
public:
	DoubleHeap();
	DoubleHeap(const DoubleHeap&);
	~DoubleHeap();

	//static methods
	static int Parent(int index) { return (index - 1) / 2; };
	static int Left(int index) { return 2 * index + 1; };
	static int Right(int index) { return 2 * index + 2; };

	int insert(int, string);
	
	//max
	void fixMaxHeap(int);
	ItemType max() const;
	ItemType deleteMax();

	//min
	void fixMinHeap(int);
	ItemType min() const;
	ItemType deleteMin();

private:
	ItemType _maxHeap[MAX_SIZE];
	ItemType _minHeap[MAX_SIZE];
	int _heapSize;
};

#endif
