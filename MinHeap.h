#ifndef MINHEAP_H
#define MINHEAP_H

#include "ItemType.h"

class MinHeap {
public:

private:
	ItemType** heap;
	int logSize;
	int physSize;
};

#endif