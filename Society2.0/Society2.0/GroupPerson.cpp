#include "GroupPerson.h"
#include "BasicFunctions.h"

GroupPerson::GroupPerson(Person * p, Group * g)
{
}

GroupPerson::GroupPerson()
{
	group_clearance_level = new MetaString();
	realism_exposure_agreement = new MetaString();
	user_clearance = new Policy();
	user = new Person();
}

GroupPerson::~GroupPerson()
{
	user->~Person();
	user_clearance->~Policy();

	delete group_clearance_level, realism_exposure_agreement, user_clearance;
}

string * GroupPerson::ToString()
{
	string* result = new string("GroupPerson");

	FillParam(result, group_clearance_level);
	FillParam(result, realism_exposure_agreement);
	FillParam(result, user_clearance);
	FillString(result, &user_hash);

	FillVector<MetaString>(result, this->interaction_feedback);
	FillVector<MetaFloat>(result, this->values);

	FillVectorString(result, this->ts_hash);

	FillVectorString(result, this->in_group_search_tags);
	FillVector<Policy>(result, policies);

	result->append("@" + group_person_hash);
	
	return result; 
}

int GroupPerson::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "GroupPerson")
		return -1;

	int i = num + 1;

	i = ProccessParam(group_clearance_level, db_line, i);
	i = ProccessParam(realism_exposure_agreement, db_line, i);
	i = ProccessParam(user_clearance, db_line, i);
	i = ProcessTheString(&user_hash, db_line, i);
	i = ProccessVector(interaction_feedback, db_line, i);
	i = ProccessVector(values, db_line, i);
	i = ProccessVectorString(ts_hash, db_line, i);
	i = ProccessVectorString(in_group_search_tags, db_line, i);
	i = ProccessVector(policies, db_line, i);

	group_person_hash = db_line[i];
	i++;
	
	return i; 
}

