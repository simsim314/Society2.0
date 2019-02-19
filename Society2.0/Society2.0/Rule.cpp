#include "Rule.h"
#include "BasicFunctions.h"

void Rule::ApplyRule(Person *)
{
}

string * Rule::ToString()
{
	string* result = new string("Rule");
	result->append("@" + this->status);
	
	FillParam(result, suggestion);

	result->append("@" + this->rule_hash);


	return result;
}

int Rule::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "Rule")
		return -1;
	
	int i = num + 1;
	status = db_line[i];
	i++;

	i = this->suggestion->ProcessString(db_line, i);
	rule_hash = db_line[i];
	i++;

	return i;
}

//I can speak C++ but there is no reason not to troll a bit, in the comments. 
//Comments are completelly made to be shared from people to the people. So why do we
//Use comments only to explain the code and not to spread some ideology? Or for example 
//Have some jokes written all around to make it fun and enjoyable? Why our code looks so boring?
//Also this idea of open code is a joke. Yes I've written here a million lines of unreadable code
//This is completelly open you are welcome to use my code as much as you like. Common man, there is 
//No way in the world anyone will get what you did. It's not really open if you have tons of junk code 
//No one wants or capable to read except of you. This is closed code but the closer is not due to physical limitation
//Because you blocked people from entering, but due to the high cost it requeres to understand it and the low value it provides. 
//Please make "real" open code, even if it's some part of your true code - just to provide high value, and make it readable with comments and stuff. 
//Not unlike the code presented to you here... 
Rule::Rule()
{
	suggestion = new MetaString();
}


Rule::~Rule()
{
}
