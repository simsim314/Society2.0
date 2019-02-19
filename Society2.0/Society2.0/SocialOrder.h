#pragma once
#include "Group.h"
#include "Rule.h"
class Group; 
class Rule; 

class SocialOrder
{
public:
	vector<Rule*> rules;
	virtual void UpdateValues(Group* g);

public:

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	SocialOrder();
	~SocialOrder();
};

