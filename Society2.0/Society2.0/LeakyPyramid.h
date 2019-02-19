#pragma once
#include "Pyramid.h"

//The idea in which if some branch is forced and has better quality then it will attract more 
//attention and more people will go to the place which provides better master. And the old place 
//will either die or improve or someone from the other branch will take that branch. 

//The status changes automatically by value. 
//If User.Parent.val < User.val, swap(user, user.Parent). 

//Anyone can ask from anyone else to switch places. I mean from time to time. Not to swap all the time. 
//Like once a month. This creates dynamics where people are actually good on the top of any 
//skill and they direct the skill very proffetiently. 
//Like giving kasparov to lead in chess to make good chess players. This for any skill. Giving bonuses. 
class LeakyPyramid : public Pyramid
{
public:
	LeakyPyramid();
	~LeakyPyramid();
};

