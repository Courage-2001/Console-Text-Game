#pragma once
#include "World.hpp"
#include "CharacterCreation.hpp"
#include <algorithm>

class Player {
public:
    Player();
    Player(const CharacterCreation::PlayerData& playerData);
    void setCurrentLocation(World::LocationID id);
    void setCurrentSubLocation(World::SubLocationID id);
    void setCurrentLocalMap(World::LocationID id);
    std::vector<std::string> getLocalMap() const;
    World::LocationID getCurrentLocationID() const;
    World::SubLocationID getSublocationID() const;
    World::Location getCurrentLocationData(const World::LocationID& currentLocation_) const;
    std::string getSubLocation(const World::SubLocationID& currentSubLocation_) const;
    std::vector<std::string> generateCharacterSheet() const;
private:
    CharacterCreation::PlayerData player_;
    World::LocationID currentLocationID_;
    World::SubLocationID currentSubLocationID_;
    std::vector<std::string> current_local_map_;
};

