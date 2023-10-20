#pragma once
#include "IParsable.h"

class HyperbolParser :public IParsable
{
private:

public:
	Object* parse(string org);
	string toString() { return ""; };
};

