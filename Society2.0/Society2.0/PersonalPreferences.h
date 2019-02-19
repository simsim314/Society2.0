#pragma once
#include "Group.h"
#include "MetaFloat.h"
#include <map>

class PersonalPreferences : AbstractSerialization
{
public:
	map<string, MetaFloat*> group_priorities; //Uses Group Hash
	MetaFloat* usage_time;
	MetaFloat* prefered_usage_time;

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	PersonalPreferences();
	~PersonalPreferences();
};

