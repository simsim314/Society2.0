#pragma once
#include "CommunityGroup.h"
#include "EthicalValue.h"
#include "Norm.h"
#include "SkillGroup.h"
class CityGroup : public CommunityGroup
{
public:

	//All which is needed for open city managed by the people themselves for themselves. 
	EthicalValue* city_spirit;
	EthicalValue* street_clean;
	EthicalValue* building_aesthetics;
	Norm* agura_square; 
	Norm* spontanius_engagement;

	//Buildings 
	//Sewer
	//Roads & Traffic 
	//Garbage cleaner 
	vector<SkillGroup*> city_providers; 

	CityGroup();
	~CityGroup();
};

