#pragma once
#include "MetaMockGenerator.h"
#include "Policy.h"

static Policy* CreatePolicy(const string& str)
{
	Policy* ms = new Policy();
	(ms->policies).push_back(CreateString(str));
	return ms;
}

static Policy* CreatePolicy(const vector<string>& str)
{
	Policy* ms = CreatePolicy(str[0]);
	for(int i = 1; i < str.size(); i++)
		(ms->policies).push_back(CreateString(str[i]));

	return ms;
}

static Rule* CreateRule(const string& name, const string& description)
{
	Rule* ms = new Rule();
	ms->rule_hash = name;
	ms->status = "Applied";
	ms->suggestion = CreateString(description);
	return ms;
}

static PersonalPreferences* CreatePersonalPreference()
{
	PersonalPreferences* ms = new PersonalPreferences();
	ms->usage_time->data = 0.1;
	ms->prefered_usage_time->data = 0.1;

	ms->group_priorities["usage_time"] = ms->usage_time;
	ms->group_priorities["prefered_usage_time"] = ms->prefered_usage_time;

	return ms; 
}

static GroupPreferences* CreateGroupPreference()
{
	GroupPreferences* ms = new GroupPreferences();
	ms->clearance = CreatePolicy("some policy");
	ms->prefs.push_back(CreateString("Who let the dogs out?"));

	return ms;
}

static SocialOrder* CreateSocialOrder()
{
	SocialOrder* ms = new SocialOrder();
	ms->rules.push_back(CreateRule("Number 0", "Don't speak about fight club"));
	ms->rules.push_back(CreateRule("Number 1", "See rule #0"));

	return ms;
}

static MeetingPolicy* CreateMeetingPolicy()
{ 
	MeetingPolicy* ms = new MeetingPolicy(CreatePolicy("Hello!"));
	ms->policies.push_back(CreateString("This is not a dream"));
	ms->policies.push_back(CreateString("This is real life"));

	ms->rules.push_back(CreateRule("Next", "This is the big next thing!"));
	ms->rules.push_back(CreateRule("Don't fight", "It will fight back"));

	ms->realism_level = CreateString("This is not a drill");
	ms->transaction_hash = "A very very big hash"; 

	return ms;
}

static Transaction* CreateTransaction()
{
	Transaction* ms = new Transaction();
	ms->GroupA_hash = "GroupA";
	ms->GroupB_hash = "GroupB";
	ms->PersonA_hash = "Person_A";
	ms->PersonB_hash = "Person_B";
	ms->transaction_hash = "Let there be light";
	return ms;
}

static Person* CreatePerson(const string& hash_name)
{
	Person* person = new Person();
	person->all_policies.push_back(CreatePolicy("Policy A"));
	person->all_policies.push_back(CreatePolicy("Policy B"));

	person->ecosystem_ratings.push_back(CreateFloat(0.3));
	person->ecosystem_ratings.push_back(CreateFloat(0.1));

	person->latest_transactions_hashs.push_back("Misha-Sasha-1");
	person->latest_transactions_hashs.push_back("Misha-Sasha-2");
	person->latest_transactions_hashs.push_back("Sasha-Petya-1");

	person->peronal_groups_hashs.push_back("Chess best group 1");
	person->peronal_groups_hashs.push_back("Chess best group 2");
	person->peronal_groups_hashs.push_back("Cricket best group 1");

	person->person_hash = hash_name;

	person->prefernces = CreatePersonalPreference();

	person->search_tags.push_back("#CoolGuy");
	person->search_tags.push_back("#Interesting");

	return person; 
}

static GroupPerson* CreateGrouPerson()
{
	GroupPerson* ms = new GroupPerson();
	ms->group_clearance_level = CreateString("Fight or flight");
	ms->group_person_hash = "Chess lover 497339";
	ms->interaction_feedback.push_back(CreateString("Ho ho ho!!"));
	ms->interaction_feedback.push_back(CreateString("Yes we can?"));
	ms->in_group_search_tags.push_back("#Chess");
	ms->policies.push_back(CreatePolicy("yo yo"));
	ms->policies.push_back(CreatePolicy("yo yo1"));
	ms->policies.push_back(CreatePolicy("yo yo2"));
	ms->realism_exposure_agreement = CreateString("I want to be private");
	ms->ts.push_back(CreateTransaction());
	ms->ts.push_back(CreateTransaction());
	ms->user = CreatePerson("misha");
	ms->user_clearance = CreatePolicy("misha");
	ms->values.push_back(CreateFloat(0.1));
	ms->values.push_back(CreateFloat(0.2));
	ms->values.push_back(CreateFloat(100));

	return ms;
}

