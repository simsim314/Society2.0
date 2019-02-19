#pragma once
#include <string>

class PersonalSafety
{
public:
	PersonalSafety(const std::string& hash_key);
	PersonalSafety();
	std::string GetKey();
	std::string hash; 

	~PersonalSafety();
};

