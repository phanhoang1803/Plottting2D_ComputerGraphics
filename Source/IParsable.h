#pragma once
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class IParsable :public Object
{
private:

public:
	virtual Object* parse(string org) = 0;
	string toString() = 0;
};

