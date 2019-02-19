#pragma once
#include "Transaction.h"
class Trade : public Transaction
{
public:
	MetaString* trade_description;
	MetaString* start_state;
	MetaString* end_state;

	Trade();
	~Trade();
};

