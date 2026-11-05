#pragma once
#include "Menu.hpp"

class World
{
public:
	enum class LocationID {
		STARTING_TOWN,
		ROLLING_PLAINS,
		FOREST
	};

	enum class SubLocationID {
		TOWN_SQUARE,
		BLACKSMITH,
		GENERAL_STORE, 
		OPEN_FIELD
	};

	struct SubLocation {
		SubLocationID id;
		std::string sublocation_name;
	};

	struct Location {
		LocationID id;
		std::string location_name;
		std::string description;
		std::vector<std::string> local_map;
		std::vector<LocationID> connectedLocations;
		std::vector<SubLocation> subLocations;
	};

	World();
	std::vector<std::string> getAvailableDestinations(const LocationID& id) const;
	std::vector<Location> getAllLocations() const;
private:
	std::vector<Location> locations_;
};

