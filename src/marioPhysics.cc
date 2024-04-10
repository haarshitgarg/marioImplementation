#include <opencv2/opencv.hpp>
#include "marioPhysics.hpp"
#include "marioObject.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <vector>

// Try a way to use the Sparce maritces implementation you have
MarioPhysics::MarioPhysics(const std::vector<GameObject> objects) {

    int count = 0;
    for(int i = 0; i<WINDOW_X; i++) {
        std::vector<int> temp;
        for(int j = 0; j<WINDOW_Y; j++) {
            temp.push_back(0);
            count++;
        }
        matrix.push_back(temp);
    }

    list_of_objects = objects;
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

}

void MarioPhysics::setMarioPosition(MarioObject& mario) {

    double dt = mario.ElapsedTime();
    if(dt < 10) {
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
    checkMatrix(mario, currentLoc);
    if(currentLoc.y >= 850) {
        currentLoc.y = 849;
    }
    mario.SetVelocity(currentVel);
    mario.SetLocation(currentLoc);
}

void MarioPhysics::UpdateMatrix(const std::vector<GameObject>& gameObject, const location& windowLocation) {
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

void MarioPhysics::checkMatrix(MarioObject& mario, location& loc) {

    int start = -1;
    int end = -1;
    for(int i = 0; i<mario.GetSize().length; i++) {
        if(matrix[loc.x + i][loc.y] == 1) {
            if(start == -1) {
                start = i;
            }
            else {
                end = i;
            }
        }
    }
    int delta = end - start;
    if(delta>0) {
        std::cout<<"Delta is : "<<delta<<std::endl;
        if(start>mario.GetSize().length/2) {
            loc.x -= delta+10;
        }
        else if(end<mario.GetSize().length/2) {
            loc.x += delta+10;
        }
    }
}
















