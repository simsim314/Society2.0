#pragma once
#include "CommunityGroup.h"
#include "Group.h"
#include "SkillGroup.h"

class TradeGroup : public CommunityGroup
{
public:
	Group* customers;
	SkillGroup* suppliers;

	TradeGroup();
	~TradeGroup();
};


