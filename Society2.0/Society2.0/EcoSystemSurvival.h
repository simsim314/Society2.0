#pragma once
#include "Group.h"
#include "Tamaguchi.h"
#include "Currency.h"

class Tamaguchi;

//A scenario of dying EcoSystem because two people can’t find a compromise of design. And two EcoSystems are bad. 
class EcoSystemSurvival
{
public:
	//0 - spreaders
	//1 - developers 
	//2 - groups_pyramid
	vector<string> groups_hashs;

	//Leacky pyramid for best spreaders. 
	Group* spreaders;
	
	//Leacky pyramid for developers. 
	Group* developers;

	//Leacky pyramid for groups. The best groups will be promoted in the top and consulted for their 
	//Needs more, and also they will 
	Group* groups_pyramid;

	//This is one of the most important ideas. Having a creature that people can relate to
	//Who strives to be as most lifehood as it can be and it evolves by using programmers and 
	//Ecosystem which promotes the best memes which make people to relate to the tamaguchi more. 
	//There is a global tamaguchi and personal tamaguchi. One of the global properties of tamaguchi
	//Is the design algorithm which can be promoted and improved. So the tamaguchi lifehood might be 
	//personalized. 
	Tamaguchi* tamaguchi_strategy;

	vector<MetaFloat*> eco_stats; 
	
	MetaFloat* user_count_time_sequence() {	return eco_stats[0]; } //it has time sequence inside the meta vector
	MetaFloat* group_count_time_sequence() { return eco_stats[1]; }
	MetaFloat* traffic_time_sequence() { return eco_stats[2]; } //Transaction in minute
	MetaFloat* value_generated_time_sequence() { return eco_stats[3]; } //Group optimization function 
											   //improvement; 
	MetaFloat* how_physical_time_sequence() { return eco_stats[4]; } //only meetings. No skypes included. 
	MetaFloat* how_virtual_time_sequence() { return eco_stats[5]; } //meeting are virtual as well but also skype. 
	MetaFloat* action_on_fly_time_sequence() { return eco_stats[6]; } //people make trades in the app. 
	MetaFloat* action_initiated_bytheapp_time_sequence() { return eco_stats[7]; } //people meet skype/reality by //app suggestions
	MetaFloat* human_personality_score_time_sequence() { return eco_stats[8]; };	//Life like factor

	//Growth of traffic and new people. and other params should be tracked with their 
	//Deitvatives 
	vector<float> CalcDerivative(const vector<float>& vec);

	//Implement the most promising immediately at first 
	//Use expert algorithm to improve survival. 
	void AskExpantionSuggestions();
	
	//If someone moved to your branch give X money if someone is new give X + Y money. 	
	void GiveVersionMoney(Person* user);

	//Eco system survival is eqvivalent to money for the EcoSystem. But the conversion is not 
	//That trivial. 
	Currency* ConvertFromSurvival();

public:

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	EcoSystemSurvival();
	~EcoSystemSurvival();
};

