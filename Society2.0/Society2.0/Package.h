#pragma once
#include "Version.h"

class Package
{
	void Update(Version* from, Version* to);

public:
	Package();
	~Package();
};

