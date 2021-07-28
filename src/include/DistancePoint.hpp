#ifndef DISTANCEPOINT_HPP
#define DISTANCEPOINT_HPP

// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream>


namespace utl{

    class DistancePoint{
        // CONSTRUCTOR
        public:
            DistancePoint(
                // const sf::Vector2f& position, 
                // const sf::Vector2f& pointSize, 
                // const sf::Font& font, 
                // const std::string& textContent 
            );

        // VARIABLES
        public:
            sf::RectangleShape point;
            sf::Text text;
    };

} //! namespace utl


#endif //! DISTANCEPOINT_HPP