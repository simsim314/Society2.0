#pragma once
#include "Policy.h"
#include "Group.h"
#include "Transaction.h"
#include "PersonalPreferences.h"

class Group; 
class Transaction;
class PersonalPreferences;

//Every user is a person. This is people, they could be imaginary avatars - but we stick here to people. 
//Avatars are usually representatives of groups. 
class Person : public AbstractSerialization
{
public:
	
	vector<Group*> peronal_groups; //Groups he belongs to
	vector<string> peronal_groups_hashs; //Hash to be extracted in ObjectDB

	vector<string> search_tags; 

	//More built in policies which suits all the users. 
	PersonalPreferences* prefernces;

	//His hash using MAC + password. You can't extract personal data from hash.
	//but if you have MAC address then yes. With a search. The search takes a lot of 
	//Calculation power per check. Say 60 seconds. 
	string person_hash; 

	//Person is capable to define general policies and the EcoSystem will know to use them
	//For example person could say please stop sending me spam - and the spam senders if detected
	//Will be fined. This mechanism is not implemented yet but Policy is basically everything 
	//A person has configured. 
	vector<Policy*> all_policies;

	//List of latest transactions done by the person. Transaction can be real and can be done online, 
	//EcoSystem rewards both but rewards more the physical transactions. The DB shared with your friends,
	//And people you meet is larger. You are more exposed to other groups, interests, values of that person, 
	//Than in the online meetings. 
	vector<Transaction*> latest_transactions; 
	vector<string> latest_transactions_hashs; //Hash to be extracted in ObjectDB

	//Prposals
	//Activity
	//Number of people brought in 
	//etc. 
	vector<MetaFloat*>	ecosystem_ratings;
	MetaFloat*	EcoSystemRating();

	void InitFromPolicies(const vector<Policy*>& policies);


	void InitHashLists();

public:
	Person(const vector<Policy*>& policies);
	Person(Person* p);
	Person();
	~Person();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

};

