/*****************************************************************************
    File: sudoku.cc                                                                                                                                       
    Author: Eseosa Asiruwa                      
    Date: 2/5/16 
    Assignment: Lab 3
                                                                                                                              
    This is a sudoku program that solves a given puzzle and returns a    
    completed board. The program uses the mostconstrained function and         
    backtracking in order to solve the board efficiently.                      
                                                                           
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "sudokuboard.h"
#include "stack.h"

using namespace std;

bool mostconstrained(const sudokuboard & sboard, size_t & row, size_t & col, 
    char & numeral)
/* Determine the location of the most constrained empty cell on the board -
where the fewest numerals can be placed. If any cell accepts 0 numeral return
false to trigger back tracking */
{
    int current = 0; // nums that can be placed
    int smallest = 0; // smallest nums that can be placed so far

    for (size_t r = 0; r < 9; r++){
        for (size_t c = 0; c < 9; c++){
            if (sboard.get(r,c) == '_'){
                for (char x = '1'; x <= '9'; x++){
                    if (sboard.canplace(x, r, c))
                        current++;  // how many nums can be placed at the pos
                }
                if (current == 0){ // if no nums can be placed 
                    return false; // trigger backtracking 
                }
                else if (smallest == 0){ // for the first iteration 
                    smallest = current; 
                    row = r;
                    col = c;
                }
                else if (current < smallest){ // if the curr pos takes less nums
                    smallest = current;
                    row = r;
                    col = c;
                }
                current = 0; // reset 
            }
        }
    }
    return true;
}
                    
void solveboard(sudokuboard & sboard, stack & st)
{
    size_t row;
    size_t col;
    char numeral;
    int num;

    while (!sboard.solved()){
        if (mostconstrained(sboard, row, col, numeral)){
            for (int x = 1; x <= 9; x++){
                if (sboard.canplace(x + '0', row, col)){ // convert num to char
                    sboard.place(row, col, x); // place a num if you can
                    st.push(row); st.push(col); // push the r,c to stack
                }
            }
        }
        else {
            do{
                col = st.top(); st.pop();  // pop the last r,c
                row = st.top(); st.pop();
                num = sboard.get(row,col) - '0' + 1; // add 1 to the num at r,c 
                sboard.remove(row, col); // remove r,c from board
                for (; num <= 9 
                    && !sboard.canplace(num + '0', row, col); num++);
                    // stop at the last num that can be placed
                if (num <= 9){ 
                    // place the num if its a 9 or lower
                    sboard.place(row, col, num);
                    st.push(row); st.push(col);
                }
             // goes through every num and still and can't place so pop again                
             }while (num > 9); 
        }
    }
}

int main()
{   
    sudokuboard sboard;
    stack st;

    string input; // variable for lines of input
        // place lines of characters into the board
        for (size_t x = 0; x < 9; x++){
            cin >> input;
            sboard.placeline(x, input);
        }

    solveboard(sboard, st);
    sboard.print();
}