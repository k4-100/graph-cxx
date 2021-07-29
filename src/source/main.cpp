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

    // lato font
    sf::Font lato;
    
    if( lato.loadFromFile( "Lato-Black.ttf"  ) )
        std::cout<< "font loaded (RELEASE) \n";
    else{
        if( lato.loadFromFile(  "../../Lato-Black.ttf"  ) )
            std::cout<< "font loaded (TESTING) \n";
        else
            std::cout<< "font issue, make sure it is in res directory\n";
    }

    // sf::Text txt("font test", lato, 20);

    utl::DistancePoint dp(
        sf::Vector2f( WINDOW_SIDE/2.f, WINDOW_SIDE/2.f ),
        sf::Vector2f(50.f,50.f),
        lato,
        "lato font"
    );

    utl::DistancePoints dPoints(
    sf::Vector2f( WINDOW_SIDE/2.f, WINDOW_SIDE/2.f ),
    sf::Vector2f(30.f,30.f),
    lato,
    "EV3",
    fileContent
    );



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
        // window.draw( shape );
        // window.draw( txt );
        dPoints.Draw( window );
        window.display();
    }

    return 0;
}
