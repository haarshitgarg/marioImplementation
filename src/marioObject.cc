#include "marioObject.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <ratio>

MarioObject::MarioObject() {
    loc_.x = 50;
    loc_.y = 200;
    size_.length = 150;
    size_.breadth = 200;

    velocity_.x = 0;
    velocity_.y = 0;

    current_time_ = std::chrono::high_resolution_clock::now();

    loadTexture(); 
}

MarioObject::~MarioObject() {
}

location MarioObject::GetLocation() {
    return loc_;
}

void MarioObject::SetLocation(location loc) {
    loc_ = loc;
}

sf::Sprite MarioObject::GetSprite() {
    sf::Sprite sprite;
    sprite.setTexture(texture_);

    sprite.setTextureRect(sf::IntRect(0, 0, size_.length, size_.breadth));
    sprite.setPosition(loc_.x, loc_.y);

    return sprite;
}

void MarioObject::loadTexture() {
    std::string textureName = "wall.png";
    textureName = ROOT_ASSET_DIR + textureName;
    if(!texture_.loadFromFile(textureName)) {
        std::cerr<<"Failed to load: "<<textureName<<std::endl;
    }
    texture_.setRepeated(true);
}

Velocity2D MarioObject::GetVelocity() {
    return velocity_;
}

void MarioObject::SetVelocity(Velocity2D vel) {
    velocity_ = vel;
}

void MarioObject::SetXVelocity(float x) {
    velocity_.x = x;
}

void MarioObject::SetYVelocity(float y) {
    velocity_.y = y;
}

ObjectSize MarioObject::GetSize() {
    return size_;
}

double MarioObject::ElapsedTime() {
    double dt = std::chrono::duration<float , std::milli>(std::chrono::high_resolution_clock::now() - current_time_).count();
    return dt;
}

void MarioObject::ResetTime() {
    current_time_ = std::chrono::high_resolution_clock::now();
}















