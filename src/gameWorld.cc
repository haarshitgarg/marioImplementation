#include "gameWorld.hpp"
#include "commonObjects.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

World::World() {
    
    location loc;
    loc.x = WINDOW_X/2;
    loc.y = WINDOW_Y/2;

    std::string mapPath = "map1.json";
    mapPath = ROOT_MAP_DIR + mapPath;
    std::ifstream f(mapPath);
    json data = json::parse(f);

    json object_array = data["Objects"];

    for(int i = 0; i<data["noOfObjects"]; i++) {
        location loc;
        loc.x = object_array[i]["x"];
        loc.y = object_array[i]["y"];

        ObjectSize objSize;
        objSize.length = object_array[i]["length"];
        objSize.breadth = object_array[i]["breadth"];

        GameObject obj(loc, object_array[i]["textureName"], objSize);
        this->list_of_objects_.push_back(obj);

    }

}

World::~World() {
    std::cout<<"Destryoing the WORLD HA HA HA HA HA"<<std::endl;
}

std::vector<GameObject>& World::GetGameObjects() {
    return list_of_objects_;
}

void World::setMap() {
    
}


