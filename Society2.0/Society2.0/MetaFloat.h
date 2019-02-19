#pragma once
#include "Meta.h"

class MetaFloat : public Meta<float, float>
{
public:
	~MetaFloat();
	MetaFloat();
	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
};

