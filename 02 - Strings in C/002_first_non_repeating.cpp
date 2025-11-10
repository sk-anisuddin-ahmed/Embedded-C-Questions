/*
2. Find the first non-repeating character in a given string (C++ Version)
Identify the first character that does not repeat anywhere else in the string, 
using C++ STL unordered_map for optimized time and space complexity.

Example: Input: "swiss"
Output: 'w'
*/

#include <iostream>
#include <string>
#include <unordered_map>

char findFirstNonRepeating(const std::string& str)
{
    std::unordered_map<char, int> freq;
    
    for (char c : str) 
    {
        freq[c]++;
    }
    
    for (char c : str) 
    {
        if (freq[c] == 1) 
        {
            return c;
        }
    }
    
    return '\0';
}

int main()
{
    std::string test = "swiss";
    
    char result = findFirstNonRepeating(test);
    std::cout << "Input: " << test << ", First non-repeating: " << result << std::endl;
    
    return 0;
}