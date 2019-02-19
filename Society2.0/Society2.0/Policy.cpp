#include "Policy.h"
#include "BasicFunctions.h"

Policy::Policy()
{
	policyType = new MetaString();
}

Policy::~Policy()
{
	delete policyType; 

	for(int i = 0; i < policies.size(); i++)
		delete policies[i];
}

string* Policy::ToString()
{
	string* result = new string();
	FillVector<MetaString>(result, policies, false);
	return result;
}

int Policy::ProcessString(const vector<string>& db_line, int num)
{
	return ProccessVector<MetaString>(policies, db_line, num);
}
