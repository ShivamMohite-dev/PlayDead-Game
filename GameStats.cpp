#include "GameStats.h"

GameStats::GameStats() : timeTaken(0.f), projectilesFired(0), projectilesHit(0), enemiesEliminated(0)
{
}

void GameStats::Reset()
{
    timeTaken = 0.f;
    projectilesFired = 0;
    projectilesHit = 0;
    enemiesEliminated = 0;
}