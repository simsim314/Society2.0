#pragma once
#include "Currency.h"

class CurrencyManager
{
public:

	//Convert money from one to another; 
	//simple case why we need two dimensions. Some people don’t believe in new money some in old. 
	//If we hold only one currency we are locking ourselves to single number 
	//managed by someone not as smart as hive mind. 
	//Just as Amazon can guess how much of each book it will need we can use algorithms 
	//To guess how much of specific resource we will need. For example (old,new) money pair is predictible by usage.
	Currency* Convert(Currency* other);
	CurrencyManager();
	~CurrencyManager();
};

