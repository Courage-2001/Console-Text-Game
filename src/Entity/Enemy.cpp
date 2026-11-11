#include "Entity/Enemy.hpp"

Enemy::Enemy() {
	enemy_data_ = 
	{
		{ EnemyID::SLIME, { "Slime", "A slime approaches you, filled with curiosity...", 25, 25, 5, 
		{
			R"(                                              )",
			R"(              __________________              )",
			R"(            _/                  \_            )",
			R"(          _/   / \         / \    \_          )",
			R"(        _/    |  |         |  |     \_        )",
			R"(      _/      |  |         |  |       \_      )",
			R"(    _/         \ /          \ /         \     )",
			R"(   |                                     |    )",
			R"(   |                                     |    )",
			R"(   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|    )",
			R"(                                              )",
			R"(                                              )",
			R"(                                              )",
			R"(                                              )",
			R"(                                              )"
	    } } 
		},

		{ EnemyID::NONE, { "None", "", 0, 0, 0,
		{} } 
		}
	};
}

Enemy::EnemyData Enemy::GetEnemyData(const EnemyID& enemyID) const {
	return enemy_data_.at(enemyID);
}
