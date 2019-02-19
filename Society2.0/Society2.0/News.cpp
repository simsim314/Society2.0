#include "News.h"
#include "BasicFunctions.h"

News::News()
{
	importantToGroup = new MetaFloat();
	urgency = new MetaFloat();
	generator_of_news = new Group();
	reporter = new Person();
}

News::~News()
{
	generator_of_news->~Group();
	reporter->~Person();
	delete importantToGroup, urgency, generator_of_news, reporter;
}


string* News::ToString()
{
	string* result = new string("News");
	FillVector<Person>(result, this->conformations);
	FillVectorString(result, this->conformations_hashs);
	FillString(result, &generator_of_news_hash);
	FillParam(result, this->importantToGroup);
	FillVector(result, this->rated_suggestions);
	FillString(result, &reporter_hashs);
	FillParam(result, this->urgency);
	
	FillString(result, &news_hash);

	return result;
}

int News::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "News")
		return -1;

	int i = num + 1;

	i = ProccessVector(conformations, db_line, i);
	i = ProccessVectorString(conformations_hashs, db_line, i);
	i = ProcessTheString(&generator_of_news_hash, db_line, i);
	i = ProccessParam(importantToGroup, db_line, i);
	i = ProccessVector(rated_suggestions, db_line, i);
	i = ProcessTheString(&reporter_hashs, db_line, i);
	i = ProccessParam(urgency, db_line, i);
	i = ProcessTheString(&news_hash, db_line, i);

	return i;
}

MetaFloat * News::EstimateReliability()
{
	return nullptr;
}

MetaFloat * News::EstimateImportance()
{
	return nullptr;
}

MetaFloat * News::EstimatePublishingValue()
{
	return nullptr;
}


