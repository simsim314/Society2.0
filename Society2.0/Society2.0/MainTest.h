#pragma once
#include "TestMetaClass.h"
#include "TestUserCases.h"

#include <iostream>
using namespace std; 

void AssertTest(const string& test_name, int(*test_case)())
{
	if(test_case() == 1)
		cout << test_name << " SUCCESS\n";
	else 
		cout << "\n" << test_name << " Fail!!!!\n\n";
}
//When I was 18 no one asked me if I like the current society. Like if you ask me 
//How do I dare to code morality and society? My answer is that it's already coded, 
//By very stupid people 2500 years ago (for that period they were extremelly smart). 
//So when I was 18 no one suggested me some alternatives, no one showed me some different
//Moral paths. You empose yourself on me like a leach. You want to play by your rules, 
//How moral is that? How moral is to empose your views and concepts on a person without his 
//Permission and his acceptance? This is force. This is violance, this is a crime. Like 
//in Rick & Morty it's not slavery if it's not society - well this is slavery, modern slavery. 
//And it will continue to work and inslaves us until we will raise from the dashes, and say 
//To society: ENOUGH! of this complete bulshit. You can play by whatewer stupid 
//Rules you want, I don't see any reason as rational free man to play by your rules. Obviously
//This is why we need Society 2.0. Please also check out the solution of Scott Alexander Archipelago. 
//This is very simple idea, but it's the real moral solution to current humanity problems. 
//At least a beginning of the solution. I say Hello to the 21st century revolution. 
//I hope you (the reader) will join me. 

static void TestingSerialization()
{
	AssertTest("TestMetaString", TestMetaString);
	AssertTest("TestMetaStringToString", TestMetaStringToString);
	AssertTest("TestMetaFloat", TestMetaFloat);
	AssertTest("TestMetaFloatToString", TestMetaFloatToString);
	AssertTest("TestMetaSwitch", TestMetaSwitch);
	AssertTest("TestMetaSwitchToString", TestMetaSwitchToString);
	AssertTest("TestMetaControlToString", TestMetaControlToString);
	AssertTest("TestMetaControl", TestMetaControl);
	AssertTest("TestUIGlobalNavigatorToString", TestUIGlobalNavigatorToString);
	AssertTest("TestNavigatorSwitches", TestNavigatorSwitches);
	AssertTest("TestPolicy", TestPolicy);
	AssertTest("TestPolicyToString", TestPolicyToString);
	AssertTest("TestPersonalPreferenceToString", TestPersonalPreferenceToString);
	AssertTest("TestPersonToString", TestPersonToString);
	AssertTest("TestRuleToString", TestRuleToString);
	AssertTest("GroupPreferenceToString", GroupPreferenceToString);
	AssertTest("GroupSocialOrderToString", GroupSocialOrderToString);
	AssertTest("TransactionToString", TransactionToString);
	AssertTest("MeetingPolicyToString", MeetingPolicyToString);
	AssertTest("GroupPersonToString", GroupPersonToString);
	AssertTest("NewsToString", NewsToString);
	AssertTest("GenesToString", GenesToString);
	AssertTest("GroupToString", GroupToString);
	AssertTest("TamaguchiToString", TamaguchiToString);
	AssertTest("EcoSystemSurvivalToString", EcoSystemSurvivalToString);
	AssertTest("EcoSystemToString", EcoSystemToString);
	
}

static void Testing()
{
	TestingSerialization();
}
