#include "gameObjects.hpp"
#include "commonObjects.hpp"
#include <iostream>

GameObject::GameObject(location loc, std::string textureName, ObjectSize size) {
    loc_ = loc;
    textureName_ = textureName;
    size_ = size;
    loadTexture();
}

GameObject::~GameObject() {
}

location GameObject::GetLocation() {
    return loc_;
}

sf::Sprite GameObject::GetSprite(location windowLocation) {
    sf::Sprite sprite;
    sprite.setTexture(texture_);

    sprite.setTextureRect(sf::IntRect(0, 0, size_.length, size_.breadth));
    sprite.setPosition(loc_.x - windowLocation.x, loc_.y - windowLocation.y);

    return sprite;
}

void GameObject::loadTexture() {
    textureName_ = ROOT_ASSET_DIR + textureName_;
    if(!texture_.loadFromFile(textureName_)) {
        std::cerr<<"Failed to load: "<<textureName_<<std::endl;
    }
    texture_.setRepeated(true);
}







