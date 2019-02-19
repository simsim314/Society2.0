#pragma once
#include "SkillPerson.h"
class HappinessPerson :	public SkillPerson
{
public:
	vector<MetaFloat*> happiness_scores; 
	MetaFloat* happiness;

	HappinessPerson();
	~HappinessPerson();
};

