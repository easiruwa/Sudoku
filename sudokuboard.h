/************************************************************************
    File: sudokuboard.h
    Author: Eseosa Asiruwa
    Date: February 22, 2016
    Assignment: Lab 3

    Declaration of a sudokuboard class.

************************************************************************/

#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

class sudokuboard{
public:

    sudokuboard(); // no-arg constructor: creates empty board
    char get(size_t r, size_t c) const; // return the numeral at position (r,c)
    // if the board would allow placing n at (r,c)
    bool canplace(char num, size_t r, size_t c) const; 
    void place(size_t r, size_t c, int n); // place numeral n at posiion (r,c)
    void print(); // write the board to cout
    void remove(size_t r, size_t c); // remove the numeral at position (r,c)
    bool solved(); // true if there are no blank spots on the board
    void placeline(size_t p, string input); // inputs characters line by line

private:
    string sboard[9]; // array of 9 strings
};