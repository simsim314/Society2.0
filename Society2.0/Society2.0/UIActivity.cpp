#include "UIActivity.h"



UIActivity::UIActivity()
{
}


UIActivity::~UIActivity()
{
}

string* UIActivity::ToString()
{
	string* str = UIBase::ToString();

	//We need to have logic step by step. If we add in the end this will become a mess. 
	//We need to know first the class we're creating
	str->insert(0, "UIActivity@");

	return str;
}

string UIActivity::TypeName()
{
	return "UIActivity";
}

void UIActivity::Load(const string & full_definition)
{
}

void UIActivity::Save()
{
}

void UIActivity::VisualizeData(MetaString * meta)
{
}

string * UIActivity::NextGuidance(MetaString * current)
{
	return nullptr;
}

