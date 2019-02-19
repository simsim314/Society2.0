#pragma once
#include "PollQuestion.h"
class HivePollQuestion : PollQuestion
{
public:
	
	//How well the others have actioned 
	vector<PollQuestion*> estimate_q_statistics;

	HivePollQuestion();
	~HivePollQuestion();
};

