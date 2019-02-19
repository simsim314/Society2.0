#include "BasicFunctions.h"
#include "MetaFloat.h"



MetaFloat::MetaFloat()
{
}


MetaFloat::~MetaFloat()
{
}

string* MetaFloat::ToString()
{
	string res = to_string(data);
	res += "@" + to_string(meta.size());

	for (int i = 0; i < meta.size(); i++)
		res += "@" + to_string(meta[i]);

	return new string(res);
}

int MetaFloat::ProcessString(const vector<string>& db_line, int num)
{
	data = atof(db_line[num].c_str());

	int size = atoi(db_line[num + 1].c_str());

	for (int i = 0; i < size; i++)
		meta.push_back(atof(db_line[num + 2 + i].c_str()));

	return num + 2 + size;
}


