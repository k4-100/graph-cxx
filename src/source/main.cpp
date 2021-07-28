// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream> 

#include "../include/FileReader.hpp"

// user-defined macros 
#define WINDOW_SIDE 800


int main(const int argc, const char *argv[] )
{
    sf::RenderWindow window
    ( 
        sf::VideoMode( WINDOW_SIDE, WINDOW_SIDE ), 
        "SFML works!", 
        sf::Style::Close 
    );

    const std::string filePath = argv[1] != nullptr ? argv[1] : "sample.rtf";

    const std::string fileContent =  utl::readFromFile( filePath );
  
    std::cout<< "fileContent: \n "<< fileContent << "###\n"; 

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
