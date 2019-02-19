#pragma once
#include "Group.h"
#include "HivePollQuestion.h"
#include "SkillPerson.h"

class SkillGroup : public Group
{
private:
	void UpdateSkillPeople();
public:
	vector<HivePollQuestion*> questions;
	vector<SkillPerson*> skilled_people; 
	
	Person* GenerateSuperHumanAgent();

	SkillGroup();
	~SkillGroup();
};

