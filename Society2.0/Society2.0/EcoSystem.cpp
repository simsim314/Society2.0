#include "EcoSystem.h"

EcoSystem::EcoSystem()
{
}


EcoSystem::~EcoSystem()
{
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

