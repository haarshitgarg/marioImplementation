#ifndef BAKCKGROUND_OBJECT_HPP
#define BAKCKGROUND_OBJECT_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "commonObjects.hpp"

enum BackgroundType {
    START_SCREEN = 0,
    GAME1,
    END_SCREEN
};

class Background {

    public:
        Background();
        ~Background();
        bool setLocation(location loc);
        location getLocation();
        void changeBackground(BackgroundType type);
        sf::Vector2u getCurrentBackgroundSize();
        
        sf::Sprite getBackground();
    
    private: 
        location loc_;
        BackgroundType current_background_;

        std::vector<sf::Texture> background_textures_;

};

#endif
