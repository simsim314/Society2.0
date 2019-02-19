#pragma once
#include "SkillGroup.h"
#include "HiveTest.h"
#include <map>

//This is a quest for programmers to understand the idea. It takes several days of tests in total.
//He should really get the value system of the revolution.
class TrustedDevelopers : public SkillGroup
{
	map<SkillPerson*, MetaString* > person_to_achievements; 

	//Depends on the knowledge of the code and ideology, estimated by other members of the group.
	//Commiting the code together increses the trust.
	float Trust(SkillPerson* developer); 

	static vector<HiveTest*> acceptance_tests;

public:
	TrustedDevelopers();
	~TrustedDevelopers();
};

