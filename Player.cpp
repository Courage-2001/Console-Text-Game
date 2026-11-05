#include "Player.hpp"

Player::Player() {
    currentLocation_ = { World::LocationID::STARTING_TOWN, "PlaceHolder" };
    currentSubLocation_ = { World::SubLocationID::TOWN_SQUARE, "Town Square" };
    current_local_map_ = getCurrentLocationData(World::LocationID::STARTING_TOWN).local_map;
}

Player::Player(const CharacterCreation::PlayerData& playerData) {
    player_ = playerData;
    currentLocation_ = { World::LocationID::STARTING_TOWN, "PlaceHolder" };
    currentSubLocation_ = { World::SubLocationID::TOWN_SQUARE, "Town Square" };
    current_local_map_ = getCurrentLocationData(World::LocationID::STARTING_TOWN).local_map;
}

void Player::setCurrentLocation(World::Location loc) {
    currentLocation_ = loc;
}

void Player::setCurrentSubLocation(World::SubLocation subLoc) {
    currentSubLocation_ = subLoc;
}

void Player::setCurrentLocalMap(World::LocationID locID) {
    current_local_map_ = getCurrentLocationData(locID).local_map;
}

std::vector<std::string> Player::getLocalMap() const {
    return current_local_map_;
}

World::Location Player::getCurrentLocation() const {
    return currentLocation_;
}

World::SubLocation Player::getCurrentSubLocation() const {
    return currentSubLocation_;
}

World::Location Player::getCurrentLocationData(const World::LocationID& currentLocation_) const {
    World world;
    for (auto& location : world.getAllLocations()) {
        if (currentLocation_ == location.locID)
            return location;
    }
}
 
std::vector<std::string> Player::getSubLocationStr(const World::Location& location_data_) const {
    std::vector<std::string> subLocationList;
    for (auto& subLocation : location_data_.subLocations) {
        if (subLocation.subID != currentSubLocation_.subID)
            subLocationList.push_back(subLocation.sublocation_name);
    }
    return subLocationList;
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