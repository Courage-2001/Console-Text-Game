#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "Menu.hpp"

class BattleMenu
{
public:
	void loadBattleMenu(const Enemy::EnemyID& enemyID);
	void displayBattleMenu(const Player& player, const Enemy::EnemyData& enemy);
private:
	Menu menu_;
	Enemy enemy_;
	int selected_option_ = 0;
	bool battle_completed_ = false;
	bool redraw_ = true;
};

