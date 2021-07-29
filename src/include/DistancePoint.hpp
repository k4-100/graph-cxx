#ifndef DISTANCEPOINT_HPP
#define DISTANCEPOINT_HPP

// external libs
#include <SFML/Graphics.hpp>

// core c/c++
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
/*PI number with somehow low float point precision*/
#define PI 3.141592654

/*pseudo reverses the value; float number precision*/ 
#define reverse(X) (1.0f/X)

/*calculates divider for PI*/
#define calculatePIdivider(X) ( float( (360.0/X) / 2.0 ) ) 


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
            void SetPosition(  const sf::Vector2f& position);
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
             /// draw DistancePoint objects
            void Draw( sf::RenderWindow& window );
            
        public:
            std::vector<DistancePoint> list;

    };

} //! namespace utl


#endif //! DISTANCEPOINT_HPP