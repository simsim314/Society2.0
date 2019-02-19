#include "UIBase.h"
#include "MetaControl.h"
#include "BasicFunctions.h"

UIBase::UIBase()
{
	title = new MetaString();
}

UIBase::~UIBase()
{
}

string* UIBase::ToString()
{	
	string* result = new string();
	FillVector<MetaControl>(result, data, false);
	result->append("@" + *UI_hash);
	FillParam(result, title);

	return result;
}

int UIBase::ProcessString(const vector<string>& db_line, int num)
{
	int i = num;
	i = ProccessVector<MetaControl>(data, db_line, i);
	UI_hash = new string(db_line[i]);
	i = title->ProcessString(db_line, i+1);

	return i;
}

void UIBase::Project(MetaString * meta)
{
}

void UIBase::Load(const string & full_definition)
{
}

void UIBase::Save()
{
}

void UIBase::VisualizeData(MetaString * meta)
{
}

string * UIBase::NextGuidance(MetaString * current)
{
	return nullptr;
}

string UIBase::TypeName()
{
	return "UIBase";
}
