#pragma once
#include "PollQuestion.h"
class LordQeustion : public PollQuestion
{
public:

	//How the lord will answer
	PollQuestion* estimate_lord_will;

	LordQeustion();
	~LordQeustion();
};

