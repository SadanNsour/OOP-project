#include "Team.h"
#include "Coach.h"




void Team::setAll(string teamN, string teamC , int Cid)     
{
	teamCoach.setAll(teamC, Cid);
	teamName = teamN;
}

void Team::setTeamName(string teamN)
{
	teamName = teamN;
}

string Team::getTeamName()
{
	return  teamName;
}

Team::Team(string teamN, string teamC, int Cid) :teamCoach (teamC , Cid)
{
	teamName = teamN;
}
