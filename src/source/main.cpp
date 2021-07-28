// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream> 

// user-defined headers
#include "../include/FileReader.hpp"
#include "../include/DistancePoint.hpp"

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
  
    // std::cout<< "fileContent: \n "<< fileContent << "###\n"; 

    utl::DistancePoint dp;


    sf::RectangleShape shape(sf::Vector2f(100.f,100.f) );
    shape.setOrigin(shape.getSize().x/2.f, shape.getSize().y/2.f );
    shape.setPosition( WINDOW_SIDE/2.f, WINDOW_SIDE/2.f );



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
