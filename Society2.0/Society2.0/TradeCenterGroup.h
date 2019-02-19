#pragma once
#include "Market.h"
class TradeCenterGroup : public Market
{
	vector<MetaString*> physical_centers; 

public:
	TradeCenterGroup();
	~TradeCenterGroup();
};

