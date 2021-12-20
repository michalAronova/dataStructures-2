#include "DoubleHeap.h"
void DoubleHeap::insert(ItemType newItem)
{
	insert(newItem._priority, newItem._data);
}

void DoubleHeap::insert(int priority, string data)
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

void DoubleHeap::swap(ItemType& a, ItemType& b)
{
	ItemType temp = a;
	a = b;
	b = temp;
}

ItemType DoubleHeap::deleteHead(heapType T)
{
	ItemType deleted;
	if (T == MAX)
	{
		deleted = deleteMaxByIdx();
	}
	else
	{
		deleted = deleteMinByIdx();
	}
	_heapSize--;
	return deleted;
}
ItemType DoubleHeap::max() const
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");
	else
		return _maxHeap[0];
}

ItemType DoubleHeap::deleteMaxByIdx(int index, int fixed)
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");
	
	else
	{
		ItemType toDelete = _maxHeap[index];

		_maxHeap[index] = _maxHeap[_heapSize-1];
		_minHeap[_maxHeap[index]._twinIndex]._twinIndex = index;

		fixMaxHeap(index);
		if (!fixed)
		{
			deleteMinByIdx(toDelete._twinIndex, 1);

		}

		return toDelete;
	}
}

void DoubleHeap::fixMaxHeap(int index)
{
	int max;
	int left = Left(index);
	int right = Right(index);

	if (left < _heapSize-1 && _maxHeap[left]._priority > _maxHeap[index]._priority) 
	{
		max = left;
	}
	else
	{
		max = index;
	}
	if (right < _heapSize-1 && _maxHeap[right]._priority > _maxHeap[max]._priority)
	{
		max = right;
	}

	if (max != index)
	{
		swap(_maxHeap[index], _maxHeap[max]);
		_minHeap[_maxHeap[index]._twinIndex]._twinIndex = index;
		_minHeap[_maxHeap[max]._twinIndex]._twinIndex = max;
		fixMaxHeap(max);
	}
}

ItemType DoubleHeap::min() const
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");
	else
		return _minHeap[0];
}

ItemType DoubleHeap::deleteMinByIdx(int index, int fixed)
{
	if (_heapSize == 0)
		throw exception("Heap is empty!");

	else
	{
		ItemType toDelete = _minHeap[index];

		_minHeap[index] = _minHeap[_heapSize - 1];
		_maxHeap[_minHeap[index]._twinIndex]._twinIndex = index;

		fixMinHeap(index);
		if (!fixed)
		{
			deleteMaxByIdx(toDelete._twinIndex, 1);
		}
		return toDelete;
	}
}

void DoubleHeap::fixMinHeap(int index)
{
	int min;
	int left = Left(index);
	int right = Right(index);

	if (left < _heapSize - 1 && _minHeap[left]._priority < _minHeap[index]._priority)
	{
		min = left;
	}
	else
	{
		min = index;
	}
	if (right < _heapSize - 1 && _minHeap[right]._priority < _minHeap[min]._priority)
	{
		min = right;
	}

	if (min != index)
	{
		swap(_minHeap[index], _minHeap[min]);
		_maxHeap[_minHeap[index]._twinIndex]._twinIndex = index;
		_maxHeap[_minHeap[min]._twinIndex]._twinIndex = min;
		fixMinHeap(min);
	}
}
