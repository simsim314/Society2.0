#include "CLBaseNavigator.h"



void CLBaseNavigator::Init(DBManager * in_db, UIGlobalNavigator * in_navigator)
{
	db = in_db;
	navigator = in_navigator;
}

void CLBaseNavigator::Show()
{
}

int CLBaseNavigator::UserResponse()
{
	return 0;
}

void CLBaseNavigator::ApplyResponse(int idx)
{
}

CLBaseNavigator::CLBaseNavigator()
{
}

CLBaseNavigator::~CLBaseNavigator()
{
}
