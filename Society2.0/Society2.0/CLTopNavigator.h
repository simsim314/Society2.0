#pragma once
#include "CLBaseNavigator.h"
class CLTopNavigator :	public CLBaseNavigator
{
protected: 
	CLBaseNavigator* FactoryInterface(UIGlobalNavigator* ui_logic);

public:
	void Init(DBManager* in_db);
	void MainLoop();
	
	CLTopNavigator();
	~CLTopNavigator();
};

