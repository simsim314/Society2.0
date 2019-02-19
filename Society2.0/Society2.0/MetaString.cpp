#include "MetaString.h"
#include "Meta.h"
#include<vector>
#include<string>
#include <sstream> 
using namespace std;

string* MetaString::ToString() {
	string res = data;

	res += "@" + to_string(meta.size());

	for (int i = 0; i < meta.size(); i++)
		res += "@" + to_string(meta[i]);

	return new string(res);
}

int MetaString::ProcessString(const vector<string>& db_line, int num)
{
	data = db_line[num];

	int size = atoi(db_line[num + 1].c_str());

	for (int i = 0; i < size; i++)
		meta.push_back(atof(db_line[num + 2 + i].c_str()));

	return num + 2 + size;
}

MetaString::MetaString()
{
	
}

MetaString::~MetaString()
{
}
