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

        void SetPosition(MarioObject& mario, World& world);

        cv::Mat PrintMatrix();
    private:
        Matrix matrix;
        int max_ds = 0;

        void UpdateLocation(MarioObject& mario, World& world, location& loc, Velocity2D& vel);

        void CheckFrameBounds(MarioObject& mario, location& loc);

        void UpdateMatrix(World& world);
};

#endif
