#pragma once
enum class gamestate{
	Homepage,
	CharacterSelect,
	Playing,
	Paused,
	LevelComplete,  // ← new
	GameOver,       // ← new
};