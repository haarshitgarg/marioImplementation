#include "backgroundObject.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <string>

#define ROOT_DIR "/Users/harshitgarg/CPP-projects/marioImplementation/assets/"

Background::Background() {
    this->loc_.x = 0;
    this->loc_.y = 0;

    this->current_background_ = BackgroundType::GAME1;

    std::string texture_path;    
    sf::Texture texture;
    std::string image_path = "superMarioBackground.png";

    texture_path = ROOT_DIR + image_path;
    if(!texture.loadFromFile(texture_path)) {
        std::cerr<<"Cannot load the file: "<<texture_path<<std::endl;
    }
    this->background_textures_ = std::vector<sf::Texture>(5);
    this->background_textures_[static_cast<int>(current_background_)] = texture;
}


Background::~Background() {
    std::cout<<"Background Object Destroyed"<<std::endl;
}

void Background::changeBackground(BackgroundType type) {
    this->current_background_ = type;

}

sf::Sprite Background::getBackground() {
    
    sf::Sprite sprite;
    sprite.setTexture(background_textures_[static_cast<int>(current_background_)]);
    sprite.setTextureRect(sf::IntRect(loc_.x, loc_.y, WINDOW_X/3, WINDOW_Y/3));
    sprite.setScale(3, 3);

    return sprite;
}

bool Background::setLocation(location loc) {
    this->loc_ = loc; 
    return true;
}

sf::Vector2u Background::getCurrentBackgroundSize() {
    sf::Vector2u vec;

    vec = background_textures_[static_cast<int>(current_background_)].getSize();
    return vec;
}

location Background::getLocation() {
    return loc_;
}








