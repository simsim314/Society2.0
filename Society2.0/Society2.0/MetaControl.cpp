#include "MetaControl.h"
#include "BasicFunctions.h"

string* MetaControl::ToString()
{
	string* result = text->ToString();
	
	FillVector<MetaSwitch>(result, switches);
	
	result->append("@" + *next_hash);
	result->append("@" + control_type);

	if(input_text == "")
		result->append("@---");
	else
		result->append("@" + input_text);

	return result;
}

int MetaControl::ProcessString(const vector<string>& db_line, int num)
{
	int i = num;
	i = text->ProcessString(db_line, i);
	i = ProccessVector<MetaSwitch>(switches, db_line, i);
	next_hash = new string(db_line[i]);
	i++;
	control_type = db_line[i];
	i++;
	input_text = db_line[i];
	i++;

	if (input_text == "---")
		input_text = ""; 

	return i;
}

MetaControl::MetaControl()
{
	text = new MetaString();
}


MetaControl::~MetaControl()
{
}
