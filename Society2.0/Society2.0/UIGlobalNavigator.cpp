#include "UIGlobalNavigator.h"
#include <set>

map<string, UIGlobalNavigator*> UIGlobalNavigator::hash_to_UI;
DBManager *UIGlobalNavigator::db;

void UIGlobalNavigator::FillChildren()
{
	if (children_hash.size() > 0)
		return; 

	for (int i = 0; i < this->data.size(); i++)
	{
		MetaControl* con = data[i];
		string hash = *(con->next_hash);
		children_hash.push_back(hash);
		children_names[hash] = con->text->data;

		if (UIGlobalNavigator::hash_to_UI.count(hash) == 0)
		{
			if (db->ContainsHash(hash))
			{
				UIGlobalNavigator* cur_ui = db->LoadUI(hash);
				cur_ui->parent = this;
				hash_to_UI[hash] = cur_ui;
			}
			else
			{
				hash_to_UI[hash] = nullptr;
			}
		}
	}
}

UIGlobalNavigator* UIGlobalNavigator::NavigateToChild(const string & hash)
{
	if (UIGlobalNavigator::hash_to_UI.count(hash) == 0)
	{
		if (db->ContainsHash(hash))
		{
			UIGlobalNavigator* cur_ui = db->LoadUI(hash);
			cur_ui->FillChildren();
			hash_to_UI[hash] = cur_ui;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		hash_to_UI[hash]->FillChildren();
	}

	return hash_to_UI[hash];
}

string UIGlobalNavigator::ChildTitle(const string & hash)
{
	if (hash_to_UI[hash] == nullptr)
		return hash; 

	return hash_to_UI[hash]->Title();
}

void UIGlobalNavigator::InitDB(DBManager * in_db)
{
	db = in_db;
}

UIGlobalNavigator::UIGlobalNavigator()
{
	
}


UIGlobalNavigator::~UIGlobalNavigator()
{
}

void UIGlobalNavigator::AddControl(MetaControl *control)
{
	data.push_back(control);
}

string UIGlobalNavigator::Title()
{
	return title->data;
}

string UIGlobalNavigator::TypeName()
{
	return "UIGlobalNavigator";
}
