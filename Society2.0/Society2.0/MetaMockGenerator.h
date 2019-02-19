#pragma once
#include "MetaString.h"
#include "MetaFloat.h"
#include "MetaControl.h"
#include "MetaSwitch.h"

static MetaString* CreateString(const string& str)
{
	MetaString* ms = new MetaString();
	vector<string> v{ str, "0"};
	ms->ProcessString(v, 0);
	return ms; 
}

static MetaFloat* CreateFloat(float f)
{
	MetaFloat* ms = new MetaFloat();
	vector<string> v{ to_string(f), "0"};
	ms->ProcessString(v, 0);
	return ms;
}

static MetaSwitch* CreateSwitch(const string& str, float f)
{
	MetaSwitch* ms = new MetaSwitch();
	ms->measure = CreateString(str);
	ms->value = CreateFloat(f);

	return ms;
}

//Without switches 
static MetaControl* CreateButtonControl(const string& title, const string& next_hash)
{
	MetaControl* mc = new MetaControl();
	mc->next_hash = new string(next_hash);
	mc->text = CreateString(title);
	mc->control_type = "Button"; 
	return mc; 
}

static MetaControl* CreateInputControl(const string& title)
{
	MetaControl* mc = new MetaControl();
	mc->next_hash = new string("");
	mc->text = CreateString(title);
	mc->control_type = "Input";
	return mc;
}

static MetaControl* CreateInformationControl(const string& title)
{
	MetaControl* mc = new MetaControl();
	mc->next_hash = new string("");
	mc->text = CreateString(title);
	mc->control_type = "Text";
	return mc;
}

//With switches 
static MetaControl* CreateControl(const string& title, const string& next_hash, const string& control_type, const vector<pair<string, float>>& switches)
{
	MetaControl* mc = new MetaControl();
	mc->next_hash = new string(next_hash);
	mc->text = CreateString(title);
	mc->control_type = control_type;

	for(int i = 0; i < switches.size(); i++)
		mc->switches.push_back(CreateSwitch(switches[i].first, switches[i].second));
	
	return mc;
}

//With switches 
static MetaControl* CreateControl(const string& title, const string& next_hash, const string& control_type)
{
	MetaControl* mc = new MetaControl();
	mc->next_hash = new string(next_hash);
	mc->text = CreateString(title);
	mc->control_type = control_type;

	return mc;
}


static UIGlobalNavigator* CreateUINavigator(const vector<string>& names, const vector<string>& hashs, const vector<string>& control_types, const string& hash, const string& title)
{
	UIGlobalNavigator* ms = new UIGlobalNavigator();
	ms->UI_hash = new string(hash);
	ms->title = CreateString(title);

	for (int i = 0; i < names.size(); i++)
		ms->data.push_back(CreateControl(names[i], hashs[i], control_types[i]));

	return ms;
}

static UIGlobalNavigator* CreateUINavigator(const string& hash, const string& title)
{
	UIGlobalNavigator* ms = new UIGlobalNavigator();
	ms->UI_hash = new string(hash);
	ms->title = CreateString(title);

	return ms;
}


