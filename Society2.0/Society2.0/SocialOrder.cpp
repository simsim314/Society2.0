#include "SocialOrder.h"
#include "BasicFunctions.h"

void SocialOrder::UpdateValues(Group * g)
{
}

SocialOrder::SocialOrder()
{
}

SocialOrder::~SocialOrder()
{
}

string * SocialOrder::ToString()
{
	string* result = new string("SocialOrder");
	FillVector<Rule>(result, this->rules);

	return result;
}

int SocialOrder::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "SocialOrder")
		return -1;

	int i = num + 1;
	i = ProccessVector(rules, db_line, i);

	return i; 
}