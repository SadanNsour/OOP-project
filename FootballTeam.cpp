#include "FootballTeam.h"
#include"Team.h"
#include "Coach.h"
#include "Player.h"

void FootballTeam::print()
{
	cout << "Team name: " << getTeamName() << endl;
	string cochname;
	int    cochid;
	teamCoach.getAll(cochname, cochid);
	cout << "Team Coach : " << cochname << endl;
	cout << "Players : " << endl;
	for (int i = 0; i < count; i++)
	{
		players[i].print();
		

	}

}

FootballTeam::FootballTeam(string teamN = " ", string teamC = " " ,  int p=0,   int Cid=0, int mx= 0 ) :Team (teamN ,teamC , Cid )
{
	Team::setAll(teamN, teamC, Cid);
	points = p;
	maxPlayers = mx ;
	players = new Player[maxPlayers];
	count =0;
}
FootballTeam::FootballTeam(const FootballTeam& ft) : Team(ft)
{
	this->count = ft.count;
	this->points = ft.points;
	this->maxPlayers = ft.maxPlayers;
	this-> players = new  Player[maxPlayers];
	for (int i = 0; i < count; i++)
	{
		players[i] = ft.players[i];
	}

}

void FootballTeam::updatePoints(int p )
{
	points += p;
}

int FootballTeam::getNumberOfPoints()
{
	return points;
}

int FootballTeam::getCount()
{
	return count;
}

void FootballTeam::addPlayer(string name, int id , char stat)
{
	
	
		if (count == maxPlayers)
		{
			cout << "You exceeded the max number of players." << endl;

		}

		else
		{
			bool f = 0;
			
			while (1) {
				f = 0;
				for (int i = 0; i < count; i++)
				{
					if (id == players[i].getPlayerID()) {
						cout << "Please choose other ID.\n";
						cin >> id;
						f = 1;
						break;
					}
				}
				if (f)continue;
				break;
			}
			players[count++].setAll(name, id,stat);

		}

	}





void FootballTeam::removePlayer(int id )
{
	bool f = 0;
	for (int i = 0; i < count; i++)
	{
		if (players[i].getPlayerID() == id){
			f = 1;
			cout << "Removed..." << players[i].getPlayerName() << endl;
			for (int j = i; j < count - 1; j++)
			{
				players[j] = players[j + 1];
				

			}
			count--;

		}

	}        if (f == 0) {
		cout << "The player is not found in the players list.\n";
	}

}

string FootballTeam::retrievePlayerHasNumber(int  id )
{
	for (int i = 0; i < count; i++)
	{
		if (players[i].getPlayerID() == id)
		{
			return (players[i].getPlayerName());
		}

	}
	return " ";
	
}

Player * FootballTeam::retrievePlayers(char stat) ////// JOOOJO
{
	Player* p = new Player[maxPlayers];
	int c = 0;
	for (int i = 0; i < count; i++)
	{
		if (players[i].getStatus() == stat)
		{
			p[c++] = players[i];
		}
	}
	return p;
}

bool FootballTeam::operator==(FootballTeam& t2) /////
{

		if (t2.count == this->count)
		{
			return true;
		}
		else return false;
}

FootballTeam FootballTeam::moreNumberOfPoints(FootballTeam* t2)
{
	if (this->points > t2->points) return *this;
	else return *t2;

}

FootballTeam::~FootballTeam()
	{
		delete[] players;
	}
