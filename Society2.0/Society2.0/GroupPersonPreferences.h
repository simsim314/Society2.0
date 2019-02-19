#pragma once
class GroupPersonPreferences
{
private: 
	int time_spenditure_preference;
	//How much time to spend in the group min/day. 
	//The group is expecting the person to withhold his promise, change it, or it will charge //from previous rating and contribution

	int participation_motivation_type;
	float ExplorationRate; //Agreeing to try new versions of the app, group etc. 

						   //How much he wants to participate - read news, make suggestion, rate suggestions, 
						   //Community pays community points for this. Some of it comes from the EcoSystem


public:
	GroupPersonPreferences();
	~GroupPersonPreferences();
};

