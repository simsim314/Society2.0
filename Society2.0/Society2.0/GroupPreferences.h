#pragma once
#include "MetaString.h"
#include "Policy.h"

class GroupPreferences : public AbstractSerialization
{
public: 
	vector<MetaString* > prefs;
	Policy* clearance; //Permission needed to join/advance/see something etc. 
	
	Policy* AcceptancePolicy(); //Chess players need to play 5 games and rating estimate. //Several people or the dictator would be able to approve. 
								//Closed group - 5 people who want to keep it private. Not rewarded by the EcoSystem 
								//Inform the user about making experiment on him and with what chance he’s first. Like //he can say no place me back to normal trail. And this will reduce the exploration rate of each //group. People can also agree not to be on the bottom but on the top. Like to cut off some //button options. But if there is no bottom - the group will adjust the rate a little bit in order to //survive. 

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

public:
	GroupPreferences();
	~GroupPreferences();
};

