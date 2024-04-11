#include "marioObject.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <ratio>


MarioObject::MarioObject() {
    loc_.x = MARIO_INITIAL_X;
    loc_.y = MARIO_INITIAL_Y;
    size_.length = MARIO_LENGTH;
    size_.breadth = MARIO_BREADTH;

    velocity_.x = 0;
    velocity_.y = 0;

    current_time_ = std::chrono::high_resolution_clock::now();

    loadTexture(); 
}

MarioObject::~MarioObject() {

}

void MarioObject::loadTexture() {
    std::string textureName = MARIO_TEXTURE_NAME;
    textureName = ROOT_ASSET_DIR + textureName;
    if(!texture_.loadFromFile(textureName)) {
        std::cerr<<"Failed to load: "<<textureName<<std::endl;
    }
    texture_.setRepeated(true);
}

sf::Sprite MarioObject::GetSprite() const{
    sf::Sprite sprite;
    sprite.setTexture(texture_);

    sprite.setTextureRect(sf::IntRect(0, 0, size_.length, size_.breadth));
    sprite.setPosition(loc_.x, loc_.y);

    return sprite;
}

ObjectSize MarioObject::GetSize() const {
    return size_;
}

location MarioObject::GetLocation() const{
    return loc_;
}

void MarioObject::SetLocation(location loc) {
    loc_ = loc;
}



Velocity2D MarioObject::GetVelocity() const{
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


double MarioObject::DeltaTime() const {
    double dt = std::chrono::duration<double , std::milli>(std::chrono::high_resolution_clock::now() - current_time_).count();
    return dt;
}

void MarioObject::ResetTime() {
    current_time_ = std::chrono::high_resolution_clock::now();
}















