#pragma once
class GameStats
{
public:
    GameStats();
    float timeTaken;
    int projectilesFired;
    int projectilesHit;
    int enemiesEliminated;

    float getAccuracy() { return (projectilesFired > 0) ? (projectilesHit / (float)projectilesFired) * 100.f : 0.f; }
    void Reset();
};