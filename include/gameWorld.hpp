#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP
#include "gameObjects.hpp"
#include <vector>

class World {
    public:
        World();
        ~World();

        std::vector<GameObject> GetGameObjects();

        void SetXVelocity(int x);
        void SetYVelocity(int y);
        void SetVelocity(Velocity2D vel);

        double DeltaTime();
 
    private:
        std::vector<GameObject> list_of_objects_;
        int current_obj_index;


        std::chrono::time_point<std::chrono::high_resolution_clock> current_time_;

        void setMap();
};

#endif
