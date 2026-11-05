#include "Player.hpp"

Player::Player() {
    currentLocationID_ = World::LocationID::STARTING_TOWN;
    currentSubLocationID_ = World::SubLocationID::TOWN_SQUARE;
    current_local_map_ = getCurrentLocationData(currentLocationID_).local_map;
}

Player::Player(const CharacterCreation::PlayerData& playerData) {
    player_ = playerData;
    currentLocationID_ = World::LocationID::STARTING_TOWN;
    currentSubLocationID_ = World::SubLocationID::TOWN_SQUARE;
    current_local_map_ = getCurrentLocationData(currentLocationID_).local_map;
}

void Player::setCurrentLocation(World::LocationID id) {
    currentLocationID_ = id;
}

void Player::setCurrentSubLocation(World::SubLocationID id) {
    currentSubLocationID_ = id;
}

void Player::setCurrentLocalMap(World::LocationID id) {
    current_local_map_ = getCurrentLocationData(id).local_map;
}

std::vector<std::string> Player::getLocalMap() const {
    return current_local_map_;
}

World::LocationID Player::getCurrentLocationID() const {
    return currentLocationID_;
}

World::SubLocationID Player::getSublocationID() const {
    return currentSubLocationID_;
}

// need to add check if id is not in world
World::Location Player::getCurrentLocationData(const World::LocationID& currentLocation_) const {
    World world;
    for (auto& area : world.getAllLocations()) {
        if (currentLocation_ == area.id)
            return area;
    }
}
 
std::string Player::getSubLocation(const World::SubLocationID& currentSubLocation_) const {
    World world;
    World::Location area = getCurrentLocationData(currentLocationID_);
    for (auto& subarea : area.subLocations) {
        if (getSublocationID() == subarea.id)
            return subarea.sublocation_name;
    }
    return "Null";
}

std::vector<std::string> Player::generateCharacterSheet() const {
    std::string traits;
    for (auto i : player_.traits) {
        traits = traits + i + ", ";
    }
    return {
        "Name: " + player_.name,
        "Class: " + player_.characterClass,
        "Traits: " + traits,
        "Health: " + std::to_string(player_.health),
        "Strength: " + std::to_string(player_.strength),
        "Intelligence: " + std::to_string(player_.intelligence),
    };
}