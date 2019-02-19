#pragma once
#include "CommunicationPerson.h"

class SkillPerson :	public CommunicationPerson
{
	SkillPerson(Person* p, Group* g);
	string name_of_the_skill;
	MetaFloat* skill_rating;
	MetaFloat* skill_teaching_rating;
	MetaFloat* skill_development_speed;

public:
	SkillPerson();
	~SkillPerson();
};

