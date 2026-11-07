#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"

class BattleMenu
{
public:
	void displayBattleMenu(const Player& player, const Enemy& enemy);
private:
	bool battle_completed_ = false;
	bool redraw_ = true;
};

