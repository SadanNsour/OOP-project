#pragma once
#include<iostream>
#include "Coach.h"
#include "Player.h"
using namespace std;
class Team
{
	string teamName;
protected:
    Coach teamCoach;
public :
	void setAll(string, string, int);
	void  setTeamName(string);
	string  getTeamName();
	Team(string, string, int);
	 virtual void  print() = 0;
	

};



 