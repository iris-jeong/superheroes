#include "strlib.h"
#include <string>
#include <iostream>

std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
    //Create vector to hold the parsed strings.
    std::vector<std::string> splitStrings;
    
    //Create variables to keep track of the start and end of the new substring.
    int startIndex = 0;
    //The end of the substring will be the index of the index where we find the first instance of the delimiter from the starting index.
    int endIndex = str.find(splitChar, startIndex);
    
    //Keep making substrings until we don't find any more delimiters in the string.
    while(endIndex != std::string::npos) {

        //Create the substring.
        //Substring starts at 'startIndex' and has 'endIndex - startIndex' number of characters
        std::string substring = str.substr(startIndex, endIndex - startIndex);
        
        //Add the substring to the splitStrings vector.
        splitStrings.push_back(substring);
        
        //Update the start and end indices
        //The start will now become the index after the index where the delimiter was found.
        //e.g. if delimiter found at index 3, start will be index 4.
        startIndex = endIndex + 1;
        //The end will become the next instance of the delimiter starting from the new start index.
        endIndex = str.find(splitChar, startIndex);
    }
    
    //Since there will not be a delimiter after the last substring in the string, it will break out of the loop before grabbing it. Make the last substring here.
    std::string substring = str.substr(startIndex, str.length() - startIndex);

    
    //Add it to the vector.
    splitStrings.push_back(substring);
    
	return splitStrings;
}

