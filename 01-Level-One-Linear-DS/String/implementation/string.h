#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Print string and its length
void printLength(const string& s) {
    cout << "String: " << s << endl;
    cout << "Length: " << s.length() << endl;
}

//Access characters
void accessCharacters(const string& s) {
    cout << "First character: " << s[0] << endl;
    cout << "Second character (safe): " << s.at(1) << endl;
}

//Concatenation
void concatenateStrings(const string& a, const string& b) {
    string c = a + " " + b;
    cout << "Concatenated: " << c << endl;
}

//Compare strings
void compareStrings(const string& a, const string& b) {
    if (a == b)
        cout << "Strings are equal" << endl;
    else if (a < b)
        cout << a << " is smaller than " << b << endl;
    else
        cout << a << " is greater than " << b << endl;
}

//Substring
void extractSubstring(const string& s) {
    cout << "Substring (index 1, length 3): "
         << s.substr(1, 3) << endl;
}

//Find substring
void findSubstring(const string& s, const string& key) {
    int pos = s.find(key);
    if (pos != string::npos)
        cout << "Found at index: " << pos << endl;
    else
        cout << "Not found" << endl;
}

//Insert and erase
void insertAndErase(string s) {
    s.insert(5, " ");
    cout << "After insert: " << s << endl;

    s.erase(5, 1);
    cout << "After erase: " << s << endl;
}

//Replace
void replacePart(string s) {
    s.replace(0, 4, "That");
    cout << "After replace: " << s << endl;
}

//Reverse string
void reverseString(string s) {
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
}

//Character frequency
void charFrequency(const string& s) {
    int freq[256] = {0};

    for (char c : s)
        freq[c]++;

    cout << "Character Frequencies:" << endl;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            cout << char(i) << " : " << freq[i] << endl;
    }
}

#endif