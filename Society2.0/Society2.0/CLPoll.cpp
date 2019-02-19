#include "CLPoll.h"
#include <iostream>

void CLPoll::Show()
{
	vector<MetaControl*> current = navigator->data;

	cout << navigator->Title() << "\n";
	//Text, Input, Button, Information, NdSpaceConfigure 
	int button_count = 0;

	for (int i = 0; i < current.size(); i++)
	{
		if (current[i]->control_type == "Text")
			cout << current[i]->text->data << "\n";
		if (current[i]->control_type == "NdSpaceConfigure")
		{
			cout << current[i]->text->data << "\n";

			for (int j = 0; j < current[i]->switches.size(); j++)
			{
				cout << current[i]->switches[j]->measure->data << "\n insert float between 0 and 1: ";
				float value;
				cin >>  value;
				current[i]->switches[j]->value->data = value;
			}
		}
	}
}

int CLPoll::UserResponse()
{
	next_navigator = navigator->parent;
	while (next_navigator->parent != nullptr)
		next_navigator = next_navigator->parent;
	return -1;
}

CLPoll::CLPoll()
{
}


CLPoll::~CLPoll()
{
}
