#include "DataStructure.h"
#include "Input.h"

int main()
{
	try 
	{
		run();
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
}
	/*
	ds.Insert(99, "raq");
	ds.Insert(-100, "shc");
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.DeleteMin() << endl; //d
	cout << ds.DeleteMin() << endl; //d
	*/
	/* input 2
	ds.Insert(1, "Regen");
	ds.Insert(25, "gegen");
	ds.Insert(150, "t62 Hammer");
	ds.Insert(10, "LEid");
	ds.Insert(-7, "Prinzip");
	cout << ds.Min() << endl; //c
	cout << ds.Max() << endl; //a
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.Max() << endl; //a
	cout << ds.Median() << endl; //g
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.DeleteMin() << endl; //d
	ds.Insert((-7), "addition");
	ds.Insert(900, "another MistAke");
	cout << ds.Median() << endl; //g
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.DeleteMax() << endl; //b 
	cout << ds.Min() << endl; //c
	cout << ds.Max() << endl; //a*/


