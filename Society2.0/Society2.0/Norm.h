#pragma once
#include "Rule.h"
//Apply of norms will reduce to people who has violated norms and will 
//Remove some people from group who has violated laws. Update Eco system on that person. 
//Remove from group 
class Norm : public Rule
{
public:
	bool ToRemove(Person* person);
	bool AddToBlackList(Person* person);

	Norm();
	~Norm();
};

