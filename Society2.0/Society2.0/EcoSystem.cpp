#include "EcoSystem.h"
#include "BasicFunctions.h"

EcoSystem::EcoSystem()
{
	this->branching_factor = new MetaFloat();
	this->global_eco = new EcoSystemSurvival();
	this->local_eco = new EcoSystemSurvival();
	this->user = new Person();
	this->v_tree = new Version();
}

EcoSystem::~EcoSystem()
{
	global_eco->~EcoSystemSurvival();
	local_eco->~EcoSystemSurvival();
	user->~Person();
	v_tree->~Version();

	delete
	branching_factor,
	global_eco,
	local_eco,
	user,
	v_tree;
}

string * EcoSystem::ToString()
{
	string* result = new string("EcoSystem");

	FillVectorString(result, this->all_groups_hashs);
	FillVectorString(result, this->all_transactions_hashs);
	FillVector(result, this->black_list_ids);
	FillParam(result, this->branching_factor);
	FillVector(result, this->globalUsageStats);
	FillParam(result, this->global_eco);
	FillParam(result, this->local_eco);
	FillVectorString(result, this->others_hash);
	FillVector(result, this->userUsageStats);
	FillString(result, &user_hash);
	FillString(result, &v_tree_hash);
	FillString(result, &eco_hash);

	return result;

}

int EcoSystem::ProcessString(const vector<string>& db_line, int num)
{
	if (db_line[num] != "EcoSystem")
		return -1;

	int i = num + 1;
	i = ProccessVectorString(this->all_groups_hashs, db_line, i);
	i = ProccessVectorString(this->all_transactions_hashs, db_line, i);
	i = ProccessVector(this->black_list_ids, db_line, i);
	i = ProccessParam(this->branching_factor, db_line, i);
	i = ProccessVector(this->globalUsageStats, db_line, i);
	i = ProccessParam(this->global_eco, db_line, i);
	i = ProccessParam(this->local_eco, db_line, i);
	i = ProccessVectorString(this->others_hash, db_line, i);
	i = ProccessVector(this->userUsageStats, db_line, i);
	i = ProcessTheString(&user_hash, db_line, i);
	i = ProcessTheString(&v_tree_hash, db_line, i);
	i = ProcessTheString(&eco_hash, db_line, i);

	return i; 

}

void EcoSystem::InitHashs()
{
	if (this->user != nullptr)
		user_hash = user->person_hash;

	this->all_groups_hashs.clear();
	this->others_hash.clear();
	this->all_transactions_hashs.clear();

	for (int i = 0; i < this->all_groups.size(); i++)
		all_groups_hashs.push_back(this->all_groups[i]->group_hash);

	for (int i = 0; i < this->all_transactions.size(); i++)
		all_transactions_hashs.push_back(this->all_transactions[i]->transaction_hash);

	for (int i = 0; i < this->others.size(); i++)
		others_hash.push_back(this->others[i]->eco_hash);
}

Person* EcoSystem::LoadPersonalData(const string& MAC_Pass)
{
	return db->LoadPerson(MAC_Pass);
}

void EcoSystem::RegisterTransaction(Transaction * eco)
{
}

void EcoSystem::RegisterNewMember(Person * p)
{
}

void EcoSystem::OptimizeGeneSpread()
{
}

Policy * EcoSystem::ActionSurvivalPolicy()
{
	return nullptr;
}

Policy * EcoSystem::SuggestMeetingsToPerson()
{
	return nullptr;
}

void EcoSystem::Merge(EcoSystem * other_person)
{
}

vector<MetaString*> EcoSystem::VersionsForward()
{
	return vector<MetaString*>();
}

void EcoSystem::TravelForward(const int & branch)
{
}

void EcoSystem::TravelBackward()
{
}

