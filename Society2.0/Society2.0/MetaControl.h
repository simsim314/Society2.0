#pragma once
#include "MetaFloat.h"
#include "MetaString.h"
#include <vector>
#include "MetaSwitch.h"

class MetaControl : public AbstractSerialization
{
public:
	//Text on the window, with some stats about this text. For example it's popularity, it's influence on EcoSystem etc. 
	MetaString* text;

	//Each text comes with estimations of text/value (with some stats about those values)
	vector<MetaSwitch*> switches; 

	//Reference to other window
	string* next_hash; 

	//Four types: 
	//Text, Input, Button, NdSpaceConfigure, Action 
	//Text is label with information, Input is textbox, Button is button with text and NdSpaceConfigure is Text with N switches. 
	string control_type; 

	//if someinput from the user is returned 
	string input_text; 

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
	
	MetaControl();
	~MetaControl();
};

