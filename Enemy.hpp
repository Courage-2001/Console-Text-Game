#pragma once
#include <string>

class Enemy
{
public: 
	std::string enemy_name;
	int max_health;
	int current_health;
	int damage;

	Enemy();
	Enemy(const std::string& enemy_name, int max_health, int current_health, int damage);
};

