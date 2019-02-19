#pragma once
#include "Group.h"
#include "Person.h"
#include "GroupPerson.h"
#include "Transaction.h"

class ObjectsDB
{

public:
	
	static map<string, Group*> hash_grourps;
	static map<string, Person*> hash_person;
	static map<string, GroupPerson*> hash_groupperson;
	static map<string, Transaction*> hash_transaction;


	ObjectsDB();
	~ObjectsDB();
};

