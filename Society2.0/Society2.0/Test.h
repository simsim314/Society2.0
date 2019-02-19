#pragma once
#include "PollQuestion.h"
#include "Policy.h"

class Test
{
public:
	Policy* list_of_sotries; 
	vector<PollQuestion*>  list_of_polls; 
	
	Test();
	~Test();
};

