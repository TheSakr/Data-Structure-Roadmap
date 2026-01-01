#include <iostream>
#include "String.h"
using namespace std;

int main() {

    string s1 = "HelloWorld";
    string s2 = "Programming";
    printLength(s1);
    accessCharacters(s1);
    concatenateStrings(s1, s2);
    compareStrings("abc", "abd");
    extractSubstring(s2);
    findSubstring(s2, "gram");
    insertAndErase(s1);
    replacePart("Hello i muhammad Sakr");
    reverseString(s2);
    charFrequency("string");

    return 0;
}
