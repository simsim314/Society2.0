#include "CLFillForm.h"
#include <iostream>
void CLFillForm::Show()
{
	vector<MetaControl*> current = navigator->data;

	cout << navigator->Title() << "\n";
	//Text, Input, Button, Information, NdSpaceConfigure 
	int button_count = 0; 

	for (int i = 0; i < current.size(); i++)
	{
		if(current[i]->control_type == "Text")
			cout << current[i]->text->data << "\n";
		if (current[i]->control_type == "Input")
		{
			cout << current[i]->text->data << "\n";
			string value;
			cin >> value;
			
			current[i]->input_text = value; 
		}
		if (current[i]->control_type == "Button")
		{
			cout << "Choose " << button_count << " : " << navigator->children_names[*(current[i]->next_hash)] << "\n";
			button_hash.push_back(*(current[i]->next_hash));
			button_count++;
		}
	}
}

int CLFillForm::UserResponse()
{
	int idx;
	cin >> idx;
	next_navigator = navigator->NavigateToChild(button_hash[idx]);
	return -1;
}

CLFillForm::CLFillForm()
{
}


CLFillForm::~CLFillForm()
{
}
