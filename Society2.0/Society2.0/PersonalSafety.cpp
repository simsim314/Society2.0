#include "PersonalSafety.h"

PersonalSafety::PersonalSafety()
{
	hash = "";
}


PersonalSafety::PersonalSafety(const std::string& hash_key)
{
	hash = hash_key;
}

std::string PersonalSafety::GetKey()
{
	//Hash to CGOL state
	//CGOL state Evolve N time
	//Generate random next -> Hash
	//Repeat K times such that the battery will be fine, and calculation will be done on the device. 
	std::string key = "01010101000100100010010001";
	return key; 
}

PersonalSafety::~PersonalSafety()
{
}
