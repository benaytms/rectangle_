#include <SFML/Graphics.hpp>
// the only necessary libray is SFML

#define WIDTH 800
#define HEIGHT 600

int main() {
    // renders window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Rectangle", sf::Style::Titlebar | sf::Style::Close);

    // rectangle settings
    float recWidth = 80;
    float recWidth = 45;
    sf::RectangleShape rectangle(sf::Vector2f( recWidth, recHeight ));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition( 0.45*WIDTH , 0.4625*HEIGHT );

    float speed = 0.1f;             // rectangle speed
    bool movingRight = true;        // flag for right movement
    bool movingUp = true;           // flag for up movment
    bool horizontalBounce = false; // flag for horizontal bounce
    bool verticalBounce = false;    // vertical bounce

    // Main loop
    while (window.isOpen()) {
        // events area
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Y) {
                    horizontalBounce = true; // Set horizontal movement flag to true
                    verticalBounce = false; // set vertical movement flag to false
                }
                if (event.key.code == sf::Keyboard::T) {
                    horizontalBounce = false; // set horizontal to false
                    verticalBounce = true;    // set vertical to true
                }
                if (event.key.code == sf::Keyboard::P || event.key.code == sf::Keyboard::O){
                    verticalBounce = false;
                    horizontalBounce = false;
                }
            }
        }

        if (!horizontalBounce && !verticalBounce) { // Normal movement

            // Movement for W, A, S, D

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && rectangle.getPosition().x > 0){
                rectangle.move(-speed, 0.f); // move left
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && rectangle.getPosition().x + rectangle.getSize().x < window.getSize().x){
                rectangle.move(speed, 0.f); // move right
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && rectangle.getPosition().y > 0) {
                rectangle.move(0.f, -speed); // Move up
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && rectangle.getPosition().y + rectangle.getSize().y < window.getSize().y) {
                rectangle.move(0.f, speed); // Move down
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();     // closes the window
            }


            // color change

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                rectangle.setFillColor(sf::Color::Green);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                rectangle.setFillColor(sf::Color::Red);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                rectangle.setFillColor(sf::Color::Yellow);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                rectangle.setFillColor(sf::Color::Magenta);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                rectangle.setFillColor(sf::Color::Blue);
            }
        }

        else if (horizontalBounce){
            if (movingRight){
                if (rectangle.getPosition().x + rectangle.getSize().x >= window.getSize().x){   // checks if the rectangle passed the window border in x
                    movingRight = false;    // changes to left movement
                } else {
                    rectangle.move(speed, 0.f); // if it didn't cross, keeps moving right
                }
            } else {
                if (rectangle.getPosition().x <= 0){    // checks if the rectangle passed the window border in x
                    movingRight = true; // if gets to the left border, changes to right movement
                } else {
                    rectangle.move(-speed, 0.f); // if not, keeps going left
                }
            }
        }

        else if (verticalBounce) {      // this works with the same principle as the horizontal bounce, except its vertical
            if (movingUp){
                if (rectangle.getPosition().y <= 0){
                    movingUp = false;
                } else {
                    rectangle.move(0.f, -speed); // move up
                }
            } else {
                if (rectangle.getPosition().y + rectangle.getSize().y >= window.getSize().y){
                    movingUp = true;
                } else {
                    rectangle.move(0.f, speed); // move down
                }
            }
        }

        // Clear the window
        window.clear();

        // draws the rectangle
        window.draw(rectangle);

        // Display the window contents
        window.display();
    }
    return 0;
}
