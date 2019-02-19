#pragma once
#include "CLBaseNavigator.h"
class CLNews :
	public CLBaseNavigator
{
public:
	void Show();

	//User Response -1 is expecting next_navigator to be filled with data already
	int UserResponse();

	CLNews();
	~CLNews();
};

