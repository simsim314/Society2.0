#pragma once
#include "Group.h"
#include "CommunityPerson.h"
#include "PyramidPerson.h"

class StarGroup : public Group
{
	CommunityPerson* user;
	PyramidPerson* star;
public:

	StarGroup();
	~StarGroup();
};

