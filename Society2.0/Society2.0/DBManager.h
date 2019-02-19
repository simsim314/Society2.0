#pragma once
#include "Person.h"
#include "UIGlobalNavigator.h"
class UIGlobalNavigator;

class DBManager
{
public:
	DBManager();
	~DBManager();
	Person* LoadPerson(const string& personal_hash);
	virtual UIGlobalNavigator* LoadUI(const string& UI_hash);
	virtual UIGlobalNavigator* LoadTop();
	bool ContainsHash(const string& hash);
	UIGlobalNavigator* UIFactory(const string& UI_name);
protected:

	void Register(const pair<string, string>& window);
	vector<Policy*> FromHash(const string& personal_hash);
	vector<Policy*> LoadDataFromKey(const string& personal_key);
	map<string, string> key_to_string;
	string KeyFromHash(const string& hash);
};

