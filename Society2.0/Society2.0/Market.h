#pragma once
#include "Group.h"
#include "TradeGroup.h"

//Legal stuff important
class Market :	public Group
{
	vector<TradeGroup*> traders; 
public:
	Market();
	~Market();
};

