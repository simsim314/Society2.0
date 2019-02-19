#pragma once
#include "CLBaseNavigator.h"
class CLGlobalNavigator :	public CLBaseNavigator
{
protected:
	vector<string> button_hash;

public:
	void Show();

	//User Response -1 is expecting next_navigator to be filled with data already
	int UserResponse();

	CLGlobalNavigator();
	~CLGlobalNavigator();
};

