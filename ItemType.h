#ifndef ITEMTYPE_H
	#define ITEMTYPE_H

#include <string>
#include <iostream>

using namespace std;
  
class ItemType {
public:
	ItemType(int priority, string data, int twinIndex = 0) : _priority(priority), _data(data), _twinIndex(twinIndex) {}
	
	friend class DoubleHeap;

private:
	int _priority;
	string _data;
	int _twinIndex;
};
#endif
