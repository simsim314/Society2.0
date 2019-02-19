#pragma once
#include "UIGlobalNavigator.h"
class UIActivity :	public UIGlobalNavigator
{
public:
	UIActivity();
	~UIActivity();

	string* ToString();
	string TypeName();

	void Load(const string& full_definition);
	void Save();
	void VisualizeData(MetaString* meta);
	string* NextGuidance(MetaString* current);
	
};