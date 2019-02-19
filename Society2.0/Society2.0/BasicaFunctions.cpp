#include "BasicFunctions.h"

vector<string> split_string(const std::string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

void FillString(string* result, string * val, bool append_first)
{
	if (append_first)
		result->append("@" + *val);
	else
		result->append(*val);
}

int ProcessTheString(string* result, const vector<string>& db_line, int num)
{
	result->clear();
	result->append(db_line[num]);
	return num + 1;
}

void FillVectorString(string* result, const vector<string>& vec, bool append_first)
{
	if (append_first)
		result->append("@" + to_string(vec.size()));
	else
		result->append(to_string(vec.size()));

	for (int i = 0; i < vec.size(); i++)
		result->append("@" + vec[i]);
}

int ProccessVectorString(vector<string>& vec, const vector<string>& db_line, int num)
{

	int size = atoi(db_line[num].c_str());
	int j = num + 1;

	for (int i = 0; i < size; i++)
	{
		vec.push_back(db_line[j]);
		j++;
	}

	return j;
}
