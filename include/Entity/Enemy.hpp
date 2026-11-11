#pragma once
#include <string>
#include <vector>
#include <map>

class Enemy
{
// need to create enemyID enum, along with struct enemyData and wrap these variables inside the struct (also add std::vec<string> for ascii image)
// need also functions that retrieve enemy based on id and return the enemy data
public: 

	enum class EnemyID {
		SLIME,
		NONE
	};

	struct EnemyData {
		std::string enemy_name;
		std::string enemy_description;
		int max_health;
		int current_health;
		int damage;
		std::vector<std::string> enemy_art;
	};

	Enemy();
	EnemyData GetEnemyData(const EnemyID& enemyID) const;

private:
	std::map<EnemyID, EnemyData> enemy_data_;
};

