#pragma once
#include "Group.h"

//A scenario of dying EcoSystem because two people can’t find a compromise of design. And two EcoSystems are bad. 
class EcoSystemSurvival
{
	//Leacky pyramid for best spreaders. 
	Group* spreaders;
	
	//Leacky pyramid for developers. 
	Group* developers;

	//Leacky pyramid for groups. 
	Group* groups_pyramid;

	vector<float> user_count_time_sequence;
	vector<float> group_count_time_sequence;
	vector<float> traffic_time_sequence; //Transaction in minute
	vector<float> value_generated_time_sequence; //Group optimization function 
											   //improvement; 
	vector<float> how_physical_time_sequence; //only meetings. No skypes included. 
	vector<float> how_virtual_time_sequence; //meeting are virtual as well but also skype. 
	vector<float> action_on_fly_time_sequence; //people make trades in the app. 
	vector<float> action_initiated_bytheapp_time_sequence; //people meet skype/reality by //app suggestions

	//Life like factor
	vector<float> human_personality_score_time_sequence;

	//Growth of traffic and new people. 
	vector<float> CalcDerivative(int n);

	//Make believe it’s alive as it’s alive. But optimize for this belief, make 
	//things that make it feel more alive. Face, pain due to low growth, crying - 
	//Show size as human and baby as small human and old person as very wise and 7G app. Personification. 
	float EstimateLifehood(); 
	
	//Implement the most promising immediately at first 
	//Use expert algorithm to improve survival. 
	void AskExpantionSuggestions();
	
	//If someone moved to your branch give X money if someone is new give X + Y money. 	
	void GiveVersionMoney(Person* user);

public:
	EcoSystemSurvival();
	~EcoSystemSurvival();
};

