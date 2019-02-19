#pragma once
#include "Rule.h"
class EthicalValue : public Rule
{
	// Get to news if value is high 
	// Group has function generate_news - it iterates all values and collect in suggestions
	MetaFloat* Measure(Person* person);
	MetaFloat* Measure(MetaString* suggestion);

public:
	
	EthicalValue();
	~EthicalValue();
};

