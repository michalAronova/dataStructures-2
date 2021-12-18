#ifndef MAXHEAP_H
	#define MAXHEAP_H

#include "HeapBase.h"

class MaxHeap : public HeapBase {

public:
	MaxHeap() {}
	virtual ~MaxHeap();

	virtual void insert(ItemType*);
	virtual void fixHeap(int);

	ItemType& max() const;
	ItemType deleteMax();
};

#endif