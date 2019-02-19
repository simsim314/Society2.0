#include "MetaSwitch.h"
#include "BasicFunctions.h"

//It's obvious that our system would be not optimized to anything. 
//The people who designed it were people of power, they didn't care as long as it worked, and they are in control.
//We are now converging to a very very very bad place relative to what we can be. 
//We needed Galileo to convince people two stones of different weight fall with same speed, obviously there 
//Will be no Galileos in other field and all the time. People will bend to the will of the system, and it will
//Converge to a place which no one wants to be in but they force each other by some rules which are bad for them 
//To be there. Everyone are participating in this "holocost of stupidity" and no one wants to change it because
//They think following the blind man in the front is a good idea, and they used to their place. 
//Not always there is a blind man but many times
//There is who invented capitalism or pyramids to control the population and people don't want 
//Cops comming to their footsteps and arest them, so they obey the stupid stupid very extremely stupid laws thinking 
//This is fine or OK or somehow there was some sort of logic in it but there was a logic 2000 years ago for that stuff. 
//Simplest example monogamy. This is bad model, bad idea, not working at all - people still forced to use it, de facto. 
//Pyramids in the work place another example. The inventor of the idea is not necceserelly the best person to make it 
//Happen in real life. But having a pyramid is the worst idea ever it's just another way of feodalism. We stick to the same
//model in the workplace and this is completelly crazy. People don't even try different models, don't make science about it. 
//Boss is your feodalistic lord who is telling you what to do. 

string* MetaSwitch::ToString()
{
	string* res = measure->ToString();
	FillParam(res, value);
	
	return res;
}

int MetaSwitch::ProcessString(const vector<string>& db_line, int num)
{
	int i = num; 
	i = measure->ProcessString(db_line, i);
	i = value->ProcessString(db_line, i);
	return i; 
}

MetaSwitch::MetaSwitch()
{
	measure = new MetaString();
	value = new MetaFloat();
}


MetaSwitch::~MetaSwitch()
{
}
