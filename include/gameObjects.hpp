#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "commonObjects.hpp"

class GameObject {

    public:
        GameObject(location loc, std::string textureName, ObjectSize size);
        ~GameObject();
        location GetLocation();
        void SetRelativeLocation();
        sf::Sprite GetSprite(location windoLocation);

    private:
        location loc_;
        std::string textureName_;
        ObjectSize size_;
        sf::Texture texture_;
        sf::Sprite sprite_;

        void loadTexture();
};
