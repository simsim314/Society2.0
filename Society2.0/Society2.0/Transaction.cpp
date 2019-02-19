#include "Transaction.h"



Transaction::Transaction()
{
}


void Transaction::GeneratePoll()
{
}

void Transaction::Genratetopics()
{
}

void Transaction::MakeSuggestions()
{
}

vector<pair<Group*, Group*>> Transaction::GenerateGroupsOfInterest(float time_expendirture)
{
	return vector<pair<Group*, Group*>>();
}

Transaction::~Transaction()
{
}

string * Transaction::ToString()
{
	string* result = new string("Transaction");
	result->append("@" + this->GroupA_hash);
	result->append("@" + this->GroupB_hash);

	result->append("@" + this->PersonA_hash);
	result->append("@" + this->PersonB_hash);

	result->append("@" + this->transaction_hash);

	return result;
}

int Transaction::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "Transaction")
		return -1;

	int i = num + 1;
	GroupA_hash = db_line[i];
	i++;
	GroupB_hash = db_line[i];
	i++;
	PersonA_hash = db_line[i];
	i++;
	PersonB_hash = db_line[i];
	i++;
	transaction_hash = db_line[i];
	i++;

	return i;

}


