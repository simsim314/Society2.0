#include "DBManager.h"
#include "PersonalSafety.h"
#include "BasicFunctions.h"
#include "MainFactories.h"

DBManager::DBManager()
{
}

DBManager::~DBManager()
{
}

Person* DBManager::LoadPerson(const string& personal_hash)
{
	return new Person(FromHash(personal_hash));
}

UIGlobalNavigator * DBManager::UIFactory(const string & UI_name)
{
	return UIControlFactory(UI_name);
}

UIGlobalNavigator* DBManager::LoadUI(const string& UI_hash)
{
	vector<string> splitted = split_string(key_to_string[UI_hash], '@');

	UIGlobalNavigator* msw = UIFactory(splitted[0]);
	msw->ProcessString(splitted, 1);
	UIGlobalNavigator::hash_to_UI[UI_hash] = msw;

	return msw;
}

UIGlobalNavigator * DBManager::LoadTop()
{
	return nullptr;
}

bool DBManager::ContainsHash(const string & hash)
{
	return key_to_string.count(hash) > 0;
}

void DBManager::Register(const pair<string, string>& window)
{
		key_to_string[window.first] = window.second;	
}

vector<Policy*> DBManager::FromHash(const string& personal_hash)
{
	PersonalSafety safe = PersonalSafety(personal_hash);
	string key = safe.GetKey(); //Should take time of calculation

	//Sensitive place please make sure not hacked. 
	return LoadDataFromKey(key);
}

vector<Policy*> DBManager::LoadDataFromKey(const string& personal_key)
{
	return vector<Policy*>();
}

string DBManager::KeyFromHash(const string & hash)
{
	return hash; 
}
