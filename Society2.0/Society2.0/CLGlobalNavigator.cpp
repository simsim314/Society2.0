#include "CLGlobalNavigator.h"
#include <iostream>

void CLGlobalNavigator::Show()
{
	vector<MetaControl*> current = navigator->data;
	cout << navigator->Title() << "\n";

	int button_count = 0;

	for (int i = 0; i < current.size(); i++)
	{
		if (current[i]->control_type == "Text")
			cout << current[i]->text->data << "\n";
		if (current[i]->control_type == "Button")
		{
			cout << "Choose " << button_count << " : " << navigator->children_names[*(current[i]->next_hash)] << "\n";
			button_hash.push_back(*(current[i]->next_hash));
			button_count++;
		}
	}
}

int CLGlobalNavigator::UserResponse()
{
	int idx;
	cin >> idx;
	next_navigator = navigator->NavigateToChild(button_hash[idx]);
	return -1;
}

CLGlobalNavigator::CLGlobalNavigator()
{
}


CLGlobalNavigator::~CLGlobalNavigator()
{
}
