#pragma once
#include "UIGlobalNavigator.h"
class UIPoll :public UIGlobalNavigator
{
public:
	UIPoll();
	~UIPoll();

	void Load(const string& full_definition);
	void Save();
	void VisualizeData(MetaString* meta);
	string* NextGuidance(MetaString* current);
	string TypeName();
};

