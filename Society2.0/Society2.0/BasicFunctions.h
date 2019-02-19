#pragma once
#include<vector>
#include<string>
#include <sstream> 
#include <map>
using namespace std;

vector<string> split_string(const std::string& s, char delimiter);

int ProcessTheString(string* result, const vector<string>& db_line, int num);
void FillString(string* result, string* val, bool append_first = true);

void FillVectorString(string* res, const vector<string>& vec, bool append_first = true);
int ProccessVectorString(vector<string>& vec, const vector<string>& db_line, int num);

template <class T>
int ProccessParam(T* val, const vector<string>& db_line, int num)
{
	return val->ProcessString(db_line, num);
}

template <class T>
void FillParam(string* result, T* val, bool append_first = true)
{
	string *str = val->ToString();
	if (append_first)
		result->append("@" + *str);
	else 
		result->append(*str);

	delete str;

}


template <class T>
void FillVector(string* result, const vector<T*>& vec, bool append_first = true)
{
	if (append_first)
		result->append("@" + to_string(vec.size()));
	else
		result->append(to_string(vec.size()));

	for (int i = 0; i < vec.size(); i++)
		FillParam(result, vec[i]);
	
}

template <class T>
int ProccessVector(vector<T*>& vec, const vector<string>& db_line, int num)
{

	int size = atoi(db_line[num].c_str());
	int j = num + 1;

	for (int i = 0; i < size; i++)
	{
		T* x = new T();

		j = x->ProcessString(db_line, j);
		vec.push_back(x);
	}

	return j;
}

template <class U>
void FillFromMap(string* result, const map<string, U*>& mp, bool append_first = true)
{
	if (append_first)
		result->append("@" + to_string(mp.size()));
	else
		result->append(to_string(mp.size()));

	for (auto const& x : mp)
	{
		result->append("@" + x.first);

		FillParam(result, x.second);
	}
}

template <class U>
int ProccessMap(map<string, U*>& mp, const vector<string>& db_line, int num)
{
	int size = atoi(db_line[num].c_str());
	int j = num + 1;
	
	for (int i = 0; i < size; i++)
	{
		string p = db_line[j];
		j++;

		U* x = new U();
		j = x->ProcessString(db_line, j);
		mp[p] = x; 
	}

	return j;
}
