#ifndef _DATASTRUCTURE_H
	#define _DATASTRUCTURE_H

#include "DoubleHeap.h"

class DataStructure {

public:
	DataStructure() : _size(0) {}

	ItemType Max() const;
	ItemType DeleteMax();
	ItemType Min() const;
	ItemType DeleteMin();
	static DataStructure CreateEmpty();
	void Insert(int, string);
	ItemType Median();
	void balance();

private:
	int		   _size;
	DoubleHeap _big;
	DoubleHeap _small;

};
#endif
