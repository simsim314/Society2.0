#pragma once
#include "Meta.h"

//This class contains suggestions, rules, ideas, GUI designes XMLS with some metadata about them. 
//The metadata is a vector in infinite universe I mean in very high dimension, because it's a vector<float> 
//Now we know that everything can be presented even this way, but we want to track and pick the most meaningful stuff.
//So for example if I have a general string, I can have statistics about him, how many people prefered him over some other string. 
//So for examples in our application we will not have single string. We will have 10 string, from 10 different suggestions, and we will 
//pass not labels or even meanings but a meta meanings. Depending on the optimization function you have, you will present this or that string, 
//And you will get this or that interpretation to some string. So philosophically speaking, because humans can be placed into some finite numbers,
//we can think about every obkect to be in superposition of states. And althought it might be not the best way to think about quantum computing yet, but it 
//Closes the gap between the single int, single float, no matter what perception of reality, everything is in it basic definitions is somewhat ambigious. Why is it good? 
//So that the expression of almost everything we have will be much larger. So althought people usually don't think about the statistics of every sentece they say, and how it agreed upon 
//But this is something which exist when people talk, and we can measure this agreeaness for example and hold it as metaparemetrs. 
//Yes look think that for computers it's all 0s and 1s. So the computational language is some link inbetween the conscioss language people talk and the 0 and 1 language that machine talks. Someone know how to translate 
//from one another called the compiler. So if you understand having all this terminology around 0s and 1s is important. It's like another place we can place an array of float, a place which makes everything univvesal in some another dimension
//peopel think about, which is this computational language. So we can talk in this way as programmers as well. I mean consiousness is complex and hard, why not to try to solve it throught computing? Computational language of this kind? So this is MetaString. 
class MetaString : public Meta<string, float>
{
public:
	string* ToString();
	int ProcessString(const vector<string>& db_line, int num);
	MetaString();
	~MetaString();
};


