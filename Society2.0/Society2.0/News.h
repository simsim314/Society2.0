#pragma once
#include "Group.h"
#include "MetaFloat.h"
#include "MetaString.h"

//The coding paradigm is stucked. This is obvious that we're doing by hand much 
//more than we should. People should record and quantify and qualify the actions programmers 
//Usualy do, and make it automatic. There is still need for people to program, 
//But I'm doing the same thing over and over again, and there is no reason for that. 
//I want to say Class A connect to class B in way C and the code underneath it is runnning 
//Already. I want visual programming language that will guess well what I mean. It will compile 
//And make unit tests all the time automatically. I just want to see the visual representation,
//And say hey the system is not doing something correct - lets fix it. Obviously in society 2.0
//We say hey look the system is doing something wrong and I raise a flag, we show to random 
//People this note, and people say oho this is important - we use several loop like that with 
//More and more bigger crowd until the news reach the headlines. Those news will be the most 
//Important news objectivelly to many subjects. We will also add the news which are objectivelly, 
//Effecting the life of EcoSystem and personal news per group in which you are in. If the system 
//Is making mistakes we make a hot fix for the system. 
//The speed of response of the system is dependant on user base. For example if we have 10 people
//Using the app 1hr a week than the information is passing very slowly. Unlike if we have 10 million 
//People sharing information among themselves all the time, the accuracy in time and being in real time
//Is improving drastically. I mean it will take milliseconds for important news to travel from one place 
//To another, including discovering the important news, and I mean news people think are important not using 
//The system which begs for focus. This is obvious noise just like trolls on the internet. We need a better 
//system not based on who screams the most but who is really making important things to humanity and it will 
//be masurable. At least some people will estimate it better than others, and the estimators of importance,
//Will have their own group, and their weight in news generatiion will be higher. 
class News
{
public:
	string news_hash; 
	vector<MetaString*> rated_suggestions;
	Group* generator_of_news;
	Person* reporter;
	vector<Person*> conformations;

	string generator_of_news_hash; 
	string reporter_hashs;
	vector<string> conformations_hashs;

	//Urgent news are spread faster 
	MetaFloat* urgency;
	
	//Important to public. Important spread slower but less rigorous test if importance 9/10               	
	//then skip the 100, 1000, 10K try 100K
	MetaFloat* importantToGroup;

public:
	News();
	~News();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	MetaFloat* EstimateReliability();
	MetaFloat* EstimateImportance();
	MetaFloat* EstimatePublishingValue();

};