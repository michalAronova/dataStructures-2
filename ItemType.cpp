#include "ItemType.h"

ostream& operator<<(ostream& os, const ItemType& item)
{
	os << item._priority << " " << item._data;
	return os;
}