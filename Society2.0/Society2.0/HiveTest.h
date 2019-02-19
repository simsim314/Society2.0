#pragma once
#include "Test.h"
#include "Person.h"
#include "MetaFloat.h"
#include <map>
class HiveTest :
	public Test
{
	map<Person*, MetaFloat*> person_score; 
	map<PollQuestion*, MetaFloat*> question_score;
public:
	void EstimatesResults();
	HiveTest();
	~HiveTest();
};

