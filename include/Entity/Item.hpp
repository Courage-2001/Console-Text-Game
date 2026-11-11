#pragma once
#include <string>
class Item
{
public:
	enum class ItemType {
		NONE,
		WEAPON, 
		ARMOR
	};

	enum class ItemID {
		NONE,
		SWORD,
		WAND,
		LEATHER_ARMOR,
		NOVICE_ROBES

	};

	struct ItemStats {
		int weapon_damage = 0;
		int armor_points = 0;
	};

	ItemType item_type;
	ItemID item_ID;
	std::string item_name;
	ItemStats stats;
	//std::string description;

	Item();
	Item(ItemType item_type, ItemID item_ID, const std::string& item_name, ItemStats stats);
};

