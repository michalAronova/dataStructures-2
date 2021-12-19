#include "DoubleHeap.h"

int DoubleHeap::insert(int priority, string data)
{
	if (_heapSize >= MAX_SIZE)
	{
		throw exception("Reached heap maximum size.");
	}

	int maxIndex = _heapSize;
	int minIndex = _heapSize;
	++_heapSize;

	while (maxIndex > 0 && _maxHeap[Parent(maxIndex)]._priority < priority) // not first item AND my fathers priority is smaller than mine
	{
		_maxHeap[maxIndex] = _maxHeap[Parent(maxIndex)];
		_minHeap[_maxHeap[maxIndex]._twinIndex]._twinIndex = maxIndex;
		maxIndex = Parent(maxIndex);
	}
	_maxHeap[maxIndex] = ItemType(priority, data, minIndex);

	while (minIndex > 0 && _minHeap[Parent(minIndex)]._priority > priority) // not first item AND my fathers priority is bigger than mine
	{
		_minHeap[minIndex] = _minHeap[Parent(minIndex)];
		_maxHeap[_minHeap[minIndex]._twinIndex]._twinIndex = minIndex;
		minIndex = Parent(minIndex);
	}
	_minHeap[minIndex] = ItemType(priority, data, maxIndex);
	_maxHeap[maxIndex]._twinIndex = minIndex;

}

void DoubleHeap::fixMaxHeap(int index)
{
	int max;
	int left = Left(index);
	int right = Right(index);

	if (left<_logSize && *_heap[left] > * _heap[index]) //operator> needed for ItemType (priority)
	{
		max = left;
	}
	else
		max = index;

	if (right<_logSize && *_heap[right] > * _heap[max])
	{
		max = right;
	}

	if (max != index)
	{
		Swap(_heap[index], _heap[max]);
		FixHeap(max);
	}
}

ItemType DoubleHeap::max() const
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");
	else
		return _heap[0];
}

ItemType  DoubleHeap::deleteMax()
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");
	else
	{
		ItemType max = _heap[0];

		_heapSize--;
		_heap[0] = _heap[_heapSize];

		fixHeap(0);

		return max;
	}
}

