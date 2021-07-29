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
    point.setFillColor(sf::Color::Green);
    text.setOrigin(text.getLocalBounds().width/2.f, pointSize.y );
    SetPosition(position);
}


void utl::DistancePoint::Draw( sf::RenderWindow& window ){
    window.draw(point);
    window.draw(text);
}

void utl::DistancePoint::SetPosition(const sf::Vector2f& position){
    point.setPosition(position);
    text.setPosition(position);
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
    list[0].point.setFillColor(sf::Color::Red);


    std::string str = fileContent;

    std::vector<utl::DistancePoints> fileValues;
    
    for(uint16_t i=0; i<storage.size(); i++){
        std::stringstream val;
        val << std::fixed << std::setprecision(1) << storage[i];

        list.push_back( utl::DistancePoint( position + sf::Vector2f(0.f,300.f + storage[i] * 5.f ), pointSize, font, std::to_string(i+1) + ": "  + val.str()  ) );
    }
        

    const float averageDegree = 360.f / storage.size();

    for(uint16_t i=1; i<list.size(); i++){
        // angle in TRIGONOMETRY, not in degrees
        double angle = 0;
        float degrees = 0;

        if( i > 1 ){
            degrees = averageDegree * (i-1);
            angle = PI / calculatePIdivider( degrees ) ;
        }
        


        sf::Vector2f dp = list[i].point.getPosition() ;
        
        std::cout<< degrees << '\n';
        double Xrot = dp.x * cos(angle) - dp.y * sin(angle);
        double Yrot = dp.y * cos(angle) + dp.x * sin(angle);
        std::cout<<"Xrot: "<< Xrot << '\n';
        std::cout<<"Yrot: "<< Yrot << '\n';

        list[i].SetPosition(sf::Vector2f( (float)Xrot,(float)Yrot )  );
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
