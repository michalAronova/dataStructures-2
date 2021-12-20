#include "DataStructure.h"

int main()
{
	DataStructure ds = DataStructure::CreateEmpty();
	ds.Insert(25, "QWERTY");
	ds.Insert(10, "JSON");
	ds.Insert(30, "XML");
	cout << ds.Min() << endl;
	cout << ds.DeleteMax() << endl;
	ds.Insert((-10), "HTML");
	cout << ds.Median() << endl;
	cout << ds.DeleteMax() << endl;
	cout << ds.DeleteMax() << endl;
	cout << ds.Median() << endl;
}