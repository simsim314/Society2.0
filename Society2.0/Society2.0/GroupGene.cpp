#include "GroupGene.h"
#include "BasicFunctions.h"

string* GroupGene::ToString()
{
	string* result = new string("GroupGene");
	FillVector(result, this->genes);
	return result; 
}

int GroupGene::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "GroupGene")
		return -1;

	int i = num + 1;
	i = ProccessVector(genes, db_line, i);
	return i; 
}

GroupGene::GroupGene()
{
}


GroupGene::~GroupGene()
{
}
