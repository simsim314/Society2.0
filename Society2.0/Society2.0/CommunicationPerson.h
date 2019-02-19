#pragma once
#include "GroupPerson.h"
class CommunicationPerson :	public GroupPerson
{
public:
		  
	//Passer and reciever should be matched for best communication. 
	MetaFloat* passer_of_information_rating; //Here what is important is the speed
	MetaFloat* reciever_of_information_rating; //Here what is important is the speed
	MetaFloat* defending_point_of_view_rating; //Here what is important is not to bend to social pressure

	//People who speak unclearly. Here what's important is people saying yes, this what I ment. 
	MetaFloat* understanding_ill_information_rating; 

	//Finding compromisses and common language.
	MetaFloat* facilitation_rating; 
	
	//Helping to other to find comprommises and common language 
	MetaFloat* facilitation_help_rating; 
	
	//How well are you in teaching the other to find comprommises and common language 
	MetaFloat* facilitation_teaching_rating; 
	
	CommunicationPerson();
	~CommunicationPerson();
};

