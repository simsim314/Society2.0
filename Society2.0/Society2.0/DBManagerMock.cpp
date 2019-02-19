#include "DBManagerMock.h"
#include "MetaMockGenerator.h"
#include "BasicFunctions.h"
#include "UIGenerator.h"

void DBManagerMock::LoadEverything(const string & everything)
{
	vector<string> vec = split_string(everything, '╔');

	for (int i = 0; i < vec.size(); i += 2)
		key_to_string[vec[i]] = vec[i + 1];
}

UIGlobalNavigator * DBManagerMock::LoadTop()
{
	return LoadUI("EntranceWindow");
}

DBManagerMock::DBManagerMock()
{
	FillKey();
	key_to_string = keydb;

	//Register(GenerateRegisterUI());

	//key_to_string["TopWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"Alone", "Groups", "EcoSystem"}, vector<string>{"AloneWindow", "GroupsWindow", "EcoSystemWindow"}, "TopWindow", "Welcome!")->ToString());
	//key_to_string["TopWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"Alone", "Groups", "EcoSystem"}, vector<string>{"AloneWindow", "GroupsWindow", "EcoSystemWindow"}, "TopWindow", "Welcome!")->ToString());
	//key_to_string["AloneWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"Tamaguchi", "Games"}, vector<string>{"TamaguchiWindow", "GamesWindow"}, "AloneWindow", "Welcome to interactive self!")->ToString());
	//key_to_string["TamaguchiWindow"] = "UIActivity@" + *(CreateUINavigator(vector<string>{"Back to Top"}, vector<string>{"TopWindow"}, "TamaguchiWindow", "Tanaguchi fun!")->ToString());
	//key_to_string["GamesWindow"] = "UINews@" + *(CreateUINavigator(vector<string>{"Back to Top"}, vector<string>{"TopWindow"}, "GamesWindow", "Welcome to Games")->ToString());

	//key_to_string["GroupsWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"A", "B", "C"}, vector<string>{"AWindow", "BWindow", "CWindow"}, "GroupsWindow", "Welcome to Groups!")->ToString());
	//key_to_string["AWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"A_News", "A_Activities", "A_Q&A"}, vector<string>{"A_NewsWindow", "A_ActivitiesWindow", "A_Q&AWindow"}, "AWindow", "Welcome to Group A!")->ToString());
	//key_to_string["BWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"B_News", "B_Activities", "B_Q&A"}, vector<string>{"B_NewsWindow", "B_ActivitiesWindow", "B_Q&AWindow"}, "BWindow", "Welcome to Group B!")->ToString());
	//key_to_string["CWindow"] = "UIGlobalNavigator@" + *(CreateUINavigator(vector<string>{"C_News", "C_Activities", "C_Q&A"}, vector<string>{"C_NewsWindow", "C_ActivitiesWindow", "C_Q&AWindow"}, "CWindow", "Welcome to Group C!")->ToString());
	//key_to_string["A_ActivitiesWindow"] = "UIPoll@" + *(CreateUINavigator(vector<string>{"Meet 1 on 1", "Group meeting"}, vector<string>{"Meeting_window", "Grou_window"}, "A_ActivitiesWindow", "What activity would you prefer?")->ToString());
	//key_to_string["EcoSystemWindow"] = "UISuggestions@" + *(CreateUINavigator(vector<string>{"LifeStatus", "News", "Activities", "Q&A"}, vector<string>{"EcoStatusWindow", "EcoNewsWindow", "EcoActivitiesWindow", "EcoQ&AWindow"}, "EcoSystemWindow", "Welcome to EcoSystem life!")->ToString());

}

DBManagerMock::~DBManagerMock()
{
}
