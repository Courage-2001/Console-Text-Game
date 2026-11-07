#include "Enemy.hpp"

Enemy::Enemy() {
	enemy_name = "";
	max_health = 0;
	current_health = 0;
	damage = 0;
}
Enemy::Enemy(const std::string& enemy_name, int max_health, int current_health, int damage) :
	enemy_name(enemy_name),
	max_health(max_health),
	current_health(current_health),
	damage(damage) {
}
