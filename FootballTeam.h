#pragma once
#include "Team.h"
#include "Player.h"
#include<iostream>
#include "Coach.h"
#include "Team.h"
using namespace std;

class FootballTeam :
    public Team
{
    Player* players = new Player[maxPlayers];
    int points;
    int count;
    int maxPlayers;
    void print();
public :
    FootballTeam( string , string , int , int , int );

    FootballTeam(const FootballTeam&);
    void  updatePoints(int);
    int getNumberOfPoints();
    int  getCount();
    void addPlayer(string, int, char);
    void  removePlayer(int);
    string retrievePlayerHasNumber(int);
    Player* retrievePlayers(char);
    bool operator==(FootballTeam&);
    FootballTeam  moreNumberOfPoints(FootballTeam*);
    ~FootballTeam();

     
};

