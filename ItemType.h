#ifndef ITEMTYPE_H
	#define ITEMTYPE_H

#include <string>
#include <iostream>

using namespace std;
  
class ItemType {
public:
	ItemType(int priority = 0, string data = "", int twinIndex = 0) : _priority(priority), _data(data), _twinIndex(twinIndex) {}
	
	friend ostream& operator<<(ostream& os, const ItemType& item);
	friend class DoubleHeap;
	friend class DataStructure;

private:
	int _priority;
	string _data;
	int _twinIndex;
};
#endif
