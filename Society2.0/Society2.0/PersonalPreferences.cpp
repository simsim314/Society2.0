#include "PersonalPreferences.h"
#include "BasicFunctions.h"

string* PersonalPreferences::ToString()
{
	string* result = usage_time->ToString();
		
	FillParam(result, prefered_usage_time);
	FillFromMap<MetaFloat>(result, this->group_priorities);

	return result;
}

int PersonalPreferences::ProcessString(const vector<string>& db_line, int num)
{
	int i = num;
	i = usage_time->ProcessString(db_line, i);
	i = prefered_usage_time->ProcessString(db_line, i);
	i = ProccessMap<MetaFloat>(this->group_priorities, db_line, i);
	return i;
}

PersonalPreferences::PersonalPreferences()
{
	prefered_usage_time = new MetaFloat();
	usage_time = new MetaFloat();
}


PersonalPreferences::~PersonalPreferences()
{
	delete prefered_usage_time, usage_time;
}
