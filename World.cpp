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
			{
				{SubLocationID::RETURN, "Return"},
			}
		}
	};
}

std::vector<std::string> World::getAvailableDestinations(const LocationID& locID) const {
	std::vector<std::string> destinations;
	for (const auto& location : locations_) {
		for (const auto& connectionID : location.connectedLocations) {
			if (connectionID == locID) {
				destinations.push_back(location.location_name);
				break;
			}
		}
	}
	return destinations;
}

std::vector<World::Location> World::getAllLocations() const {
	return locations_;
}
