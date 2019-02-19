#pragma once
#include "UIBase.h"
#include <map>
#include "DBManager.h"

class DBManager;

class UIGlobalNavigator : public UIBase
{
public:
	UIGlobalNavigator* parent;
	vector<string> children_hash;
	map<string, string> children_names;
	static map<string, UIGlobalNavigator*> hash_to_UI; 
	static DBManager *db; 

public:
	void FillChildren();
	UIGlobalNavigator * NavigateToChild(const string & hash);
	string ChildTitle(const string& hash);

	static void InitDB(DBManager * in_db);

	UIGlobalNavigator();
	~UIGlobalNavigator();

	void AddControl(MetaControl* control);

	string Title();
	string TypeName();
	
};

