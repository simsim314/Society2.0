#pragma once
#include "Transaction.h"
//Reference count is somewhat similiar to focus economy but to be reffered you need more to 
//just catch up a focus. You need to make something valuable to someone else. And the fact 
//that you have made something useful assuming making useful things is hard, so reference 
//is optimized to be appritiated by other people. So there is some weight to reference count 
//and some weight to weighted reference count, and we can play with some functions and check 
//some interesting top level references and this is our economy. We promote people who contribute
//good ideas and this is replaced by some other goods in some other economies. You can call it 
//capitalistic money. 
class ReferenceCount : public Transaction
{
public:
	ReferenceCount();
	~ReferenceCount();
};

