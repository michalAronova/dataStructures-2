#ifndef MINHEAP_H
#define MINHEAP_H

#include "HeapBase.h"

class MinHeap : public HeapBase {

public:
	MinHeap() {}
	virtual ~MinHeap();

	virtual void insert(ItemType*);
	virtual void fixHeap(int);

	ItemType& min() const;
	ItemType deleteMin();
};

#endif