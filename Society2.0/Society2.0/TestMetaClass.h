#pragma once
#include "MetaMockGenerator.h"
#include "BasicFunctions.h"

static int TestMetaString()
{
	MetaString* str = CreateString("Glider Gun");
	if (str->data != "Glider Gun")
		return -1;

	if (str->meta.size() != 0)
		return -1;

	return 1;
}

static int TestMetaStringToString()
{
	MetaString* str = CreateString("Glider Gun");
	string temp = *(str->ToString());
	MetaString* str1 = new MetaString();
	str1->ProcessString(split_string(temp, '@'), 0);

	if (str->data != str1->data)
		return -1;

	if (str->meta.size() != str1->meta.size())
		return -1;

	return 1;
}

static int TestMetaFloat()
{
	MetaFloat* str = CreateFloat(0.5);
	if (str->data != 0.5)
		return -1;

	if (str->meta.size() != 0)
		return -1;

	return 1;
}

static int TestMetaFloatToString()
{
	MetaFloat* str = CreateFloat(0.5);
	string temp = *(str->ToString());
	MetaFloat* str1 = new MetaFloat();
	str1->ProcessString(split_string(temp, '@'), 0);

	if (str->data != str1->data)
		return -1;

	if (str->meta.size() != str1->meta.size())
		return -1;

	return 1;
}

static int TestMetaSwitch()
{
	MetaSwitch* sw = CreateSwitch("ABS", 0.5);

	if (sw->measure->data != "ABS")
		return -1;

	if ((sw->measure->meta).size() != 0)
		return -1;

	if (sw->value->data != 0.5)
		return -1;

	if ((sw->value->meta).size() != 0)
		return -1;

	return 1;
}

static int TestMetaSwitchToString()
{
	MetaSwitch* str = CreateSwitch("ABS", 0.5);
	string temp = *(str->ToString());
	MetaSwitch* str1 = new MetaSwitch();
	str1->ProcessString(split_string(temp, '@'), 0);

	if (str->measure->data != str1->measure->data)
		return -1;

	if (str->value->meta.size() != str1->value->meta.size())
		return -1;

	return 1;
}

static int TestMetaControl()
{
	MetaControl* mc = CreateControl("Tile", "Bugi", "Button");

	if (*(mc->next_hash) != "Bugi")
		return -1;

	if ((mc->switches).size() != 0)
		return -1;

	if (mc->text->data != "Tile")
		return -1;

	return 1;
}

static int ValidateControl(MetaControl* mc, MetaControl* mc1)
{
	if (*(mc->next_hash) != *(mc->next_hash))
		return -1;

	if ((mc->switches).size() != (mc1->switches).size())
		return -1;

	if (mc->text->data != mc1->text->data)
		return -1;

	return 1;
}

static int TestMetaControlToString()
{
	MetaControl* mc = CreateControl("Tile", "Bugi", "Button");

	string temp = *(mc->ToString());
	MetaControl* mc1 = new MetaControl();
	mc1->ProcessString(split_string(temp, '@'), 0);

	return ValidateControl(mc, mc1);
}

static int TestUIGlobalNavigatorToString()
{
	UIGlobalNavigator* mc = CreateUINavigator(vector<string>{"Alone", "Groups", "EcoSystem"}, vector<string>{"AloneWindow", "GroupsWindow", "EcoSystemWindow"}, vector<string>{"Button", "Button", "Button"}, "TopWindow", "Welcome!");

	string temp = *(mc->ToString());
	UIGlobalNavigator* mc1 = new UIGlobalNavigator();
	mc1->ProcessString(split_string(temp, '@'), 0);

	if (mc->data.size() != mc1->data.size())
		return -1;

	if (mc->data.size() != 3)
		return -1; 

	if (ValidateControl(mc->data[0], mc1->data[0]) == -1)
		return -1;

	if (ValidateControl(mc->data[2], mc1->data[2]) == -1)
		return -1;

	return 1;
}

static int TestNavigatorSwitches()
{
	UIGlobalNavigator* navigator = CreateUINavigator("SelfContentThoughtsWindow", "Welcome! Here you will explore your opinions");
	navigator->AddControl(CreateControl("How much do you agree with capitalism?", " ", "NdSpaceConfigure"));
	navigator->data[0]->switches.push_back(CreateSwitch("Agree", 0.0));
	navigator->AddControl(CreateControl("How much do you like Trump can press the red button?", " ", "NdSpaceConfigure"));
	navigator->data[1]->switches.push_back(CreateSwitch("Like", 0.0));
	
	string temp = *(navigator->ToString());
	UIGlobalNavigator* mc1 = new UIGlobalNavigator();
	mc1->ProcessString(split_string(temp, '@'), 0);

	if (navigator->data.size() != mc1->data.size())
		return -1;

	if (mc1->data[0]->switches.size() != 1)
		return -1;

	if (mc1->data[1]->switches.size() != 1)
		return -1;

	return 1;
}