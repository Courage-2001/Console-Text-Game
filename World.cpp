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
				{ SubLocationID::GENERAL_STORE, "General Store" }
			}
		},

		{
			LocationID::ROLLING_PLAINS,
			"Rolling Plains",
			"The great plains were once kind to the settlers of the land",
			{},
			{ LocationID::STARTING_TOWN },
			{}
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

std::vector<World::LocationID> World::getAvailableDestinations(const LocationID& id) const {
	for (auto& area : locations_) {
		if (area.id == id)
			return area.connectedLocations;
	}
	return {};
}

std::vector<World::Location> World::getAllLocations() const {
	return locations_;
}
