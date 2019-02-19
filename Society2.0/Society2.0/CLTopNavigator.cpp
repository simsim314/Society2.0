#include "CLTopNavigator.h"
#include "MainFactories.h"

void CLTopNavigator::Init(DBManager * in_db)
{
	db = in_db;
	UIGlobalNavigator::InitDB(db);
	navigator = db->LoadTop();
	navigator->FillChildren();
}

void CLTopNavigator::MainLoop()
{
	CLBaseNavigator* current = FactoryInterface(navigator);

	while (true)
	{
		current->Show();
		int i = current->UserResponse();

		if (i >= 0)
			current->ApplyResponse(i);
		else
		{
			CLBaseNavigator* next = FactoryInterface(current->next_navigator);
			delete current; 
			current = next; 
		}
	}
}

CLBaseNavigator* CLTopNavigator::FactoryInterface(UIGlobalNavigator * ui_logic)
{
	
	string ui_type = ui_logic->TypeName(); 
	CLBaseNavigator* result = CLFactory(ui_type);
	result->Init(db, ui_logic);

	return result;
}

CLTopNavigator::CLTopNavigator()
{
}


CLTopNavigator::~CLTopNavigator()
{
}
