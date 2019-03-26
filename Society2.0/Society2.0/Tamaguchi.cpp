#include "Tamaguchi.h"
#include "BasicFunctions.h"

Policy * Tamaguchi::AlertingPolicy()
{
	return nullptr;
}

MetaString * Tamaguchi::EmotionToDisplay()
{
	return nullptr;
}

Policy * Tamaguchi::SurvivalStrategyOnPhone()
{
	return nullptr;
}

MetaFloat * Tamaguchi::EstimateLifehood()
{
	return nullptr;
}

string* Tamaguchi::ToString()
{
	string* result = new string("Tamaguchi");

	FillVector(result, this->history_of_usage_and_score);
	FillParam(result, this->personification_score);
	
	return result;
}

int Tamaguchi::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "Tamaguchi")
		return -1;

	int i = num + 1;
	i = ProccessVector(this->history_of_usage_and_score, db_line, i);
	i = ProccessParam(this->personification_score, db_line, i);
	
	return i;
}

Tamaguchi::Tamaguchi()
{
	personification_score = new MetaFloat();
}


Tamaguchi::~Tamaguchi()
{
	delete personification_score;
}
