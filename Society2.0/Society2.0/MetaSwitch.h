#pragma once
#include "MetaFloat.h"
#include "MetaString.h"

class MetaSwitch : public AbstractSerialization
{
public:
	MetaString* measure; 
	MetaFloat* value;
	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	MetaSwitch();
	~MetaSwitch();
};

