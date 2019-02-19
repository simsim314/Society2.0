#pragma once
#include "CommunicationPerson.h"

class CommunityPerson :	public CommunicationPerson
{
public:

	MetaFloat* contribution;
	MetaFloat* harm;
	MetaFloat* help_time;
	MetaFloat* communication_time;
	MetaFloat* realistic_communication_time;

	CommunityPerson();
	~CommunityPerson();
};

