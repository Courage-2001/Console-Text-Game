#pragma once
#include "World.hpp"
#include <algorithm>

class Player {
public:
    Player();
    Player(const std::string& playername);
    void setCurrentLocation(World::LocationID id);
    World::Location getCurrentLocation(const World::LocationID& currentLocation_) const;
    World::LocationID getCurrentLocationID() const;
    World::SubLocationID getSublocationID() const;
    std::string getSubLocation(const World::SubLocationID& currentSubLocation_) const;
private:
    std::string name_;
    World::LocationID currentLocation_;
    World::SubLocationID currentSubLocation_;
};

