#include "../include/DistancePoint.hpp"
utl::DistancePoint::DistancePoint(
                const sf::Vector2f& position, 
                const sf::Vector2f& pointSize, 
                const sf::Font& font, 
                const std::string& textContent 
)
: point(pointSize)
, text( textContent, font, 15 )

{   
    point.setOrigin(pointSize/2.f);
    point.setPosition(position);
    point.setFillColor(sf::Color::Green);
    text.setPosition(position);
    text.setOrigin(text.getLocalBounds().width/2.f, pointSize.y );

    std::cout<< "DISTANCEPOINT IS HERE MAN\n";
}


void utl::DistancePoint::Draw( sf::RenderWindow& window ){
    window.draw(point);
    window.draw(text);
}