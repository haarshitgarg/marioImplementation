#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#define goBrrr "***************************************************"


int main() {
    std::cout<<goBrrr<<std::endl;
    std::cout<<"RUNNING THE SUPERR MARIO GAME"<<std::endl;
    std::cout<<goBrrr<<std::endl;

    sf::RenderWindow window(sf::VideoMode(1600,1200), "SUPER MARIO");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                std::cout<<goBrrr<<std::endl;
                std::cout << "Close event receive. Mario window closing... "<<std::endl;
                window.close();
            }

        }
    }
    return 0;
}
