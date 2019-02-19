#pragma once
#include "Transaction.h"
//This economy believes that transaction between people is a way to pass value.
//Money in this economy expresses the amount of thankfulness people have toward
//This or that value provided to them. The cost price is not fixed and each individual is 
//saying thanks in different amounts. We limit only the thanfulness amount. We provide everything 
//For free for anyone anyway, but we try to measure how much someone is getting more thanks. 
//It's like focus economy, expressed thanks a lot is a way to be in high status. 
class Thankfulness : public Transaction
{
public:
	Thankfulness();
	~Thankfulness();
};

