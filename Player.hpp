#pragma once
#include "World.hpp"
#include "CharacterCreation.hpp"
#include "Item.hpp"
#include <algorithm>

class Player {
public:
    struct Inventory {
    Item equippedWeapon;
    Item equippedArmor;
    std::vector<Item> inventory_list;

    };

    Player();
    Player(const CharacterCreation::PlayerData& playerData);
    void setCurrentLocation(World::Location loc);
    void setCurrentSubLocation(World::SubLocation subLoc);
    void setCurrentLocalMap(World::LocationID locID);
    std::vector<std::string> getLocalMap() const;
    World::Location getCurrentLocation() const;
    World::SubLocation getCurrentSubLocation() const;
    World::Location getCurrentLocationData(const World::LocationID& currentLocation_) const;
    std::vector<std::string> getSubLocationStr(const World::Location& location_data_) const;
    std::vector<std::string> generateCharacterSheet() const;
private:
    CharacterCreation::PlayerData player_;
    Inventory inventory_;
    World::Location currentLocation_;
    World::SubLocation currentSubLocation_;
    std::vector<std::string> current_local_map_;
};

