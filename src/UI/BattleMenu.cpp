#include "UI/BattleMenu.hpp"

// need to tweak loading screen time, and size of enemy encounter box
// width is going to be an issue, depending on size of art, as well as length of description
void BattleMenu::loadBattleMenu(const Enemy::EnemyID& enemyID) {
	menu_.displayLoadingScreen(2);
	system("cls");
	std::vector<std::string> enemyArt = enemy_.GetEnemyData(enemyID).enemy_art;

	size_t width = 0;
	for (const auto& longestLine : enemyArt) {
		if (longestLine.length() > width) {
			width = longestLine.length();
		}
	}

	std::cout << "+" << std::string(width + 10, '-') << "+\n";

	for (const auto& line : enemyArt) {
		std::cout << "| " << std::left
			<< std::setw(width + 8) << line
			<< " |\n";
	}

	std::cout << "|  " << std::setw(width + 8) << enemy_.GetEnemyData(enemyID).enemy_description << "|\n";
	std::cout << "|" << std::string(width + 10, ' ') << "|\n";
	std::cout << "+" << std::string(width + 10, '-') << "+\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

// need a way to track enemy data when taking damage
void BattleMenu::displayBattleMenu(const Player& player, const Enemy::EnemyData& enemy) {
	while (battle_completed_ == false) {
		if (redraw_ == true) {
			std::vector<std::string> choices = { "Fight", "Run" };
			int firstOption = 0;
			system("cls");

			std::cout << "HP: " << std::to_string(enemy.current_health) << "\n";
			for (const auto& line : enemy.enemy_art) {
				std::cout << line << "\n";
			}
			std::cout << "\n\n";
			std::cout << std::string(40, '-') << "\n";

			for (int index = 0; index < choices.size(); index++)
			{
				if (index == selected_option_)
					std::cout << " > " << choices[index] << '\n';
				else
					std::cout << "   " << choices[index] << '\n';
			}
			Menu::Keyboard input = menu_.getInput();
			menu_.navigateOptions(input, selected_option_, choices.size(), firstOption, redraw_);
			if (input == Menu::Keyboard::Enter) {
				battle_completed_ = true;
			}
		}
	}
	battle_completed_ = false;
}
