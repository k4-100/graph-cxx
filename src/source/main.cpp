// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream> 

#define WINDOW_SIDE 800


int main()
{
    sf::RenderWindow window
    ( 
        sf::VideoMode( WINDOW_SIDE, WINDOW_SIDE ), 
        "SFML works!", 
        sf::Style::Close 
    );

    sf::CircleShape shape( 100.f );
    // shape.setPosition( sf::Vector2f(WINDOW_SIDE/2 - 100, WINDOW_SIDE/2 - 100 ) );
    shape.setFillColor( sf::Color::Green );

    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent( event ) )
        {

            switch( event.type ){
                case sf::Event::Closed:
                    window.close();
                break; 
            }

        }

        window.clear();
        window.draw( shape );
        window.display();
    }

    return 0;
}
