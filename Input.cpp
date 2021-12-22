#include "Input.h"

void run()
{
	string str;

	int numberOfCommands;
	cin >> numberOfCommands;

	if (numberOfCommands <= 0)
	{
		throw "wrong input";
	}

	cin.get();
	getline(cin, str);
	handleFirstLine(str);

	DataStructure ds = DataStructure::CreateEmpty();

	for (int i = 0; i < numberOfCommands - 1; i++)
	{
		getline(cin, str);
		checkValidCommand(str);
		doStuff(str, ds);
	}

	getline(cin, str);
	if (str != "")
	{
		throw "wrong input";
	}
}

void handleFirstLine(const string& str)
{
	size_t found = str.find_first_not_of("e ");

	if (found != string::npos)
	{
		throw "wrong input";
	}

	found = str.find_first_of("e");
	if (found == string::npos)
	{
		throw "wrong input";
	}

	if (found != str.find_last_of("e"))
	{
		throw "wrong input";
	}
}

void checkValidCommand(const string& str)
{
	char* charstr = new char[str.length() + 1];
	strcpy(charstr, str.c_str());
	char* token = strtok(charstr, " ");

	isValid(token);

	if (*token == 'f')
	{
		token = strtok(nullptr, " ");
		isNumber(token);
	}
	else
	{
		token = strtok(nullptr, " ");
		if (token != nullptr)
			throw "wrong input";
	}

	delete[] charstr;
}

void isValid(const char* str)
{
	if (str == nullptr || !(strcmp(str, "a") == 0 || strcmp(str, "b") == 0 || strcmp(str, "c") == 0 || strcmp(str, "d") == 0 || strcmp(str, "f") == 0 || strcmp(str, "g") == 0))
	{
		throw "wrong input";
	}
}

void isNumber(char* str)
{
	char* c = str;

	if (str == nullptr)
		throw "wrong input";

	if (*c == '-') //negative number is valid
	{
		c++;
		if (*c == '\0') //but if the string was simply "-" it's not valid
			throw "wrong input";
	}

	while (*c != '\0')
	{
		if (*c > '9' || *c < '0')
		{
			throw "wrong input";
		}
		c++;
	}
}

void doStuff(const string& str, DataStructure& ds)
{
	stringstream ss(str);

	char command;
	ss >> command;

	switch (command)
	{
	case 'a':
	{
		cout << ds.Max() << endl;
		break;
	}
	case 'b':
	{
		cout << ds.DeleteMax() << endl;
		break;
	}
	case 'c':
	{
		cout << ds.Min() << endl;
		break;
	}
	case 'd':
	{
		cout << ds.DeleteMin() << endl;
		break;
	}
	case 'g':
	{
		cout << ds.Median() << endl;
		break;
	}
	case 'f':
	{
		int priority;
		ss >> priority;
		string data;
		getline(ss, data);
		removeWhiteSpaceFromStart(data);
		ds.Insert(priority, data);
		break;
	}
	default:
		break;
	}
}

void removeWhiteSpaceFromStart(string& str)
{
	while (str[0] == ' ')
	{
		str.erase(0, 1);
	}
}