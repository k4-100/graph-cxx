#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <iostream>
#include <fstream>
#include <iterator>


namespace utl{

/// @param path path to file 
/// @return string containing whole file
std::string readFromFile( const std::string& path );

} //! namespace utl


#endif //! FILEREADER_HPP