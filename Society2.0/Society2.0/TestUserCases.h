#pragma once
#include "UserMockGenerator.h"

static int TestPolicy()
{
	Policy* pl = CreatePolicy("Glider Gun");
	if (pl->policies[0]->data != "Glider Gun")
		return -1;

	if (pl->policies.size() != 1)
		return -1;

	return 1;
}

static int TestPolicyToString()
{
	Policy* str = CreatePolicy(vector<string>{"Glider Gun", "Caterloopillar"});
	string temp = *(str->ToString());
	Policy* str1 = new Policy();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	if (str1->policies.size() != 2)
		return -1;

	return 1;
}

static int TestPersonalPreferenceToString()
{
	PersonalPreferences* str = CreatePersonalPreference();
	string temp = *(str->ToString());
	PersonalPreferences* str1 = new PersonalPreferences();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	if (str1->group_priorities.size() != str->group_priorities.size())
		return -1;

	return 1;
}

static int TestPersonToString()
{
	Person* str = CreatePerson("Misha");

	string temp = *(str->ToString());
	Person* str1 = new Person();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int TestRuleToString()
{
	Rule* str = CreateRule("PeeingFine", "Please stop peeing on the streets, this makes the city smell bad");

	string temp = *(str->ToString());
	Rule* str1 = new Rule();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int GroupPreferenceToString()
{
	GroupPreferences* str = CreateGroupPreference();

	string temp = *(str->ToString());
	GroupPreferences* str1 = new GroupPreferences();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int GroupSocialOrderToString()
{
	SocialOrder* str = CreateSocialOrder();

	string temp = *(str->ToString());
	SocialOrder* str1 = new SocialOrder();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int TransactionToString()
{
	Transaction* str = CreateTransaction();

	string temp = *(str->ToString());
	Transaction* str1 = new Transaction();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int MeetingPolicyToString()
{
	MeetingPolicy* str = CreateMeetingPolicy();

	string temp = *(str->ToString());
	MeetingPolicy* str1 = new MeetingPolicy();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int GroupPersonToString()
{
	GroupPerson* str = CreateGrouPerson();

	string temp = *(str->ToString());
	GroupPerson* str1 = new GroupPerson();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}


static int NewsToString()
{
	News* str = CreateNews("Garbage is flowing all over the place");

	string temp = *(str->ToString());
	News* str1 = new News();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int GenesToString()
{
	GroupGene* str = CreateGene("Garbage is flowing all over the place");

	string temp = *(str->ToString());
	GroupGene* str1 = new GroupGene();
	str1->ProcessString(split_string(temp, '@'), 0);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}

static int GroupToString()
{
	Group* str = CreateGroup("Misha");

	string temp = *(str->ToString());
	Group* str1 = new Group();
	str1->ProcessString(split_string(temp, '@'), 0);
	FillGroupByHash(str1);
	string temp1 = *(str1->ToString());

	if (temp != temp1)
		return -1;

	return 1;
}