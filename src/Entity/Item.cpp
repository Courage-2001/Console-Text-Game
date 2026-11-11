#include "Entity/Item.hpp"

Item::Item() {
    item_type = ItemType::NONE;
    item_ID = ItemID::NONE;
    item_name = "";
    stats = { 0, 0 };
}

Item::Item(ItemType item_type, ItemID item_ID, const std::string& item_name, ItemStats stats) :
    item_type(item_type),
    item_ID(item_ID),
    item_name(item_name),
    stats(stats) { 
}