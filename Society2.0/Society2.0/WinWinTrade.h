#pragma once
#include "CommunityGroup.h"
class WinWinTrade :	public CommunityGroup
{

public:
	Group* WinA;
	Group* WinB;
	
	WinWinTrade();
	~WinWinTrade();
};

