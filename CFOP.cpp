#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <iterator> 

#include "prompts.h"
#include "Cube.h"

//TESTING FUNCTIONS
#include "Cross.h"

bool validColour(char colour) {
    char lowerCaseColour = std::tolower(colour);

    if ((lowerCaseColour == 'w') || (lowerCaseColour == 'b') || (lowerCaseColour == 'r')
     || (lowerCaseColour == 'g') || (lowerCaseColour == 'o') || (lowerCaseColour == 'y')) {
        return true;
    }

    return false;
} 

void printCube(std::vector<std::vector<std::vector<char>>> cube) {

    std::cout << "PRINTING CUBE LAYOUT" << std::endl;

    std::string sides[6] = {"Top", "Bottom", "Left", "Right", "Front", "Back"};

    for (int i = 0; i < 6; i++) 
    {
        printf("%-10s|", sides[i].c_str());
        for (int j = 0; j < 3; j++) 
        {
            for (int k = 0; k < 3; k++) 
            {
                std::cout << cube[i][j][k];
            }
        }
        std::cout << "|" << std::endl;
    }
}

int main (void) {

    bool solved = false;

    //Vector to store cube layout
    std::vector<std::vector<std::vector<char>>> cube;
    
    cube.resize(6);
    for (unsigned int i = 0; i < cube.size(); i++) 
    {
        cube[i].resize(3);
        for (unsigned int j = 0; j < cube[i].size(); j++) 
        {
            cube[i][j].resize(3);
        }   
    }


    //Variable to store colours of pieces
    char colour = 'w';

    //Declare iterators
    std::vector<std::vector<std::vector<char>>>::iterator it1;
    std::vector<std::vector<char>>::iterator it2;
    std::vector<char>::iterator it3;

    //Menu
    while (!solved) {
        printProgramTitle();
        printPrompt();
        //Set sides of cube
        for (auto it1 = cube.begin(); it1 != cube.end(); ++it1) 
        {
            for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) 
            {
                for (auto it3 = it2->begin(); it3 != it2->end(); ++it3) 
                {
                    std::cin >> colour;
                    while(!validColour(colour)) {
                        std::cout << "\nInvalid input: Please enter 'W', 'B', 'R', 'G', 'Y' or 'O'" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> colour;
                    }
                    (*it3) = colour; 
                }
            }
        }
        printCube(cube);
        Cube rubiksCube(cube);
        Cross(rubiksCube);
        printCube(rubiksCube.getCube());
        solved = true;
    }

    printEnd();
}

