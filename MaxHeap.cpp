#include "MaxHeap.h"

/*
class MaxHeap {
public:

private:
	ItemType** heap;
	int logSize;
	int physSize;
};
*/

/*MaxHeap::MaxHeap()
{

}
*/
MaxHeap::MaxHeap(const MaxHeap& other)
{
	_logSize = other._logSize;
	_physSize = _logSize;

	if (_logSize > 0)
	{
		_heap = new ItemType * [_physSize];

		for (int i=0;i<_logSize;i++)
		{
			_heap[i] = new ItemType(*other._heap[i]);
		}
	}
}

MaxHeap::~MaxHeap()
{
	for (int i = 0; i < _logSize; ++i)
	{
		delete _heap[i];
	}
	delete[] _heap;
}

void MaxHeap::insert(ItemType* newItem)
{
	if (_logSize == _physSize)
	{
		_physSize *= 2;
		reAlloc(_heap, _physSize); //execute
	}

	int index = _logSize;
	_logSize++;

	_heap[index] = new ItemType;

	while (index > 0 && *_heap[Parent(index)] < *newItem) //execute operator < for ItemType
	{
		*_heap[index] = *_heap[Parent(index)];
		index = Parent(index);
	}

	if (_heap[index])
		delete _heap[index];

	*_heap[index] = *newItem;
}

void MaxHeap::reAlloc(ItemType* heap[], int newSize)
{

}

ItemType& MaxHeap::Max()
{
	if (_logSize == 0)
		throw exception("Heap is empty!");
	else
		return *_heap[0];
}

ItemType  MaxHeap::DeleteMax()
{
	if (_logSize == 0)
		throw exception("Heap is empty!");
	else
	{
		ItemType max = *_heap[0];

		_logSize--;
		*_heap[0] = *_heap[_logSize];
		delete _heap[_logSize];

		FixHeap(0);

		return max;
	}
}

void MaxHeap::FixHeap(int index)
{
	int max;
	int left = Left(index);
	int right = Right(index);

	if (left<_logSize && *_heap[left] > *_heap[index]) //operator> needed for ItemType (priority)
	{
		max = left;
	}
	else
		max = index;

	if (right<_logSize && *_heap[right] > *_heap[max])
	{
		max = right;
	}

	if (max != index)
	{
		Swap(_heap[index], _heap[max]);
		FixHeap(max);
	}
}
