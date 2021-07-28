#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <iostream>

namespace utl{

/// @param path path to file 
/// @return string containing whole file
std::string readFromFile( const std::string& path = "../../sample.txt" );


} //! namespace utl


#endif //! FILEREADER_HPP