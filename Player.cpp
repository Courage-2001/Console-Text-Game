#include "Player.hpp"

Player::Player() {

}

Player::Player(const std::string& playername) {
    name_ = playername;
    currentLocation_ = World::LocationID::STARTING_TOWN;
    currentSubLocation_ = World::SubLocationID::TOWN_SQUARE;
}

void Player::setCurrentLocation(World::LocationID id) {
    currentLocation_ = id;
}

World::LocationID Player::getCurrentLocationID() const {
    return currentLocation_;
}

World::SubLocationID Player::getSublocationID() const {
    return currentSubLocation_;
}

// need to add check if id is not in world
World::Location Player::getCurrentLocation(const World::LocationID& currentLocation_) const {
    World world;
    for (auto& area : world.getAllLocations()) {
        if (currentLocation_ == area.id)
            return area;
    }
}
 
std::string Player::getSubLocation(const World::SubLocationID& currentSubLocation_) const {
    World world;
    World::Location area = getCurrentLocation(getCurrentLocationID());
    for (auto& subarea : area.subLocations) {
        if (getSublocationID() == subarea.id)
            return subarea.sublocation_name;
    }
}
