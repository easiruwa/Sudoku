/************************************************************************
    File: sudokuboard.cc
    Author: Eseosa Asiruwa
    Date: 2/21/16
    Assignment: Lab 3

    Implemenation of the sudokuboard class.

************************************************************************/

#include <iostream>
#include "sudokuboard.h"

/*** Constructor ***/
sudokuboard::sudokuboard()
    // Initializes board with blank spaces
{   
    for (size_t i = 0; i < 9; i++)
        sboard[i] = "_________";
}

void sudokuboard::print()
    // Print the board
{
    for (size_t i = 0; i < 9; i++){
        cout << sboard[i] << endl;
    }
}

void sudokuboard::place(size_t r, size_t c, int n)
    // Place numeral n at posiion (r,c)
{
    sboard[r][c] = n + '0';
}

void sudokuboard::placeline(size_t p, string input)
    // Places characters in board, line by line
{
    sboard[p] = input;
}

bool sudokuboard::canplace(char num, size_t r, size_t c) const
    // Checks empty spot to see if you can place given number. Returns a bool
    // depending on if the number shows up in the same r, c, or 3x3
{    
        if (get(r,c) == '_'){ 
             for (int j = 0; j < 9; j++){ // check rows
                if (get(j,c) == num)
                    return false;
            }
            for (int k = 0; k < 9; k++){ // check cols
                if (get(r,k) == num)
                    return false;
            }
            for (int y = 0; y < 3; y++){ // check 3x3
                for (int x = 0; x < 3; x++){
                    if (get((r / 3) * 3 + y , (c / 3) * 3 + x) == num){
                        return false;
                    }
                }
            }
            return true;
        }
    return false;
}

char sudokuboard::get(size_t r, size_t c) const
    // Return char at position r,c
{
    return sboard[r][c];
}

void sudokuboard::remove(size_t r, size_t c)
    // Replace char at postion r,c with an empty space
{
    sboard[r][c] = '_';
}

bool sudokuboard::solved()
    // Check to see if there are any empty spaces on the board
{
    for (int r = 0; r < 9; r++){
        for (int c = 0; c < 9; c++){
            if (sboard[r][c] == '_')
                return false;
        }
    }
    return true;
}