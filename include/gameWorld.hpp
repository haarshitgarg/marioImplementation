#include "gameObjects.hpp"
#include <vector>

class World {
    public:
        World();
        ~World();

        std::vector<GameObject>& GetGameObjects();
 
    private:
        std::vector<GameObject> list_of_objects_;
        int current_obj_index;

        void setMap();
};
