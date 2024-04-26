#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP
#include "gameObjects.hpp"
#include <vector>

class World {
    public:
        World();
        ~World();

        std::vector<GameObject>& GetGameObjects();

        void setObjLocations(int x);

    private:
        std::vector<GameObject> list_of_objects_;

};

#endif
