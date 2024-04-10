#ifndef MARIO_PHYSICS_HPP
#define MARIO_PHYSICS_HPP

#include "commonObjects.hpp"
#include "marioObject.hpp"
#include "gameObjects.hpp"
#include <opencv2/core/mat.hpp>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

class MarioPhysics {
    public:
        MarioPhysics(const std::vector<GameObject> list_of_objects);

        ~MarioPhysics();

        void setMarioPosition(MarioObject& mario);

        void UpdateMatrix(const std::vector<GameObject>& gameObject, const location& windowLocation);
    
        cv::Mat PrintMatrix();
    private:
        Matrix matrix;

        std::vector<GameObject> list_of_objects;

        void checkMatrix(MarioObject& mario, location& loc);
};

#endif
