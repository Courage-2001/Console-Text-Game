#include "World.hpp"

World::World() {
	locations_ =
	{
		{
			LocationID::STARTING_TOWN,
			"PlaceHolder",
			"Where most adventurers begin their journey",
		{
			"+-----------------------------------------+",
			"|                               ____      |",
		  R"(|                              /    \     |)",
			"|                             |   B  |    |",
			"|                             |______|    |",
			"|                                         |",
			"|                 -------                 |",
			"|                |       |                |",
			"|                |   P   |                |",
			"|                |       |                |",
			"|                 -------       ____      |",
		  R"(|                              /    \     |)",
		  R"(|                             /      \    |)",
			"|                            |    G   |   |",
			"|                            |________|   |",
			"|                                         |",
			"+-----------------------------------------+"
		},
			{ LocationID::ROLLING_PLAINS, LocationID::FOREST },
			{
				{ SubLocationID::TOWN_SQUARE, "Town Square" },
				{ SubLocationID::BLACKSMITH , "Blacksmith" },
				{ SubLocationID::GENERAL_STORE, "General Store" },
				{ SubLocationID::RETURN, "Return" }
			}, 
		},

		{
			LocationID::ROLLING_PLAINS,
			"Rolling Plains",
			"The great plains were once kind to the settlers of the land",
			{},
			{ LocationID::STARTING_TOWN },
			{
				{ SubLocationID::OPEN_FIELD, "Open Field" },
				{ SubLocationID::RETURN, "Return" },
			}
		},

		{
			LocationID::FOREST,
			"Forest",
			"Do not venture deep into the forest, as the commoners say...",
			{},
			{ LocationID::STARTING_TOWN },
			{}
		}
	};
}

std::vector<std::string> World::getAvailableDestinations(const LocationID& id) const {
	std::vector<std::string> destinations;
	for (auto& area : locations_) {
		auto it = area.connectedLocations.begin();
		while (it != area.connectedLocations.end()) {
			if (id == *it) {
				destinations.push_back(area.location_name);
			}
			++it;
		}
	}
	return destinations;
}

std::vector<World::Location> World::getAllLocations() const {
	return locations_;
}
