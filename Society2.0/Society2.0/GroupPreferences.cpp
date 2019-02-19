#include "GroupPreferences.h"
#include "BasicFunctions.h"


Policy * GroupPreferences::AcceptancePolicy()
{
	return nullptr;
}

string * GroupPreferences::ToString()
{
	string* result = new string("GroupPreferences");

	FillParam(result, clearance);
	
	FillVector<MetaString>(result, this->prefs);
	
	return result; 
}

int GroupPreferences::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "GroupPreferences")
		return -1;

	int i = num + 1;
	i = clearance->ProcessString(db_line, i);
	i = ProccessVector(prefs, db_line, i);
	
	return i;
}

GroupPreferences::GroupPreferences()
{
	clearance = new Policy();
}

GroupPreferences::~GroupPreferences()
{
}
