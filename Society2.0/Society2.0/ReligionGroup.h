#pragma once
#include "Pyramid.h"
class ReligionGroup : public Pyramid
{
	vector<MetaString*> rituals; 
public:
	ReligionGroup();
	~ReligionGroup();
};

