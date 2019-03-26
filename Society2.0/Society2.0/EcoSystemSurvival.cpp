#include "EcoSystemSurvival.h"
#include "BasicFunctions.h"


vector<float> EcoSystemSurvival::CalcDerivative(const vector<float>& vec)
{
	return vector<float>();
}

void EcoSystemSurvival::AskExpantionSuggestions()
{
}

void EcoSystemSurvival::GiveVersionMoney(Person * user)
{
}

Currency * EcoSystemSurvival::ConvertFromSurvival()
{
	return nullptr;
}

string * EcoSystemSurvival::ToString()
{
	string* result = new string("EcoSystemSurvival");

	FillVector(result, this->eco_stats);
	FillVectorString(result, this->groups_hashs);
	FillParam(result, this->tamaguchi_strategy);

	return result;
}

int EcoSystemSurvival::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "EcoSystemSurvival")
		return -1;

	int i = num + 1;
	i = ProccessVector(this->eco_stats, db_line, i);
	i = ProccessVectorString(this->groups_hashs, db_line, i);
	i = ProccessParam(this->tamaguchi_strategy, db_line, i);

	return i;
}

EcoSystemSurvival::EcoSystemSurvival()
{
	tamaguchi_strategy = new Tamaguchi();
}


EcoSystemSurvival::~EcoSystemSurvival()
{
	tamaguchi_strategy->~Tamaguchi();
	delete tamaguchi_strategy;
}
