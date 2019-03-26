#pragma once
#include "Person.h"
#include "DBManager.h"
#include "Group.h"
#include "Version.h"
#include "Currency.h"
#include "EcoSystemSurvival.h"

//The rules of EcoSystem are such that the physical meeting are scored differently. I don’t care 
//how you manage the physical and the virtual as long as the app knows to treat them differently 
//and give extra point for physical usage. EcoSystem designers who want to move it to the cloud 
//may do this, as it’s anarchy I’m saying it will fail because people will come back to use countries, 
//or app which connects with physical reality. 
//People do see the difference between them - this is why Zuckerberg works to make a 
//lot of 18th century capitalism dollars. Yet 21st century is self sustained, we say thx to the 
//18th century system of money - but no thanks. Today we can manage everything in multidimentional market
//And other market models based on hive mind and mobile and internet technologies, which you didn't have back then. 

//EcoSystem news are passed to everyone in groups and people without groups. 
//EcoSystem news are updated only when you swap phones - not sure it's the best idea. We want news to spread fast. 

//Initially the EcoSystem is optimized to survive, but eventually it should optimize the evaluation function. 
//The optimization for survival is done only to showcase the technology available today. 
//When we finish to explore we will be left with converging.
class EcoSystem
{
public:

	string eco_hash; 

	Version* v_tree;
	string v_tree_hash; 
	
	EcoSystemSurvival* local_eco;
	EcoSystemSurvival* global_eco;

	vector<Group*> all_groups; //per user + some noise from the world, incluing the Ecosystem as well. 
	vector<Transaction*> all_transactions; //per user + some noise from the world 

	vector<string> all_groups_hashs;
	vector<string> all_transactions_hashs;

	vector<MetaString*> black_list_ids; //per user + some collected "suspects" from the world. 

	//Does the eco system wants to merge branches or to expand some more? The versions are optimized to make EcoSystem happy
	//Happiness of the EcoSystem is a result of convergent process of how to estimate collective happiness, such that everyone will
	//the situation will maximally fit to their intution. This is somewhat complex question but it converges, from different branches. 
	//This is learned by trial and error, branching and merging is a signal to developers what to do. We will split some will branch
	//Some will merge some do nothing, and see what is best statistically. 
	//How much of the time to invest into branching and how much into mering. 0 only merge 1 only develop next version. 
	//Can be optimized per user version and his branch. 
	MetaFloat* branching_factor;

	vector<MetaFloat*> userUsageStats;
	vector<MetaFloat*> globalUsageStats;

	vector<EcoSystem*> others;
	vector<string> others_hash;
	DBManager* db;
	Person* user;
	string user_hash; 

public: //up until now variables, from now on functions. 

	vector<MetaString*> VersionsForward();
	void TravelForward(const int& branch);
	void TravelBackward();

	void InitHashs();

	Person* LoadPersonalData(const string& MAC_Pass);

	// Updates the communication quoue. 
	void RegisterTransaction(Transaction* eco); 
	
	void RegisterNewMember(Person *p);
	void OptimizeGeneSpread();

	//which actions promote growth(genes), predict the growth, and take those actions
	//When the growth stops start to search new strategies and experiment, when growth is good 
	//Continue to do more of the same. The graphs should guide you well. 
	Policy* ActionSurvivalPolicy();

	Policy* SuggestMeetingsToPerson();

	//Here we merge all data 
	//Merge version trees. 
	//See each other like in google glass. 
	//Predict which gene spread will make the system grow faster.
	//Can start from random suggestions to rate them, and spread the suggestions which statistically 
	//make the increment of the ecosystem larger.Give prizes for growing.
	void Merge(EcoSystem* other_person);
public: //public can be used as logical seperator in the class
	EcoSystem();
	~EcoSystem();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
};

