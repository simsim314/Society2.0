#pragma once
#include "EcoSystemSurvival.h"

class EcoSystemViewer
{
	EcoSystemSurvival* survive; 
public:

	//Show four derivatives, of the last week and check out how well the community develops
	vector<MetaString*> ShowGraphs(); 
	vector<MetaString*> WholeGlobeVisualization();
	
	vector<MetaString*>  ShowLocalStats();
	

	EcoSystemViewer();
	~EcoSystemViewer();
};

