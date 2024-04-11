#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "marioPhysics.hpp"
#include "marioObject.hpp"
#include "commonObjects.hpp"
#include <vector>

// Try a way to use the Sparce maritces implementation you have
MarioPhysics::MarioPhysics() {

    // Initialising the matrix to zero
    int count = 0;
    for(int i = 0; i<WINDOW_X; i++) {
        std::vector<int> temp;
        for(int j = 0; j<WINDOW_Y; j++) {
            temp.push_back(0);
            count++;
        }
        matrix.push_back(temp);
    }

    std::vector<GameObject> list_of_objects = world.GetGameObjects();
    for(int i = 0; i<list_of_objects.size(); i++) {
        if(list_of_objects[i].GetLocation().x <WINDOW_X) {

            GameObject object = list_of_objects[i];
            std::cout<<"k: "<<object.GetLocation().x<<std::endl;
            for(int k = object.GetLocation().x; k<std::min(WINDOW_X, object.GetLocation().x + object.GetObjectSize().length); k++) {
                for(int l = object.GetLocation().y; l< std::min(WINDOW_Y, object.GetLocation().y + object.GetObjectSize().breadth); l++) {
                    matrix[k][l] = 1;
                }
            }
        }
    }
}

MarioPhysics::~MarioPhysics() {
    std::cout<<"Ending the Physics"<<std::endl;

}

void MarioPhysics::HandleActions(MarioObject& mario, Actions action) {
    switch (action) {
        case Actions::UP :
            {
                mario.SetYVelocity(-500);
            }
        default:
            {

            }
    
    }
}


cv::Mat MarioPhysics::PrintMatrix() { 
    cv::Mat image(WINDOW_Y, WINDOW_X, CV_8UC1);
    for(int i = 0; i<WINDOW_X; i++) {
        for(int j = 0; j<WINDOW_Y; j++) {
            if(this->matrix[i][j] == 1){
                image.at<uchar>(j, i) = static_cast<uchar>(0);
            }
            else {
                image.at<uchar>(j, i) = static_cast<uchar>(200);
            }
        }
    }

    return image;
}

void MarioPhysics::SetPosition(MarioObject& mario, World& world) {
    
    Velocity2D vel = mario.GetVelocity();
    double dt = mario.DeltaTime();
    if(dt > 50) {
        mario.ResetTime();
        dt = dt/1000;
        vel.y += gravityAccel*dt;
        location loc = mario.GetLocation();

        int dx = vel.x*dt;
        int dy = vel.y*dt;
        loc.y += dy;
        loc.x += dx;

        UpdateLocation(mario, loc, vel);
    }
}

void MarioPhysics::UpdateLocation(MarioObject& mario, location& loc, Velocity2D& vel) {
    std::vector<location> corners(4);
    corners[0].x = loc.x + 30;
    corners[0].y = loc.y + 30;

    int deltaX = 0;
    int deltaY = 0;

    for(int i = 0; i<30; i++) {
        if(matrix[corners[0].x][corners[0].y - i] == 1){
            deltaY = std::max(deltaY, 30-i);
        }
        if(matrix[corners[0].x -i][corners[0].y] == 1) {
            deltaX = std::max(deltaX, 30-i);
        }
    }
    loc.x += deltaX;
    loc.y += deltaY;
    mario.SetLocation(loc);
    if(deltaY != 0) {
        vel.y = 0;
    }
    mario.SetVelocity(vel);

    deltaX = 0;
    deltaY = 0;

    corners[1].x = loc.x + MARIO_LENGTH - 30;
    corners[1].y = loc.y + 30;

    for(int i = 0; i<30; i++) {
        if(matrix[corners[1].x][corners[1].y - i] == 1){
            deltaY = std::max(deltaY, 30-i);
        }
        if(matrix[corners[1].x + i][corners[1].y] == 1) {
            deltaX = std::max(deltaX, 30-i);
        }
    }
    
    loc.x -= deltaX;
    loc.y += deltaY;
    mario.SetLocation(loc);
    if(deltaY != 0) {
        vel.y = 0;
    }
    mario.SetVelocity(vel);

    deltaX = 0;
    deltaY = 0;

    corners[2].x = loc.x + 30;
    corners[2].y = loc.y + MARIO_BREADTH - 30;

    for(int i = 0; i<30; i++) {
        if(matrix[corners[2].x][corners[2].y + i] == 1){
            deltaY = std::max(deltaY, 30-i);
        }
        if(matrix[corners[2].x - i][corners[2].y] == 1) {
            deltaX = std::max(deltaX, 30-i);
        }
    }
    
    loc.x += deltaX;
    loc.y -= deltaY;
    mario.SetLocation(loc);
    if(deltaY != 0) {
        vel.y = 0;
    }
    mario.SetVelocity(vel);

    deltaX = 0;
    deltaY = 0;

    corners[3].x = loc.x + MARIO_LENGTH - 30;
    corners[3].y = loc.y + MARIO_BREADTH - 30;

    for(int i = 0; i<30; i++) {
        if(matrix[corners[3].x][corners[3].y + i] == 1){
            deltaY = std::max(deltaY, 30-i);
        }
        if(matrix[corners[3].x + i][corners[3].y] == 1) {
            deltaX = std::max(deltaX, 30-i);
        }
    }
    
    loc.x -= deltaX;
    loc.y -= deltaY;
    mario.SetLocation(loc);
    if(deltaY != 0) {
        vel.y = 0;
    }
    mario.SetVelocity(vel);
}












