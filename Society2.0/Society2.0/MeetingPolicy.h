#pragma once
#include "Transaction.h"
#include "Rule.h"
#include "Policy.h"

class Transaction;
class Policy; 

class MeetingPolicy : public Policy
{
public: 

	//The limits in which the meeting is assumed to take place. This could be list of axioms, topics allowed to discuss etc.
	//More than the limits we use values to direct the meeting into profitible for the whole group direction. 
	//Values 
	//Norms 
	//laws
	vector<Rule*> rules;
	
	Transaction* trans; 
	string transaction_hash; 

	MetaString* realism_level;

	// if rules == null, use standard protocol. 
	//Ask suggestions before the meeting. 
	//Ask people who have been there. Think of suggestions and generate new ones. 
	//Here we also use suggestions from other people with probability K. 
	//We can be informed being experimented upon or not informed according to group policy. 
	//Dictionary of every two groups policies. If there is no policy people discuss make suggestions. 
	//Special syntax to say Goto Node N - or we will show them node by node as they wish. 
	//Suggestions will automatically be renumbered. 
	MetaString* NextRecomindationFlow(MetaString* last_interaction_result); 

	void IntroduceSuggestionInFlow(MetaString* suggestion, int k);
	void RenumberSuggestion(); //Loop over rules, and $N->$(N+1) for N > k

public:
	MeetingPolicy();
	MeetingPolicy(Policy * policy);
	~MeetingPolicy();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
};

