#pragma once
#include <vector> 
#include <string> 
#include <stdlib.h>
#include <stdio.h>
#include "AbstractSerialization.h"
using namespace std; 

template <class T, class U>
class Meta : public AbstractSerialization
{
public:
	T data;
	vector<U> meta;
	
};
