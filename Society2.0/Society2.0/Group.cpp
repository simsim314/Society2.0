#include "Group.h"
#include "BasicFunctions.h"

Group::Group()
{
	explorationRate = new MetaFloat();
	globalUsageStats = new MetaFloat();
	g_prefs = new GroupPreferences();
	Group_description = new MetaString();
	Group_name = new MetaString();
	meeting_policy = new MeetingPolicy();
	solcial_order = new SocialOrder();
	realism_of_communications = new MetaFloat();
	userUsageStats = new MetaFloat();
}

Group::~Group()
{
	g_prefs->~GroupPreferences();
	meeting_policy->~MeetingPolicy();
	solcial_order->~SocialOrder();

	delete explorationRate,
	globalUsageStats,
	g_prefs,
	Group_description,
	Group_name,
	meeting_policy,
	solcial_order,
	realism_of_communications,
	userUsageStats;
}

void Group::Merge(Group * other_user)
{
}

vector<MetaFloat*> Group::FlowMeasurements()
{
	return vector<MetaFloat*>();
}

Policy * Group::SafetyPolicy()
{
	return nullptr;
}

void Group::InitHashs()
{
	if(group_customizers != nullptr)
		group_customizers_hash = group_customizers->group_hash;

	if (group_designers != nullptr)
		group_designers_hash = group_designers->group_hash;

	active_users_hashs.clear();
	subscribers_hashs.clear();
	ts_hashs.clear();
	VIPs_groups_hashs.clear();

	for (int i = 0; i < this->active_users.size(); i++)
		active_users_hashs.push_back(this->active_users[i]->person_hash);

	for (int i = 0; i < this->subscribers.size(); i++)
		subscribers_hashs.push_back(this->subscribers[i]->person_hash);

	for (int i = 0; i < this->VIPs_groups.size(); i++)
		VIPs_groups_hashs.push_back(this->VIPs_groups[i]->group_hash);

	for (int i = 0; i < this->ts.size(); i++)
		ts_hashs.push_back(this->ts[i]->transaction_hash);
}

News * Group::GenerateNews()
{
	return nullptr;
}

vector<MetaFloat*> Group::Aggregations(const string & byParameter)
{
	return vector<MetaFloat*>();
}

void Group::ApplyOptimizations()
{
}

vector<MetaString*> Group::PrioritizeSuggestions()
{
	return vector<MetaString*>();
}


GroupPerson * Group::Project(Person * p)
{
	return nullptr;
}

void Group::RuleConsensus(Person * p)
{
}

void Group::AddRule(Rule * rule)
{
}

void Group::InitiateMeeting()
{
}

vector<Transaction*> Group::GeneratePairwiseMeetings()
{
	return vector<Transaction*>();
}

Policy * Group::PolicyToTestSuggestions(Policy * list_suggestions)
{
	return nullptr;
}

Policy * Group::GenerateActivity()
{
	return nullptr;
}

string* Group::ToString()
{
	InitHashs();
	string* result = new string("Group");
	
	FillVectorString(result, this->active_users_hashs);
	FillFromMap(result, this->activity_sequences);
	FillFromMap(result, this->connection_weight_other_group);
	FillVector<Policy>(result, this->disccusion_reports);
	FillParam(result, this->explorationRate);
	FillVector(result, this->genes);
	FillParam(result, this->globalUsageStats);
	FillParam(result, this->g_prefs);
	FillString(result, &group_designers_hash);
	FillString(result, &group_customizers_hash);
	FillParam(result, this->Group_description);
	FillParam(result, this->Group_name);
	FillString(result, &group_hash);
	FillVectorString(result, this->group_search_tags);
	FillParam(result, this->meeting_policy);
	FillParam(result, this->solcial_order);
	FillFromMap(result, this->policies_with_other_groups);
	FillVector(result, this->rated_suggestions);
	FillParam(result, this->realism_of_communications);
	FillVector(result, this->rules);
	FillVectorString(result, this->VIPs_groups_hashs);
	FillParam(result, this->userUsageStats);
	FillVectorString(result, this->ts_hashs);
	FillVectorString(result, this->supported_versions_hash);
	FillVector(result, this->suggestions);
	FillVectorString(result, this->subscribers_hashs);
	
	return result;
}

int Group::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "Group")
		return -1;

	int i = num + 1;
	i = ProccessVectorString(this->active_users_hashs, db_line, i);
	i = ProccessMap(this->activity_sequences, db_line, i);
	i = ProccessMap(this->connection_weight_other_group, db_line, i);
	i = ProccessVector(this->disccusion_reports, db_line, i);
	i = ProccessParam(this->explorationRate, db_line, i);
	i = ProccessVector(this->genes, db_line, i);
	i = ProccessParam(this->globalUsageStats, db_line, i);
	i = ProccessParam(this->g_prefs, db_line, i);
	i = ProcessTheString(&group_designers_hash, db_line, i);
	i = ProcessTheString(&group_customizers_hash, db_line, i);
	i = ProccessParam(this->Group_description, db_line, i);
	i = ProccessParam(this->Group_name, db_line, i);
	i = ProcessTheString(&group_hash, db_line, i);
	i = ProccessVectorString(this->group_search_tags, db_line, i);
	i = ProccessParam(this->meeting_policy, db_line, i);
	i = ProccessParam(this->solcial_order, db_line, i);
	i = ProccessMap(this->policies_with_other_groups, db_line, i);
	i = ProccessVector(this->rated_suggestions, db_line, i);
	i = ProccessParam(this->realism_of_communications, db_line, i);
	i = ProccessVector(this->rules, db_line, i);
	i = ProccessVectorString(this->VIPs_groups_hashs, db_line, i);
	i = ProccessParam(this->userUsageStats, db_line, i);
	i = ProccessVectorString(this->ts_hashs, db_line, i);
	i = ProccessVectorString(this->supported_versions_hash, db_line, i);
	i = ProccessVector(this->suggestions, db_line, i);
	i = ProccessVectorString(this->subscribers_hashs, db_line, i);

	return i;
}
