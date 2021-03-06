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
        sf::VideoMode( 1000, 1000 ), 
        "SFML works!", 
        sf::Style::Default 
    );

    window.setView(
        sf::View( sf::Vector2f(0.f,0.f), sf::Vector2f(WINDOW_SIDE,WINDOW_SIDE) * 2.f  )
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

    // utl::DistancePoint dp(
    //     sf::Vector2f( WINDOW_SIDE/2.f, WINDOW_SIDE/2.f ),
    //     sf::Vector2f(50.f,50.f),
    //     lato,
    //     "lato font"
    // );

    utl::DistancePoints dPoints(
    sf::Vector2f( 0.f, 0.f ),
    sf::Vector2f(35.f,35.f),
    lato,
    "EV3",
    fileContent
    );



    sf::RectangleShape shape(sf::Vector2f(100.f,100.f) );
    shape.setOrigin(shape.getSize().x/2.f, shape.getSize().y/2.f );
    shape.setPosition(0.f,0.f );



    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent( event ) )
        {

            switch( event.type ){
                case sf::Event::Closed:
                    window.close();
                break; 
                case sf::Event::MouseButtonPressed:
                // sf::Mouse msPos;
                // std::cout<< "x: "<< msPos.getPosition(window).x << '\n';
                // std::cout<< "y: "<< msPos.getPosition(window).y << '\n';

                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                std::cout<< "x: "<< mouse.x << '\n';
                std::cout<< "y: "<< mouse.y << '\n';
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
