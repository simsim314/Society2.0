#pragma once
#include "MetaString.h"
#include "Person.h"
class Person;

class Rule
{
public:
	string rule_hash;
	string status; //experimental, first level, second level etc. 
	MetaString* suggestion;

	void ApplyRule(Person* p);
	
	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

public:
	Rule();
	~Rule();
};

