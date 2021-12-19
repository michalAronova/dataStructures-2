#ifndef DOUBLEHEAP_H
	#define DOUBLEHEAP_H

#include "ItemType.h"
const int MAX_SIZE = 100;


class DoubleHeap {
public:
	enum heapType { MAX, MIN };

	DoubleHeap() :_heapSize(0) {}

	//static methods
	static int Parent(int index) { return (index - 1) / 2; };
	static int Left(int index) { return 2 * index + 1; };
	static int Right(int index) { return 2 * index + 2; };

	void	 insert(ItemType);
	void	 insert(int, string);
	void	 swap(ItemType& a, ItemType& b);
	ItemType deleteHead(heapType);

	//max
	ItemType  max() const;
	ItemType  deleteMaxByIdx(int index = 0, int fixed = 0);
	void	  fixMaxHeap(int);

	//min
	ItemType  min() const;
	ItemType  deleteMinByIdx(int index = 0, int fixed = 0);
	void	  fixMinHeap(int);
	
	friend class DataStructure;

private:
	ItemType _maxHeap[MAX_SIZE];
	ItemType _minHeap[MAX_SIZE];
	int _heapSize;
};

#endif
