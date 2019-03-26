#pragma once
#include <string>
#include <vector>
#include "MetaString.h"
#include "MetaFloat.h"

using namespace std; 

class Version
{
public: 
	string version_hash; 

	MetaString* version_name;
	
	Version* parent;
	vector<Version*> children;
	
	vector<MetaFloat*> userUsageStats; 
	vector<MetaFloat*> globalUsageStats;

public:
	Version();
	~Version();
};

