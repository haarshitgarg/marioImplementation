#ifndef BAKCKGROUND_OBJECT_HPP
#define BAKCKGROUND_OBJECT_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "commonObjects.hpp"
#include <chrono>

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
        void setXVelocity(int x);
        void setYVelocity(int y);
        void setVelocity(Velocity2D vel);
        location getLocation();
        Velocity2D getVelocity();
        void changeBackground(BackgroundType type);
        sf::Vector2u getCurrentBackgroundSize();
        void resetCurrentTime();
        double deltaTime();
        sf::Sprite getBackground();
    
    private: 
        location loc_;
        BackgroundType current_background_;
        Velocity2D vel_;

        std::vector<sf::Texture> background_textures_;
        std::chrono::time_point<std::chrono::high_resolution_clock> current_time_;

};

#endif
