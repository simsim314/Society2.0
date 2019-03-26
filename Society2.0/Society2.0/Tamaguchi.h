#pragma once
#include "MetaFloat.h"
#include "Policy.h"
#include "EcoSystemSurvival.h"

//	Suggestion are sent to group designers.
//The group is dead if the users are not flowing in, or start to be less active. As we want to expand 
//and not die or slow our growth we want to learn understand and invent strategies to continue 
//the growth. Experiment with different suggestions and update the gene pool with them to other 
//groups. Beginning and initial boom solutions providing, and special treatment from programmers is to 
//make the EcoSystem survivable. 
//Tamaguchi heart beat. Make visualization of living organism. 
//Make it pet like, the pets want to talk between themselves and you should let it play with other 
//“pet owners” only it cries when it doesn’t spreads. So pet owners compete inside leaky pyramid 
//to be the one who spreads it most as you get poitns, and they can be treated as money in 
//many transaction already agreed between people
//The tamagiuche effect is the outside of each system on the phone. EcoSystem survival is a 
//complex of EcoSystem survival on this phone + EcoSystemSurvival data passed from other Users. 
class Tamaguchi
{
public:
	MetaFloat* personification_score; //How many people treat it as living organism. 
	vector<MetaString*> history_of_usage_and_score; 

	//At every stage the app might start to die off. 
	//Don’t nag the user at first, but try to find the optimal measure for this. 
	//Ask question at first how much does he wants to be alerted about the topic. Some applications //are passive - when I need I want to press button
	//Groups sometimes compatible and can swap some of the genes between themselves and check out if the genes are helping them. Those genes that will spread better and improve the growth better will be suggested more by the system. 
	Policy* AlertingPolicy();

	//At the beginning simple emulation of human mood switches, 
	//later on network that will generate the next emotion to increase global EcoSytemSurvival 
	//params in the long run
	MetaString* EmotionToDisplay(); 
	
	//Manage new people Version money flows like in pyramid.Only if money(Child) > money(Parent) swap child - parent.
	//Parent gets 50 % of all children.Each new person is 1 each person in current version is 0.5.
	//This places the most active spreaders in the top of the EcoSystem. They can see their names //on top of the EcoSystem pyramid. 
	//Eco system will reward programmers for their work as well. Every new person in a branch //written by list of programmers give them 0.01 of the whole pyramid divided by number of programmers. 

	//Manage different policies so that the user will be happy. 
	//Switch user friendliness memes in every transaction. Apply the best memes. 
	Policy* SurvivalStrategyOnPhone();

	//Make believe it’s alive as it’s alive. But optimize for this belief, make 
	//things that make it feel more alive. Face, pain due to low growth, crying - 
	//Show size as human and baby as small human and old person as very wise and 7G app. Personification. 
	MetaFloat* EstimateLifehood();

public:

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	Tamaguchi();
	~Tamaguchi();
};

