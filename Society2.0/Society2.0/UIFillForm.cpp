#include "UIFillForm.h"
string* UIFillForm::ToString()
{
	string* str = UIBase::ToString();

	//We need to have logic step by step. If we add in the end this will become a mess. 
	//We need to know first the class we're creating
	str->insert(0, "UIFillForm@");
	return str;
}

string UIFillForm::TypeName()
{
	return "UIFillForm";
}



UIFillForm::UIFillForm()
{
}


UIFillForm::~UIFillForm()
{
}
