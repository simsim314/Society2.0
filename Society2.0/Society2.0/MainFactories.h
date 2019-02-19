#pragma once
#include "UIGlobalNavigator.h"
#include "CLBaseNavigator.h"

UIGlobalNavigator * UIControlFactory(const string & UI_name);
CLBaseNavigator* CLFactory(const string& ui_type);
