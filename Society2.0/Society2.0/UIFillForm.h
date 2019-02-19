#pragma once
#include "UIGlobalNavigator.h"
class UIFillForm : public UIGlobalNavigator
{
public:
	string* ToString();
	string TypeName();

	UIFillForm();
	~UIFillForm();
};