static News* CreateNews(const string& the_news)
{
	News* ms = new News();
	ms->conformations.push_back(CreatePerson("Misha"));
	ms->conformations_hashs.push_back("Misha");
	ms->generator_of_news = new Group();
	ms->generator_of_news_hash = "This is simsim314";
	ms->importantToGroup = CreateFloat(0.32);
	ms->news_hash = "hello kitty";
	ms->rated_suggestions.push_back(CreateString(the_news));
	ms->reporter = CreatePerson("Kuku");
	ms->reporter_hashs = "Kuku hash";
	ms->urgency = CreateFloat(0.221);
	return ms; 
}

static GroupGene* CreateGene(const string& the_gene)
{
	GroupGene* ms = new GroupGene();
	ms->genes.push_back(CreatePolicy(the_gene));
	return ms;
}

static Group* CreateGroup(const string& group_name)
{
	Group* ms = new Group();
	ms->active_users.push_back(CreatePerson("Misha"));
	ms->active_users.push_back(CreatePerson("Sasha"));
	ms->active_users.push_back(CreatePerson("Igor"));

	ms->activity_sequences["This week"] = CreateFloat(0.1);
	ms->activity_sequences["Last week"] = CreateFloat(0.12);

	ms->connection_weight_other_group["Sasha"] = CreateFloat(0.11);
	ms->connection_weight_other_group["Lesha"] = CreateFloat(0.345);

	ms->disccusion_reports.push_back(CreatePolicy("This was fun"));
	ms->disccusion_reports.push_back(CreatePolicy("This was not fun"));

	ms->explorationRate = CreateFloat(0.31);
	ms->genes.push_back(CreateGene("U"));
	ms->genes.push_back(CreateGene("V"));

	ms->globalUsageStats = CreateFloat(0.292);
	ms->group_customizers_hash = "misha customizer";
	ms->Group_description = CreateString("This is a test group");
	ms->group_designers_hash = "misha designers";
	ms->group_hash = "misha group";
	ms->Group_name = CreateString(group_name);
	ms->group_search_tags.push_back("Sasha");
	ms->group_search_tags.push_back("Lesha");
	ms->group_search_tags.push_back("Misha");
	ms->g_prefs = CreateGroupPreference();
	ms->meeting_policy = CreateMeetingPolicy();
	ms->policies_with_other_groups["Lesha Group"] = CreateMeetingPolicy();
	ms->policies_with_other_groups["Sasha Group"] = CreateMeetingPolicy();
	ms->rated_suggestions.push_back(CreateString("A"));
	ms->rated_suggestions.push_back(CreateString("B"));
	ms->rated_suggestions.push_back(CreateString("C"));
	ms->realism_of_communications = CreateFloat(21);
	ms->rules.push_back(CreateRule("D", "dddd"));
	ms->rules.push_back(CreateRule("P", "this is it"));
	ms->solcial_order = CreateSocialOrder();
	ms->subscribers.push_back(CreatePerson("Loal"));
	ms->subscribers.push_back(CreatePerson("Dima"));
	ms->suggestions.push_back(CreatePolicy("Lets try it"));
	ms->suggestions.push_back(CreatePolicy("Lets try it1"));
	ms->suggestions.push_back(CreatePolicy("Lets try it2"));
	ms->supported_versions_hash.push_back("v0.1");
	ms->supported_versions_hash.push_back("v0.2");
	ms->supported_versions_hash.push_back("v0.3");
	ms->ts.push_back(CreateTransaction());
	ms->ts.push_back(CreateTransaction());
	ms->userUsageStats = CreateFloat(0.22);
	ms->VIPs_groups_hashs.push_back("A");
	ms->VIPs_groups_hashs.push_back("B");

	return ms;
}

void FillGroupByHash(Group* ms)
{
	ms->active_users.clear();
	ms->subscribers.clear();
	ms->ts.clear();
	ms->VIPs_groups.clear();

	for(int i = 0; i < ms->active_users_hashs.size(); i++)
		ms->active_users.push_back(CreatePerson(ms->active_users_hashs[i]));
	
	for (int i = 0; i < ms->subscribers_hashs.size(); i++)
		ms->subscribers.push_back(CreatePerson(ms->subscribers_hashs[i]));

	for (int i = 0; i < ms->ts_hashs.size(); i++)
		ms->ts.push_back(CreateTransaction());
}