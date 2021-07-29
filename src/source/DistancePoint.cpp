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
    
    for(uint16_t i=0; i<storage.size(); i++)
        list.push_back( utl::DistancePoint( position + sf::Vector2f(10.f * (1+i),0.f), pointSize, font, textContent ) );

    for(uint16_t i=1; i<list.size(); i++){
        double angle = 20 * i ;
        sf::Vector2f dp = list[i].point.getPosition();
        
        std::cout<< angle << '\n';
        double Xrot = dp.x * cos(angle) - dp.y * sin(angle);
        double Yrot = dp.y * cos(angle) + dp.x * sin(angle);

        list[i].point.setPosition(sf::Vector2f( (float)Xrot,(float)Yrot ) );
    }

}


void utl::DistancePoints::Draw( sf::RenderWindow& window ){
    for(utl::DistancePoint dp : list )
        dp.Draw( window );
}


// void utl::Cable::setPointsGlobal()
// {
//     TPart::setPointsGlobal(); //< inherited function

//     #pragma region Cable specific

//     std::array<sf::Vector2f,4> arr = getPointsGlobal();

    
//     double angle = PI / calculatePIdivider(getRotation());

    
     
//     for (uint8_t i = '\000'; i < '\004'; i++) 
//     {   
//         arr[i] -= referencePoints.first;

//         double Xrot = arr[i].x * cos(angle) - arr[i].y * sin(angle);
//         double Yrot = arr[i].y * cos(angle) + arr[i].x * sin(angle);

//         arr[i] = sf::Vector2f ( (float)Xrot,(float)Yrot) + referencePoints.first; 
//     }
    
//     TPart::setPointsGlobal(arr);


//     setGraphicalBounds();
    


//     // Quad set-up
//     pointsQuadGlobal = getPointsGlobal();
//     setCenterQuad();
//     #pragma endregion // !Cable specific 

// }
