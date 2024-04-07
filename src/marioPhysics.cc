#include "marioPhysics.hpp"
#include "marioObject.hpp"
#include "commonObjects.hpp"
#include <chrono>
#include <iostream>
#include <ratio>

// Try a way to use the Sparce maritces implementation you have
MarioPhysics::MarioPhysics() {

    for(int i = 0; i<WINDOW_X; i++) {
        std::vector<int> temp;
        for(int j = 0; j<WINDOW_Y; j++) {
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }
}

MarioPhysics::~MarioPhysics() {

}

void MarioPhysics::setMarioPosition(MarioObject& mario) {

    double dt = mario.ElapsedTime();
    if(dt < 100) {
        return;
    }

    mario.ResetTime();
    dt = dt/1000;

    float accel = gravityAccel; 

    Velocity2D currentVel = mario.GetVelocity();
    Velocity2D delta_vel;

    delta_vel.y = accel*dt;
    currentVel.y = currentVel.y + delta_vel.y;


    location currentLoc = mario.GetLocation();
    currentLoc.y = currentLoc.y + currentVel.y * dt;
    currentLoc.x = currentLoc.x + currentVel.x * dt;
    if(currentLoc.y >= 1000) {
        currentLoc.y = 1000;
        currentVel.y = 0;
        
    }
    mario.SetVelocity(currentVel);
    mario.SetLocation(currentLoc);
}

