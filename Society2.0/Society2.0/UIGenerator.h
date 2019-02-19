#pragma once
#include "MetaMockGenerator.h"

static map<string, string> keydb;

void Registration(UIGlobalNavigator* navigator, const string& name)
{
	keydb[*(navigator->UI_hash)] = name + "@" + *(navigator->ToString());
}

void GenerateRegisterUI()
{
	MetaControl* name = CreateInputControl("Enter your nick name:");
	MetaControl* pass = CreateInputControl("Enter your password:");
	MetaControl* email = CreateInputControl("Enter your email:");
	MetaControl* phone = CreateInputControl("Enter your phone:");
	MetaControl* ok = CreateButtonControl("OK", "EntranceWindow");
	MetaControl* cancel = CreateButtonControl("Cancel", "RegisterWindow");

	UIGlobalNavigator* navigator = CreateUINavigator("RegisterWindow", "Welcome to registration");
	navigator->AddControl(name);
	navigator->AddControl(pass);
	navigator->AddControl(email);
	navigator->AddControl(phone);
	navigator->AddControl(ok);
	navigator->AddControl(cancel);

	return Registration(navigator, "UIFillForm");
}
//MainUI
void GenerateMainUI()
{
	UIGlobalNavigator* navigator = CreateUINavigator("EntranceWindow", "Welcome to Society 2.0");
	navigator->AddControl(CreateInformationControl("Offline"));
	navigator->AddControl(CreateButtonControl("Self Content", "SelfContentWindow"));
	navigator->AddControl(CreateButtonControl("Groups News", "OfflineGroupsWindow"));
	navigator->AddControl(CreateButtonControl("Ecosystem information", "OfflineEcoSystemWindow"));
	navigator->AddControl(CreateInformationControl("Online"));
	navigator->AddControl(CreateButtonControl("Friends", "OnlineIndividualsWindow"));
	navigator->AddControl(CreateButtonControl("Groups", "OnlineGroupsWindow"));
	navigator->AddControl(CreateButtonControl("Ecosystem", "OnlineEcoSystemWindow"));
	navigator->AddControl(CreateInformationControl("Real Life"));
	navigator->AddControl(CreateButtonControl("Friends meetings", "RealLifeIndividualsWindow"));
	navigator->AddControl(CreateButtonControl("Groups meetings", "RealLifeGroupIndividualsWindow"));
	navigator->AddControl(CreateButtonControl("Ecosystem spread", "RealLifeGroupMeetingWindow"));

	return Registration(navigator, "UIGlobalNavigator");
}

//SelfConentUI
void GenerateSelfConentUI()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentWindow", "Welcome! Here you can view at yourself");
	navigator->AddControl(CreateInformationControl("Explore Yourself"));
	navigator->AddControl(CreateButtonControl("Feelings", "SelfContentFeelingsWindow"));
	navigator->AddControl(CreateButtonControl("Thoughts & opinions", "SelfContentThoughtsWindow"));
	navigator->AddControl(CreateButtonControl("Schedule & performance", "SelfContentScheduleWindow"));
	navigator->AddControl(CreateInformationControl("Mind Practices"));
	navigator->AddControl(CreateButtonControl("Being in the now", "SelfContentBeinInNowWindow"));
	navigator->AddControl(CreateButtonControl("Explore your matrix", "SelfContentExploreTheMatrixWindow"));
	navigator->AddControl(CreateButtonControl("Time and being", "SelfConentTimeBeingWindow"));
	navigator->AddControl(CreateInformationControl("Other"));
	navigator->AddControl(CreateButtonControl("Self history", "SelfConentHistoryWindow"));
	navigator->AddControl(CreateButtonControl("Decision Tree", "SelfConentDecisionWindow"));

	return Registration(navigator, "UIGlobalNavigator");
}
//SelfContentFeelUI
void GenerateSelfConentFeelUI()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentFeelingsWindow", "Welcome! Here you will explore your feelings");
	navigator->AddControl(CreateControl("Explore Yourself", "", "NdSpaceConfigure"));
	navigator->data[0]->switches.push_back(CreateSwitch("Anger", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Sadness", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Embarassed", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Happy", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Desire", 0.0));

	return Registration(navigator, "UIPoll");
}

//SelfContentThoughtUI
void GenerateSelfConentThoughtUI()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentThoughtsWindow", "Welcome! Here you will explore your opinions");
	navigator->AddControl(CreateControl("How much do you agree with capitalism", "", "NdSpaceConfigure"));
	navigator->data[0]->switches.push_back(CreateSwitch("Agree", 0.0));
	navigator->AddControl(CreateControl("How much do you like Trump can press the red button", "", "NdSpaceConfigure"));
	navigator->data[1]->switches.push_back(CreateSwitch("Like", 0.0));

	Registration(navigator, "UIPoll");
}

//Schedule 
void GenerateSelfConentSchedule()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentScheduleWindow", "Think about the furure. What will happen in the next:");
	navigator->AddControl(CreateInputControl("Day"));
	navigator->AddControl(CreateInputControl("Month"));
	navigator->AddControl(CreateInputControl("Half year"));
	navigator->AddControl(CreateInputControl("Year"));
	navigator->AddControl(CreateInputControl("Three Year"));
	navigator->AddControl(CreateInputControl("Ten Years"));
	navigator->AddControl(CreateInputControl("Twenty five Years"));
	navigator->AddControl(CreateInputControl("One hundred Years"));

	Registration(navigator, "UIFillForm");
}
//SelfContentBeinInNowWindow
void GenerateSelfContentBeinInNow()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentBeinInNowWindow", "Being in now!");
	navigator->AddControl(CreateControl("Be in a now for one minute", "", "Action"));

	navigator->data[0]->switches.push_back(CreateSwitch("Repeat? ", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Continue? ", 1.0));

	navigator->AddControl(CreateInputControl("How was it? "));
	
	Registration(navigator, "UIActivity");
}

//SelfContentExploreTheMatrixWindow
void GenerateSelfContentExploreTheMatrix()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentExploreTheMatrixWindow", "Explore your internal matrix");
	navigator->AddControl(CreateControl("Do some action - and notice the way your thoughts are directing your actions", "", "Action"));

	navigator->data[0]->switches.push_back(CreateSwitch("Repeat? ", 0.0));
	navigator->data[0]->switches.push_back(CreateSwitch("Continue? ", 1.0));

	navigator->AddControl(CreateInputControl("How was it? "));

	Registration(navigator, "UIActivity");
}

//SelfConentHistoryWindow
void GenerateSelfConentHistory()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfConentHistoryWindow", "Think about the past. How was back then in the past:");
	navigator->AddControl(CreateInputControl("Day"));
	navigator->AddControl(CreateInputControl("Month"));
	navigator->AddControl(CreateInputControl("Half year"));
	navigator->AddControl(CreateInputControl("Year"));
	navigator->AddControl(CreateInputControl("Three Year"));
	navigator->AddControl(CreateInputControl("Ten Years"));
	navigator->AddControl(CreateInputControl("Twenty five Years"));
	navigator->AddControl(CreateInputControl("One hundred Years"));

	Registration(navigator, "UIFillForm");
}


//SelfConentTimeBeingWindow
//SelfConentDecisionWindow


void FillKey()
{
	GenerateMainUI();
	GenerateSelfConentUI();
	GenerateSelfConentFeelUI();
	GenerateSelfConentThoughtUI();
	GenerateSelfConentSchedule();
	GenerateSelfContentBeinInNow();
	GenerateSelfContentExploreTheMatrix();
	GenerateSelfConentHistory();
}

