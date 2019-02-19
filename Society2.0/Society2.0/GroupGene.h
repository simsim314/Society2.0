#pragma once
#include "Policy.h"

class GroupGene
{
public: 
	//Each gene is made of Policies
	//Each policy is some complex flow of ideas which explained in some MetaString
	vector<Policy*> genes; 

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

public:
	GroupGene();
	~GroupGene();
};

