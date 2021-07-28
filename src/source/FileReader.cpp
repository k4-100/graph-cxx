#include "../include/FileReader.hpp"



/// @param path path to file 
/// @return string containing file's content
std::string utl::readFromFile( const std::string& path ){
    // file reading stream
    std::ifstream outputFile(path);
    // loads data into a string 
    std::string str(std::istreambuf_iterator<char>{outputFile}, {});
    // closes stream
    outputFile.close();
    // return string with data
    return str;
}