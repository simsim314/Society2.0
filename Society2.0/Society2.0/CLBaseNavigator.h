#pragma once
#include "DBManager.h"

class CLBaseNavigator
{
public:
	DBManager* db;
	UIGlobalNavigator* navigator;
	UIGlobalNavigator* next_navigator;

	void Init(DBManager* in_db, UIGlobalNavigator* navigator);
	virtual void Show(); 

	//User Response -1 is expecting next_navigator to be filled with data already
	virtual int UserResponse(); 

	virtual void ApplyResponse(int idx);

	CLBaseNavigator();
	~CLBaseNavigator();
};

