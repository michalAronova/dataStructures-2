#ifndef INPUT_H
	#define INPUT_H

#pragma warning (disable:4996)

#include <iostream>
#include <sstream>
#include <string>
#include "DataStructure.h"

using namespace std;

void run();
void checkValidCommand(const string& str);
void isValid(const char* str);
void isNumber(char* str);
void doStuff(const string& str, DataStructure& ds);
void removeWhiteSpaceFromStart(string& str);
void handleFirstLine(const string& str);
#endif