#include "MeetingPolicy.h"
#include "BasicFunctions.h"


MetaString * MeetingPolicy::NextRecomindationFlow(MetaString * last_interaction_result)
{
	return nullptr;
}

void MeetingPolicy::IntroduceSuggestionInFlow(MetaString * suggestion, int k)
{
}

void MeetingPolicy::RenumberSuggestion()
{
}

MeetingPolicy::MeetingPolicy()
{
	realism_level = new MetaString();
}

MeetingPolicy::MeetingPolicy(Policy* policy)
{
	realism_level = new MetaString();

	string* polic = policy->ToString();
	vector<string> split = split_string(*polic, '@');
	this->Policy::ProcessString(split, 0);
	delete polic;

	realism_level = new MetaString();
}

MeetingPolicy::~MeetingPolicy()
{
	delete realism_level;
}

string * MeetingPolicy::ToString()
{
	string* result = new string("MeetingPolicy");

	string* value_s = Policy::ToString();
	result->append("@" + *value_s);
	delete value_s;

	FillVector<Rule>(result, this->rules);
	FillParam(result, realism_level);

	result->append("@" + transaction_hash);
	return result;
}

int MeetingPolicy::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "MeetingPolicy")
		return -1;

	int i = num + 1;

	i = this->Policy::ProcessString(db_line, i);
	i = ProccessVector(rules, db_line, i);
	i = realism_level->ProcessString(db_line, i);
	transaction_hash = db_line[i];
	i++;

	return i;
}
