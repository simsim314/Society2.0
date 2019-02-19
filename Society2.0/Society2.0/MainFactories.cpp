#include "MainFactories.h"
#include "UIActivity.h"
#include "UIPoll.h"
#include "UISuggestions.h"
#include "UINews.h"
#include "CLTopNavigator.h"
#include "CLActivity.h"
#include "CLGlobalNavigator.h"
#include "CLNews.h"
#include "CLPoll.h"
#include "CLSuggestion.h"
#include "CLFillForm.h"
#include "UIFillForm.h"

UIGlobalNavigator * UIControlFactory(const string & UI_name)
{
	if (UI_name == "UIGlobalNavigator")
		return new UIGlobalNavigator();
	if (UI_name == "UIActivity")
		return new UIActivity();
	if (UI_name == "UIPoll")
		return new UIPoll();
	if (UI_name == "UISuggestions")
		return new UISuggestions();
	if (UI_name == "UINews")
		return new UINews();
	if (UI_name == "UIFillForm")
		return new UIFillForm();
}

CLBaseNavigator* CLFactory(const string& ui_type)
{
	if (ui_type == "UIActivity")
		return new CLActivity();
	else if (ui_type == "UIGlobalNavigator")
		return  new CLGlobalNavigator();
	else if (ui_type == "UINews")
		return  new CLNews();
	else if (ui_type == "UIPoll")
		return  new CLPoll();
	else if (ui_type == "UISuggestions")
		return  new CLSuggestion();
	else if (ui_type == "UIFillForm")
		return  new CLFillForm();

}