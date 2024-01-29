#pragma once
#include<iostream>
using namespace std;
class Coach
{
	string coachName;
	int coachID;
public :
	void setAll(string, int);
	void  getAll(string&, int&);
	Coach(string, int);
};

