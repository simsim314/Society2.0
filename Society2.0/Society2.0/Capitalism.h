#pragma once
#include "Transaction.h"
//The usual single number linear economics with some inflation which is also 
//Only one solution. We can make virtual capitalism without inflation at all. 
//This will not be good if we have investors and productors, but it will work
//for some other scienarious. For example producers and customers it's fine. We 
//can have different money for different purposes this is allowed. We can think 
//About different solutions and try them out and see if this makes something better, 
//To people to live by? 
class Capitalism :	public Transaction
{
public:
	Capitalism();
	~Capitalism();
};

