#include "DataStructure.h"


ItemType DataStructure::Max() const
{
	if (_size == 0)
	{
		throw exception("Heap is empty!");
	}
	else if (_size == 1)
	{
		return _small.max();
	}
	else
		return _big.max();
}

ItemType DataStructure::DeleteMax()
{
	if (_size == 0)
	{
		throw exception("Heap is empty!");
	}
	else
	{
		ItemType max = _big.deleteMaxByIdx();
		balance();
		_size--;
		return max;
	}
}

ItemType DataStructure::Min() const
{
	if (_size == 0)
	{
		throw exception("Heap is empty!");
	}
	else
		return _small.min();
}

ItemType DataStructure::DeleteMin()
{
	if (_size == 0)
	{
		throw exception("Heap is empty!");
	}
	else
	{
		ItemType min = _small.deleteMinByIdx();
		balance();
		_size--;
		return min;
	}
}

DataStructure DataStructure::CreateEmpty()
{
	 DataStructure DS;
	 return DS;
}

void DataStructure::Insert(int priority, string data)
{
	if (_size == 0)
	{
		_small.insert(priority, data);
	}
	else if (priority <= Median()._priority)
	{
		_small.insert(priority, data);
		balance();
	}
	else
	{
		_big.insert(priority, data);
		balance();
	}
	_size++;
}

ItemType DataStructure::Median()
{
	if (_size == 0)
	{
		throw exception("Heap is empty!");
	}
	else
		return _small.max();
}

void DataStructure::balance()
{
	ItemType ToMove;
	if (_small._heapSize - _big._heapSize > 1)
	{
		ToMove = _small.deleteMaxByIdx();
		_big.insert(ToMove);
	}

	else if (_big._heapSize - _small._heapSize > 0)
	{
		ToMove = _big.deleteMinByIdx();
		_small.insert(ToMove);
	}
}
