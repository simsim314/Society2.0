#pragma once
#include "CLBaseNavigator.h"
class CLPoll :	public CLBaseNavigator
{
public:
	vector<string> button_hash;

	void Show();

	//User Response -1 is expecting next_navigator to be filled with data already
	int UserResponse();

	CLPoll();
	~CLPoll();
};

