#pragma once
#include "IParsable.h"

class ParabolParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

