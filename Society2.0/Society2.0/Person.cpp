#include "Person.h"
#include "BasicFunctions.h"

string* Person::ToString()
{
	InitHashLists();
	string* result = new string("Person");

	FillVector<Policy>(result, this->all_policies);
	FillVector<MetaFloat>(result, this->ecosystem_ratings);

	FillVectorString(result, this->latest_transactions_hashs);
	FillVectorString(result, this->peronal_groups_hashs);
	FillParam(result, prefernces);

	FillVectorString(result, this->search_tags);
	result->append("@" + this->person_hash);

	return result;
}

int Person::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "Person")
		return -1; 

	int i = num + 1;
	i = ProccessVector(all_policies, db_line, i);
	i = ProccessVector(ecosystem_ratings, db_line, i);
	i = ProccessVectorString(latest_transactions_hashs, db_line, i);
	i = ProccessVectorString(peronal_groups_hashs, db_line, i);
	i = prefernces->ProcessString(db_line, i);
	i = ProccessVectorString(search_tags, db_line, i);
	person_hash = db_line[i];
	i++;

	return i;
}

void Person::InitHashLists()
{
	peronal_groups_hashs.clear();
	latest_transactions_hashs.clear(); 

	for (int i = 0; i < this->peronal_groups.size(); i++)
		peronal_groups_hashs.push_back(this->peronal_groups[i]->group_hash);

	for (int i = 0; i < this->latest_transactions.size(); i++)
		latest_transactions_hashs.push_back(this->latest_transactions[i]->transaction_hash);
}


MetaFloat * Person::EcoSystemRating()
{
	return nullptr;
}

void Person::InitFromPolicies(const vector<Policy*>& policies)
{
}

Person::Person(const vector<Policy*>& policies)
{
	InitFromPolicies(policies);
}

Person::Person(Person * p)
{
	InitFromPolicies(p->all_policies);
}

Person::Person()
{
	prefernces = new PersonalPreferences();
}

Person::~Person()
{
	prefernces->~PersonalPreferences();
	delete prefernces;
}
