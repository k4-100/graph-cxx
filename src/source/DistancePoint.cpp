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

}


void utl::DistancePoint::Draw( sf::RenderWindow& window ){
    window.draw(point);
    window.draw(text);
}


utl::DistancePoints::DistancePoints(
    const sf::Vector2f& position, 
    const sf::Vector2f& pointSize, 
    const sf::Font& font, 
    const std::string& textContent,
    const std::string& fileContent
){  
    // std::cout<< "DISTANCEPOINTSSSSSSSSSSSSSSSSSS\n";
    // std::cout<< fileContent << '\n';
    
    /// @return std::vector containing str split into floats
    auto split = [](std::string str){
        std::vector<float> valVec;

        while( str.find('\n') != std::string::npos )
        {
            std::string buffer = str.substr( 0, str.find('\n') );
            valVec.push_back( std::stof(buffer) );
            str.replace( str.find(buffer), buffer.size()+1, "" );
        }

        return valVec;
    };

    auto storage = split( fileContent );


    // central point
    list.push_back( utl::DistancePoint( position, pointSize, font, textContent ) );

    std::string str = fileContent;

    std::vector<utl::DistancePoints> fileValues;
    

}


void utl::DistancePoints::Draw( sf::RenderWindow& window ){
    for(utl::DistancePoint dp : list )
        dp.Draw( window );
}