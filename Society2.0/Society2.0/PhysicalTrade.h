#pragma once
#include "Transaction.h"

//This economy believes we can come back to hunters gatherers and trade with 
//each other using usual trade market. We only need a super smart trading algorithm
//and some sort of prediction what people need, with a large tail of objects. Or we 
//can use 3d printing for that matter. So everything is traded in some sort of virtual 
//value which is computed from the trading values currently. But this is not one 
//dimensional economy, it's multu dimensional economy applied to trades. 
class PhysicalTrade :	public Transaction
{
public:
	PhysicalTrade();
	~PhysicalTrade();
};

