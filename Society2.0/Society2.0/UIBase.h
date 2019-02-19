#pragma once
#include "MetaControl.h"
#include "Person.h"

//Load Save and visualize List of strings. 
//Questions, answers, scores everything, project to some space
class UIBase : public AbstractSerialization
{

public:
	vector<MetaControl*> data;
	string* UI_hash;
	MetaString* title;
	Person* user; 

	UIBase();
	~UIBase();

	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);

	//Project the data in the most meaningful way 
	//after questioning what projection is the most meaningful subjectivelly 
	virtual void Project(MetaString* meta);
	virtual void Load(const string& full_definition);
	virtual void Save();
	virtual void VisualizeData(MetaString* meta);
	virtual string* NextGuidance(MetaString* current);
	virtual string TypeName();
};

