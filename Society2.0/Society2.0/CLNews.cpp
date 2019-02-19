#include "CLNews.h"
#include <iostream>



void CLNews::Show()
{
	vector<string> current = navigator->children_hash;
	cout << navigator->Title() << "\n";

	for (int i = 0; i < current.size(); i++)
	{
		cout << "Choose " << i << " : " << navigator->children_names[current[i]] << "\n";
	}
}

int CLNews::UserResponse()
{
	int idx;
	cin >> idx;
	next_navigator = navigator->NavigateToChild(navigator->children_hash[idx]);
	return -1;
}



CLNews::CLNews()
{
}


CLNews::~CLNews()
{
}
