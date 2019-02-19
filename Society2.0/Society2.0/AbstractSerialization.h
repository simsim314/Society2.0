#pragma once
#include <string>
#include <vector>
using namespace std;
class AbstractSerialization
{
public:
	virtual string* ToString() = 0;
	virtual int ProcessString(const vector<string>& db_line, int num) = 0;

	AbstractSerialization();
	~AbstractSerialization();
};

