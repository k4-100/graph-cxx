// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream> 

int main()
{
    sf::RenderWindow window
    ( 
        sf::VideoMode( 800, 800 ), 
        "SFML works!", 
        sf::Style::Close 
    );

    sf::CircleShape shape( 100.f );
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
