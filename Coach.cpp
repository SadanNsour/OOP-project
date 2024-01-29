#include "Coach.h"

void Coach::setAll(string CN, int id)
{
	coachName = CN;
	coachID = id;
}

void Coach::getAll(string& CN, int& id)
{
	CN = coachName;
	id = coachID;
}

Coach::Coach(string CN, int id)
{
	Coach::setAll(CN, id);
}
