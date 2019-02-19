#pragma once
#include "GroupPerson.h"
#include <utility>

class GroupPerson; 

class Transaction
{
public:
	//The hash of the group in the global (locally represented) dictionary of groups. 
	string transaction_hash;

	string PersonA_hash;
	string PersonB_hash;
	string GroupA_hash;
	string GroupB_hash;

	GroupPerson* A;
	GroupPerson* B;
	Group* gA;
	Group* gB;

	void GeneratePoll(); //Personalized poll for this meeting. 
	void Genratetopics(); //Personalized discussion question 
	void MakeSuggestions(); //Don’t see now the UI very well. 
	vector<pair<Group*, Group*>> GenerateGroupsOfInterest(float time_expendirture);

public:
	Transaction();
	~Transaction();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

};
