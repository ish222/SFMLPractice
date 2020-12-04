#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"

int main() {
    //system("dir");
    sf::RenderWindow window(sf::VideoMode(512, 512), "Test Window");  //Makes main window
//    sf::RectangleShape player(sf::Vector2f(100, 150));  //Makes a shape with given dimensions
//    player.setFillColor((sf::Color::Red));  // Changes colour of shape to specified colour
//    player.setOrigin(50.0f, 50.0f);  // Sets the origin of the shape to its centre (50,50 on our case)
//    player.setPosition(206.0f, 206.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("tux_from_linux.png");
//    player.setTexture(&playerTexture);

    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

//    sf::Vector2u textureSize = playerTexture.getSize();  // The texture file has different animations images, this lets us choose one
//    textureSize.x /= 3;
//    textureSize.y /= 9;
//
//    player.setTextureRect(sf::IntRect(textureSize.x*2, textureSize.y*8, textureSize.x, textureSize.y));

    while(window.isOpen()){  // All our window objects go in here
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while(window.pollEvent(evnt)){
            switch(evnt.type){
                case sf::Event::Closed:  // Checks if the window is closed
                    window.close();
                    break;
//                case sf::Event::Resized:
//                    std::cout << "New Window width: " << evnt.size.width << " New window height: " << evnt.size.height << std::endl;  // Allows us to print window size
//                    break;
//                case sf::Event::TextEntered:
//                    if (evnt.text.unicode < 128){
//                        std::cout << char(evnt.text.unicode) << std::endl;  // Allows us to input characters from keyboard and then prints them out in console
                    }
            }
//        }

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){  // These four lines get input from keyboard and move the shape.
//            player.move(-0.6f, 0.0f);  // The top left coordinate is 0,0 and bottom right is width,height
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
//            player.move(0.6f, 0.0f);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
//            player.move(0.0f, -0.6f);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
//            player.move(0.0f, 0.6f);
//        }

//        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){  // Checks if the left mouse button is pressed
//            sf::Vector2i mousePos =  sf::Mouse::getPosition(window);  // creates integer vector which gets the position of the mouse relative to the window
//            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));  // Both of these (float) and static_cast do the same thing by changing variable type but static_cast is safer
//        }

//        animation.Update(0, deltaTime, false);
//        player.setTextureRect(animation.uvRect);

        player.Update(deltaTime);

        window.clear(sf::Color(150, 150, 150));  // Need to clear window everytime its updated unless you want the shape to drag
//        window.draw(player);  // Draws the shape defined earlier
        player.Draw(window);
        window.display();  // Displays the shape in the window
    }

    return 0;
}
