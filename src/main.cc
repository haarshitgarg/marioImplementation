#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "backgroundObject.hpp"
#include "gameWorld.hpp"
#include "marioObject.hpp"
#include "marioPhysics.hpp"
#include "commonObjects.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>

#define goBrrr "***************************************************"

bool _showWorld_ = false;
location _windowLocation_;

void GameBackgroundAnimation(Background& bkg) {
    sf::Vector2u textureSize = bkg.getCurrentBackgroundSize();
    location loc = bkg.getLocation();
    double dt = bkg.deltaTime();
    Velocity2D vel = bkg.getVelocity();
    if(dt > 100 && vel.x != 0) {
        if(vel.x>0) {
            if(loc.x + 1 + WINDOW_X/3 >= textureSize.x) {
                loc.x = (2*textureSize.x/3) - WINDOW_X/3 + 10;
            }
            else {
                loc.x = loc.x + 1;
            }
            _windowLocation_.x += 30;
            bkg.setLocation(loc);
            bkg.resetCurrentTime();
        }
        else {
            if(loc.x-1<0){
                loc.x = textureSize.x/3;
            }
            else {
                loc.x = loc.x -1;
            }
            _windowLocation_.x -= 30;
            bkg.setLocation(loc);
            bkg.resetCurrentTime();
        }
    }

}

void gameEngine(sf::RenderWindow& window, Background& bkg, World& world, MarioObject& mario, MarioPhysics& marioPhysics) {
    window.draw(bkg.getBackground());
    GameBackgroundAnimation(bkg);
    if(_showWorld_) {

        marioPhysics.setMarioPosition(mario);
        std::vector<GameObject> gameObject = world.GetGameObjects();
        for(int i = 0; i<gameObject.size(); i++) {
            window.draw(world.GetGameObjects()[i].GetSprite(_windowLocation_));
            marioPhysics.UpdateMatrix(world.GetGameObjects(), _windowLocation_);
        }

        window.draw(mario.GetSprite());
    }
    else {
        mario.ResetTime();
    }
}


int main() {
    std::cout<<goBrrr<<std::endl;
    std::cout<<"RUNNING THE SUPERR MARIO GAME"<<std::endl;
    std::cout<<goBrrr<<std::endl;

    _windowLocation_.x = 0;
    _windowLocation_.y = 0;
    sf::RenderWindow window(sf::VideoMode(WINDOW_X,WINDOW_Y), "SUPER MARIO");
    
    Background background;
    World world;
    MarioPhysics marioPhysics(world.GetGameObjects());
    cv::Mat image = marioPhysics.PrintMatrix();
    cv::imshow("Marix image", image);
    cv::waitKey(0);
    MarioObject mario;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                std::cout<<goBrrr<<std::endl;
                std::cout << "Close event receive. Mario window closing... "<<std::endl;
                window.close();
            }
            else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::D) {
                    background.setXVelocity(10);
                    mario.SetXVelocity(300);
                }
                else if(event.key.code == sf::Keyboard::A) {
                    background.setXVelocity(-10);
                    mario.SetXVelocity(-300);
                }
                else if(event.key.code == sf::Keyboard::Space){
                    mario.SetYVelocity(-500);
                }
            }
            else if(event.type == sf::Event::KeyReleased) {
            
                if(event.key.code == sf::Keyboard::D) {
                    background.setXVelocity(0);
                    mario.SetXVelocity(0);
                }
                else if(event.key.code == sf::Keyboard::A) {
                    background.setXVelocity(0);
                    mario.SetXVelocity(0);
                }
            }

            else if(event.type == sf::Event::MouseButtonPressed) {
                _showWorld_ = true;
            }
        }
        window.clear(sf::Color::Black);
        gameEngine(window, background, world, mario, marioPhysics);
        window.display();
    }
    return 0;
}
