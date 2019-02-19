#pragma once
#include "Group.h"
#include "PyramidPerson.h"
class Pyramid :	public Group
{
public:

	//What is the difference between pyramid and stars? Because for every top there is also some 
	//focus shared with the lower ranks. In pyramid we spread the focus maximally such that 
	//everyone will fill a little bit pharaoh of everyone benief him. But pharaoh due to this will get less 
	//focus yet the focus to pharaoh will be much more commited as he is very very very high in the 
	//hierarchy. The highest it’s humanly possible in any exponential structure. 
	PyramidPerson* lord;
	PyramidPerson* user;
	void GuessTheMasterMoveGame();

	// Lord send infinite up to 10 or 100 or however he defines. 
	//People are living in the order and sending each other this particular God money. 
	//In the pyramid the God is the center. 
	//In community we are switching bottom up - the majority is the center. 
	//The experts can  block suggestions from the crowd. In MoralDemocracy. 
	void SendReward(PyramidPerson* other); 

	void SwapNodes(PyramidPerson* p1, PyramidPerson* p2);
	//Spread the bread ritual - the master takes a bread and gives to two oh his desicples. 
	//They do the same thing, recuresevely. The app registeres the evenet and sends the EcoSystem we’re happy. 
	//We like what happens here. The system is working fine around here. 
	//If it’s not - hmm...send not working fine, say what’s the problem the urgency, importance and send. 
	//If It’s good one we will notice and fix or improve. The system will have your suggestion analyzed. 
	//You can come and talk to people who didn’t like your proposal and they would like to write maybe 
	//something else together. Such that they both would like it. And this way we can move 
	//proposals “by hand” meeting larger and larger groups and represent them using apps. 
	void SpreadTheBread();

	Pyramid();
	~Pyramid();
};

