#ifndef MARIO_OBJECT_HPP
#define MARIO_OBJECT_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "commonObjects.hpp"
#include <chrono>

class MarioObject {

    public:
        MarioObject();
        ~MarioObject();
        location GetLocation();
        void SetLocation(location loc);
        void SetRelativeLocation();
        sf::Sprite GetSprite();


        Velocity2D GetVelocity();
        void SetVelocity(Velocity2D vel);
        void SetXVelocity(float x);
        void SetYVelocity(float y);

        double ElapsedTime();
        void ResetTime();

    private:
        location loc_;
        ObjectSize size_;
        sf::Texture texture_;
        sf::Sprite sprite_;

        Velocity2D velocity_;

        std::chrono::time_point<std::chrono::high_resolution_clock> current_time_;

        void loadTexture();
};



#endif
