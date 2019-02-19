#pragma once
#include "GroupPerson.h"
class PyramidPerson : public GroupPerson
{
public:

	PyramidPerson* lord;
	vector<PyramidPerson*> disciples;

	//by default each layer is 1 / (10 * Ord). Unless changed by the lord or someone above. 
	MetaString* priority_permission; 
	MetaString* required_permission_to_change_status; //if 1 only the lord can touch you

	MetaString* AskToSwap(PyramidPerson* person);
	PyramidPerson();
	~PyramidPerson();
};

