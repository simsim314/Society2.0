#pragma once
#include "DBManager.h"
#include "UIGlobalNavigator.h"

class DBManagerMock : public DBManager
{
public:
	
	void LoadEverything(const string& everything);
	UIGlobalNavigator* LoadTop();
	DBManagerMock();
	~DBManagerMock();
};

