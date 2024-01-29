#include <iostream>
#include <string>
#include "Team.h"
#include "Player.h"
#include "Coach.h"
#include "FootballTeam.h"
using namespace std;


void getActivePlayersName(FootballTeam* ft, char ch = 'a')
{

	Player* ply = new Player[ft->getCount()];

	ply = ft->retrievePlayers(ch);
	
	while (ply->getStatus() == ch)
	{
		ply->print();
		ply++;
	}
}
	

	

void printTeamInfo(Team * t)
{
	t->print();
	cout << endl;
}

int main() {
	FootballTeam* manCity = new FootballTeam("Manchester City", "Guardiola", 32, 123, 50);
	FootballTeam * barcelona = new FootballTeam ("Barcelona", "Xavi", 37, 21, 75);

	//1. Create a dynamic object of FootballTeam class with the following values: 
	//"Manchester City", "Guardiola", 32, 123, 50
		//(Team Name, Coach Name, points, Coach ID, Max #Players)
		//2. Create a dynamic object of FootballTeam class with the following values: 
		//"Barcelona", "Xavi", 37, 21, 75
	//	(Team Name, Coach Name, points, Coach ID, Max #Players)
    manCity->addPlayer("Riyad Mahrez", 26, 'a');
	manCity->addPlayer("Julian Alvarez", 19, 'a');
	manCity->addPlayer("Erling Haaland", 9, 'a');
	manCity->addPlayer("Bernardo Silva", 20, 'i');
	manCity->addPlayer("Jack Grealish", 10, 'i');
	manCity->addPlayer("Kevin De Bruyne", 17, 'a');
	manCity->addPlayer("Kyle Walker", 2, 'i');
	barcelona->addPlayer("Marcos Alonso", 17, 'i');
	barcelona->addPlayer("Jordi Alba", 18, 'a');
	barcelona->addPlayer("Eric García", 25, 'a');
	barcelona->addPlayer("Sergio Busquets", 5, 'i');
	barcelona->addPlayer("Frenkie de Jong", 21, 'a');
	barcelona->addPlayer("Ousmane Dembélé", 7, 'a');
	barcelona->addPlayer("Ansu Fati", 10, 'a');
	barcelona->addPlayer("Memphis Depay", 14, 'a');
	int choice;
	do {
		cout << "******************************* Menu * ******************************\n";
			cout << "Enter 1: to add a player.\n"
			<< "Enter 2: to remove a player.\n"
			<< "Enter 3: to update points.\n"
			<< "Enter 4: to display teams points.\n"
			<< "Enter 5: to print the team’s name that has more points.\n"
			<< "Enter 6: to check whether the two teams have the same number of players.\n"
			<< "Enter 7: to display team info (team name, coach and players).\n"
			<< "Enter 8: to display active players.\n"
			<< "Press any Key to EXIT.\n";
		cout << "********************************************************************\n";
		cin >> choice;
		switch (choice) {
			int c;
			//*******************Add Player*******************
		case 1:
		{
			cout << "Enter 1 to add a player to Manchester City, or\n"
				<< "Enter 2 to add a player to Barcelona.\n";
			int num;
			string name;
			char s;
			cin >> c;
			cout << "Enter player name, number and status (a: active or i: inactive) and player name .\n";
			cin >> name >> num >> s;
			switch (c) {
			case 1:
				manCity->addPlayer(name,num,s);
				cout << "Added... " << name << endl << endl;
				break;
			case 2:
				barcelona->addPlayer(name,num,s);
				cout << "Added... " << name << endl << endl;
				break;
			}
			break;
		}
		//*******************Remove Player*******************
		case 2:
		{
			cout << "Enter 1 to remove a player from Manchester City, or\n"
				<< "Enter 2 to remove a player from Barcelona.\n";
			cin >> c;
			int num;
			cout << "\nEnter the player number you want to remove... ";
			cin >> num;
			switch (c) {
			case 1:
				//5. Print the player’s name you want to remove from Man. City team then 
			
				manCity->removePlayer(num);
				
					break;
			case 2:
				//6. Print the player’s name you want to remove from Barcelona team then 
			  barcelona->removePlayer(num) ;
					break;
			}
			break;
		}
		//*******************Update Points*******************
		case 3:
		{
			cout << "Enter 1 to update the points for Manchester City, or\n"
				<< "Enter 2 to update the points for Barcelona.\n";
			cin >> c;
			int p;
			cout << "Enter the new point the Team has earned... ";
			cin >> p;
			if (c == 1) {
				manCity->updatePoints(p);
				cout << "Updated...\n\n";
			}
			else {
				barcelona->updatePoints(p);
				cout << "Updated...\n\n";
			}
			break;
		}
		//*******************Display Points*******************
		case 4:
		{
			cout << "points for: " << endl;
			cout << "Manchesrer City: " << manCity->getNumberOfPoints() << endl;
			cout << "Barcelona: " << barcelona->getNumberOfPoints() << endl;
			break;
		}
		//*******************More Points*******************
		case 5:
		{
			FootballTeam team = manCity->moreNumberOfPoints(barcelona);
			cout << "The team has more points is: "<< team.getTeamName ()<< endl;
			break;
		}
		//*******************Same #Players*******************
		case 6:
		{
			if (*manCity == *barcelona)
			{
				cout << " The two teams have the same number of players ." << endl;
			}
			else
			{
				cout << " The two teams  have not the same number of players ." << endl;
			}
			break;
		}
		//*******************Display Team Info*******************
		case 7:
		{
			cout << "Enter 1 to display Manchester City team info, or\n"
				<< "Enter 2 to display Barcelona team info.\n";
			cin >> c;
			if (c == 1) {
				printTeamInfo(manCity);
				//12. Display Man. City team info.
				cout << endl;
			}
			else {
				printTeamInfo(barcelona);
				//13. Display Barcelona team info.
				cout << endl;
			}
			break;
		}
		case 8:
		{
			cout << "Enter 1 to display active players in Manchester City team, or\n"
				<< "Enter 2 to display active players in Barcelona team.\n";
			cin >> c;

			if (c == 1) {
				getActivePlayersName(manCity, 'a');
				//14. Display player’s id and name of all active players in Man. City team.

				cout << endl;
			}
			else {
				getActivePlayersName(barcelona, 'a');
				//15. Display player’s id and name of all active players in Barcelona team.

				cout << endl;
			}
			break;
		}
		}
} while (choice >= 1 && choice <= 8);
return 0;
}