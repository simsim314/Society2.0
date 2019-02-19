#pragma once
#include "Group.h"
#include "SkillGroup.h"

//The idea that hive mind experts should manage everything. Three different skills are established
//People who know well single person - psychology. Just let him tell a story and predict his answer to questionare. 
//People who know well communication between two people. 
//People who are good at generating grop coherence and solving group identity issues. 
class HiveExpertsGroup : public Group
{
	SkillGroup *single;
	SkillGroup *pair_communication;
	SkillGroup *pair_conflict;
	SkillGroup *group_debugging;
	SkillGroup *group_coherence;

public:
	HiveExpertsGroup();
	~HiveExpertsGroup();
};

