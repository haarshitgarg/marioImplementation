#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "backgroundObject.hpp"
#include "gameWorld.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#define goBrrr "***************************************************"

bool _showWorld_ = false;

void gameEngine(sf::RenderWindow& window, Background& bkg, World& world) {
    window.draw(bkg.getBackground());
    if(_showWorld_) {
        std::vector<GameObject> gameObject = world.GetGameObjects();
        for(int i = 0; i<gameObject.size(); i++) {
            window.draw(world.GetGameObjects()[i].GetSprite());
        }
    }
}

void GameBackgroundAnimation(Background& bkg) {
    sf::Vector2u textureSize = bkg.getCurrentBackgroundSize();
    location loc = bkg.getLocation();

    if(loc.x + 10 + WINDOW_X/3 >= textureSize.x) {
        loc.x = (2*textureSize.x/3) - WINDOW_X/3 + 10;
    }
    else {
        loc.x = loc.x + 10;
    }
    bkg.setLocation(loc);

}

int main() {
    std::cout<<goBrrr<<std::endl;
    std::cout<<"RUNNING THE SUPERR MARIO GAME"<<std::endl;
    std::cout<<goBrrr<<std::endl;

    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "SUPER MARIO");
    
    Background background;
    World world;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                std::cout<<goBrrr<<std::endl;
                std::cout << "Close event receive. Mario window closing... "<<std::endl;
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                GameBackgroundAnimation(background);
            }
            else if(event.type == sf::Event::KeyPressed) {
                _showWorld_ = true;
            }
        }
        window.clear(sf::Color::Black);
        gameEngine(window, background, world);
        window.display();
    }
    return 0;
}
