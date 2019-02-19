#pragma once
#include "Person.h"
#include "Policy.h"
#include "Group.h"
#include "MetaFloat.h"
#include "Transaction.h"

class Group;
class Person;
class Transaction; 
class Policy; 

class GroupPerson : public AbstractSerialization
{
public:
	//The hash of the group in the global (locally represented) dictionary of groups. 
	string group_person_hash;

	vector<MetaString*> interaction_feedback; //Feedbacks from interactions with you
	
	//How much he agreed to meet people from the group, in real life? 
	MetaString* realism_exposure_agreement; 
	
	vector<Transaction*> ts;
	vector<string> ts_hash; 

	//How much did the person contribute in order to see the next level of the group. 
	//The people who want to read news, will not be able to participate yet they can still make 
	//suggestions and answer polls. They will not be active representatives of the group. 
	MetaString* group_clearance_level;
	
	//safety issues. Person can ask not to show this group to people with lower clearance 
	Policy* user_clearance;

	vector<MetaFloat*> values; //List of values with some metadata. Ratings and stuff. 
	vector<Policy*> policies; //Policies relevant from person to this group. 

	Person* user; 
	string user_hash;

	vector<string> in_group_search_tags;

public:

	GroupPerson(Person* p, Group* g);

	GroupPerson();
	~GroupPerson();

	inline MetaFloat* actual_time_spent() { return values[0]; };
	inline MetaFloat* value_generated_for_Group() { return values[1]; };
	inline MetaFloat* proposals_quality_rating() { return values[2]; };
	inline MetaFloat* rating_contribution_to_group() { return values[3]; };
	inline MetaFloat* rating_predicting_group_distribution() { return values[4]; };
	inline MetaFloat* rating_predicting_random_person() { return values[5]; };
	inline MetaFloat* rating_interaction_feedback() { return values[6]; }; //

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

};