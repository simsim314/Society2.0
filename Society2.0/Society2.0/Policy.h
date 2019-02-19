#pragma once
#include "MetaString.h"

class Policy : public AbstractSerialization
{
public:
	Policy();
	~Policy();

	vector<MetaString*> policies; 
	MetaString* policyType; 

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
};