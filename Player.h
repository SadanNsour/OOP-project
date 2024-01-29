#pragma once
#include<iostream>
using namespace std;
class Player
{
	string PlayerName;
	int PlayerID;
	char status;
public:
	void setAll(string, int, char);
	void  setStatus(char);
	string  getPlayerName();
	int  getPlayerID();
	char  getStatus();
	Player(string = "", int = 0, char = 'i');
	void   print();

};

