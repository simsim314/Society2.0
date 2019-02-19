#include "CLActivity.h"
#include <iostream>

void CLActivity::Show()
{
	vector<MetaControl*> current = navigator->data;

	cout << navigator->Title() << "\n";
	//Text, Input, Button, Information, NdSpaceConfigure 
	int button_count = 0;

	int i = 0; 
	for (int i = 0; i < current.size(); i++)

	do
	{
		if (current[i]->control_type == "Text")
		{
			cout << current[i]->text->data << "\n";
			i++;
		}
		else if (current[i]->control_type == "NdSpaceConfigure")
		{
			cout << current[i]->text->data << "\n";

			for (int j = 0; j < current[i]->switches.size(); j++)
			{
				cout << current[i]->switches[j]->measure->data << "\n insert float between 0 and 1: ";
				float value;
				cin >> value;
				current[i]->switches[j]->value->data = value;
			}
			i++;
		}
		if (current[i]->control_type == "Input")
		{
			cout << current[i]->text->data << "\n";
			string value;
			cin >> value;

			current[i]->input_text = value;
			i++;
		}
		else if (current[i]->control_type == "Action")
		{
			cout << current[i]->text->data << "\n";
			int option;
			cin >> option;

			for (int j = 0; j < current[i]->switches.size(); j++)
			{
				int n = (int)(current[i]->switches[j]->value->data + 0.5);
				cout << "Option " << j << ": " << current[i]->switches[j]->measure->data << " - " << current[n]->text->data << "\n";
			}

			
			cin >> option;

			i = (int)(current[i]->switches[option]->value->data + 0.5);
		}

	} while (i < current.size());
}

int CLActivity::UserResponse()
{
	next_navigator = navigator->parent;
	while (next_navigator->parent != nullptr)
		next_navigator = next_navigator->parent;
	return -1;
}

CLActivity::CLActivity()
{
}


CLActivity::~CLActivity()
{
}
