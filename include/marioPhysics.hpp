#ifndef MARIO_PHYSICS_HPP
#define MARIO_PHYSICS_HPP

#include "gameWorld.hpp"
#include "marioObject.hpp"
#include <opencv2/core/mat.hpp>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

enum Actions {
    UP = 0,
    DOWN,
    RIGHT,
    LEFT,
    JUMP
};

class MarioPhysics {
    public:
        MarioPhysics();
        ~MarioPhysics();

        void UpdateMatrix();
        void HandleActions(MarioObject& mario, Actions action);

        void SetPosition(MarioObject& mario, World& world);

        cv::Mat PrintMatrix();
    private:
        Matrix matrix;
        World world;
        int max_ds = 0;

        void UpdateLocation(MarioObject& mario, location& loc, Velocity2D& vel);
};

#endif
