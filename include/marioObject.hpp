#ifndef MARIO_OBJECT_HPP
#define MARIO_OBJECT_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "commonObjects.hpp"
#include <chrono>

#define MARIO_INITIAL_X 10
#define MARIO_INITIAL_Y 200
#define MARIO_LENGTH 150
#define MARIO_BREADTH 200
#define MARIO_TEXTURE_NAME "wall.png"
#define MIN_MARIO_VELOCITY -800

class MarioObject {

    public:
        MarioObject();
        ~MarioObject();

        sf::Sprite GetSprite() const;
        ObjectSize GetSize() const;

        location GetLocation() const;
        void SetLocation(location loc);



        Velocity2D GetVelocity() const;
        void SetVelocity(Velocity2D vel);
        void SetXVelocity(float x);
        void SetYVelocity(float y);


        double DeltaTime() const;
        void ResetTime();

    private:
        ObjectSize size_;
        sf::Texture texture_;
        sf::Sprite sprite_;

        location loc_;
        Velocity2D velocity_;

        std::chrono::time_point<std::chrono::high_resolution_clock> current_time_;

        void loadTexture();
};



#endif
