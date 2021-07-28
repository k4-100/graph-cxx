#ifndef DISTANCEPOINT_HPP
#define DISTANCEPOINT_HPP

// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream>
#include <vector>

namespace utl{

    class DistancePoint{
        // CONSTRUCTOR
        public:
            DistancePoint(
                const sf::Vector2f& position, 
                const sf::Vector2f& pointSize, 
                const sf::Font& font, 
                const std::string& textContent 
            );
        // FUNCTIONS
        public:
            /// draw rectangle and text
            void Draw( sf::RenderWindow& window );
        // VARIABLES
        public:
            sf::RectangleShape point;
            sf::Text text;
    };


    class DistancePoints{
        public:
            DistancePoints(
                const sf::Vector2f& position, 
                const sf::Vector2f& pointSize, 
                const sf::Font& font, 
                const std::string& textContent,
                const std::string& fileContent
            );
        public:
            std::vector<DistancePoint> list;
        
    };

} //! namespace utl


#endif //! DISTANCEPOINT_HPP