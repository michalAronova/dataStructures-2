#include "DataStructure.h"
#include "Input.h"

int main()
{
	DataStructure ds = DataStructure::CreateEmpty();
	run();


	string str;
	stringstream ss;

	char command;
	int numberOfCommands;

	getline(cin, str);
	numberOfCommands = checkNum(str); // returns -1 if not a number or negative
	if (numberOfCommands == -1)
	{
		cout << "wrong input";
		//throw//
	}

	for (int i = 0; i < numberOfCommands - 1; i++)
	{
		getline(cin, str); 
		if (i == 0)
		{
			if (str != "e")
			{
				cout << "wrong input";
				//throw//
			}
		}
		command = checkValidCommand(str);// returns the command if input is "a-g + endl" or "f ", if empty line or not valid or 'e' return 0 // covers not enough case
		if (!command)
		{
			cout << "wrong input";
			//throw//
		}
		doStuff(str, command);
	}
	getline(cin, str);
	if (str != "")
	{
		cout << "wrong input";
		//throw//
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


