#pragma once
#include <map>
#include "Person.h"
#include "Rule.h"
#include "GroupPreferences.h"

#include "SocialOrder.h"
#include "MeetingPolicy.h"
#include "News.h"
#include "GroupGene.h"
#include "Version.h"

class GroupVIPs;
class Person; 
class GroupPerson;
class Transaction;
class SocialOrder; 
class MeetingPolicy;
class News;
class Rule; 

//A set of people around some topic, interest, or just group of local friends etc. 
class Group : public AbstractSerialization
{
public:
	//The hash of the group in the global (locally represented) dictionary of groups. 
	string group_hash; 

	vector<Person*> subscribers; //known to the user 
	vector<string> subscribers_hashs; //known to the user 

	vector<Person*> active_users; //known to the user 
	vector<string> active_users_hashs; //known to the user 

	vector<string> group_search_tags;

	MetaFloat* userUsageStats;
	MetaFloat* globalUsageStats;

	//Group usually has server, and it exchanges policies. I.e. people who want to see the //news see only the news, people who want to participate and make suggestion and polls, also //on server. People who meet and make transactions. 
	//Leaky pyramid for contribution is always installed per group to encourage participation. //Or whatewer is best for encouraging
	//Groups get point from the app and it has leacky pyramid 
	GroupPreferences* g_prefs;

	//VIP by different categories. 
	//Best chess players
	//Best chess organizers 
	//Best chess teachers etc. 
	vector<Group*> VIPs_groups;
	vector<string> VIPs_groups_hashs;
	
	//List of version EcoSystem supported by the group. 
	vector<string> supported_versions_hash; 

	//Norms, Values and laws in the group
	vector<Rule*> rules; 

	//Genes from other groups as suggestions. 
	//Suggestion from current group members.
	vector<Policy*> suggestions; 

	MetaString* Group_description;
	MetaString* Group_name;

	//Each group has a subgroup of its programmers. 
	Group* group_designers;
	string group_designers_hash;

	//Each group has a subgroup of people who can customize its ruels, without reprogram anything. 
	Group* group_customizers;
	string group_customizers_hash;

	//discussion reports which are highly rated. Generates news as well, and polls to rate bad news. 
	vector<Policy*> disccusion_reports; 

	//Measures how much people are participating in expanding the group, and exploring new 
	//effective ways to expand the group, over how much people enjoy the group. 
	MetaFloat* explorationRate;

	SocialOrder* solcial_order;
	MeetingPolicy* meeting_policy; //inside the group
	map<string, MeetingPolicy*> policies_with_other_groups; //with other groups. 

	vector<MetaString*> rated_suggestions; // String, estimated time by designers, estimated value to the group. 
	vector<MetaString*> PrioritizeSuggestions();

	MetaFloat* realism_of_communications; //How do we manage to become reality vs. virtuality

	//if the groups don’t communicate well  the Ecosystem will not force them.
	//The point is to be connected well as different groups, not to force some sort of graph between them.
	map<string, MetaFloat*> connection_weight_other_group;

	//Genes are policies which, the group might implement. 
	//How much time per group (the group will define it)
	vector<GroupGene*> genes;

	//Subset of the transaction done in the group and all user transactions as well
	vector<Transaction*> ts;
	vector<string> ts_hashs;

	//Growth of the group realism generation
	//Group transactions per week
	//Group Money making for the app 
	//Group members growth per week
	//Group coherence - ability to generate meaningful output as a group
	//Group violance - how much violance the group uses in order to make people part of it. - can be rated by anyone. 
	//Group lies - how much lies the group uses in order to make you part of it. - can be rated only from outside. 
	//Heterogenessy - how much the group is clustered, and how much is it similiar to one another. 
	map<string, MetaFloat*> activity_sequences;

	//All of the above made by some different methods. 
	virtual vector<MetaFloat*> Aggregations(const string& byParameter);
	
	//Some of suggestion don’t require coding only changing some of the values of the group definition. 
	//If consensus has been reached. As coders control the group - coders group makes trade with every specific group 
	//Providing coding serveses for payment. They can shut down some group just because they feel like it. Obviously 
	//They will shoot themselves in the foot, but they can. So this is important moment - but beforehand, people can ask menus 
	//for self governing, and those menus will be customized automatically using some sort of prepared GUI tools for the group. 
	virtual void ApplyOptimizations();

	virtual GroupPerson* Project(Person* p);

	////If consensus was reached and enforced upon people in group - they can always split. 
	//They are actually encouraged to split as a group. This is actually good for the EcoSystem, 
	//small groups that explore as many possible options as they can. But this will also be a 
	//parameter in the EcoSystem. Everything is done for the EcoSystem to survive first and the 
	//communities later. The split encouragement is something which is measured by the 
	//EcoSystem to be optimal.  
	//Please be careful here and don't make everyone play a lot of phones all the time non stop to 
	//Increase artificially EcoSystem parameters. Please, please be smart about it and understand this is 
	//done only in the beginning to create legal pressure only. No force to be applied. 
	//And the next futuristic scenaio you should avoid is the part when everyone are so much attached to
	//the application so that they stop doing anything at all. They get crazy and enjoy themselves forwever to death. 
	//The application should not become heroin, but some other drug. A drgu of human consiosness self control 
	//In meaningful manner to itself. Like becoming a rick, a super-human generated by hive mind technology. Like democracy
	//but democracy doesn't make sense for many questions (in 2016 there was an article about this hive mind idea). So this is one 
	//of the things which is done in the application everywhere, and then improved because this is just an initial huirsitcs. The 
	//The point is that specialists are independently discovering similiar things. Just saying the application is a result 
	//of a lot of thinking and expiriencing with many different medicins. 
	virtual void RuleConsensus(Person* p);
	virtual void AddRule(Rule* rule);
	virtual void InitiateMeeting(); //The system optimizes time schedule of everyone. 
	virtual vector<Transaction*> GeneratePairwiseMeetings(); //In the meeting itself. 

	News* GenerateNews();

	// The simple policy is to have 5 * 10^N filters, in each layer you should pass those with        
	//score such that X% only pass. Those who pass you probe on higher scale - such that the flow 
	//of information from bottom to top will be optimized. 
	Policy* PolicyToTestSuggestions(Policy* list_suggestions);

	//Each UI is optimizing to be interesting per each size so that you will grow.
	//You will also get points for the growth.
	//Hevruta split. Consensus and testing of suggestions 
	//Find experts with high probability and rating per expert 
	//Group coherence can be reached for large groups - i.e. chess players.
	Policy* GenerateActivity(); 

	//With groups data from other users 
	virtual void Merge(Group* other_user);

	vector<MetaFloat*> FlowMeasurements(); 
	//Communication between groups
	//Small groups are less threatened, medium size groups are threatened the most. Large groups once again safe. 
	//The larger the group the less it is threatened
	Policy* SafetyPolicy();

	void InitHashs();
public:

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	Group();
	~Group();
};

