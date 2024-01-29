#include "Player.h"

void Player::setAll(string pn, int id, char st)
{
	PlayerName = pn;
	PlayerID = id;
	status = st;
}

void Player::setStatus(char st )
{
	status = st;
}

string Player::getPlayerName()
{
	return PlayerName;
}

int Player::getPlayerID()
{
	return PlayerID;
}

char Player::getStatus()
{
	return  status ;
}

Player::Player(string pn, int id , char st)
{
	Player::setAll(pn, id, st);
}

void Player::print()
{
	cout << PlayerID <<" \t " << PlayerName << endl;

}


