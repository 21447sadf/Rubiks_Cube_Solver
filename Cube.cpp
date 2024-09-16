#include "Cube.h"
#include <vector>

Cube::Cube(std::vector<std::vector<std::vector<char>>> scrambledCube) {
    this->cube = scrambledCube;
    
    //SIDES OF THE CUBE:
    //  TOP = cube[0] 
    //  BOTTOM = cube[1]
    //  LEFT = cube[2]
    //  RIGHT = cube[3]
    //  FRONT = cube[4]
    //  BACK = cube[5]
}

std::vector<std::vector<std::vector<char>>> Cube::getCube() {
    return this->cube;
}

char Cube::getPiece(int face, int row, int col) {
    return this->cube[face][row][col];
}

void Cube::rotateClockWise90(int face) {
    for (int i = 0; i < 3 / 2; i++) { 
        for (int j = i; j < (3 - i - 1); j++) { 
            // Swapping elements after each iteration in Clockwise direction
                int temp= cube[face][i][j]; 
                cube[face][i][j] = cube[face][2 - j][i]; 
                cube[face][2 - j][i] = cube[face][2 - i][2 - j]; 
                cube[face][2 - i][2 - j] = cube[face][j][2 - i]; 
                cube[face][j][2 - i] = temp; 
        } 
    }
} 

void Cube::rotateFront() {
    //Rotate front by 90 degrees
    rotateClockWise90(4);

    //Get rows to rotate along with face
    std::vector<char> topRow = cube[0][2];
    std::vector<char> rightRow = {cube[3][0][0], cube[3][1][0], cube[3][2][0]};
    std::vector<char> bottomRow = cube[1][0];
    std::vector<char> leftRow = {cube[2][0][2], cube[2][1][2], cube[2][2][2]};

    //Shift rows around cube
    //TOP -> RIGHT
    cube[3][0][0] = topRow[0];
    cube[3][1][0] = topRow[1];
    cube[3][2][0] = topRow[2];

    //RIGHT -> BOTTOM
    cube[1][0][0] = rightRow[2];
    cube[1][0][1] = rightRow[1];
    cube[1][0][2] = rightRow[0];

    //BOTTOM -> LEFT
    cube[2][0][2] = bottomRow[0];
    cube[2][1][2] = bottomRow[1];
    cube[2][2][2] = bottomRow[2];

    //LEFT -> TOP
    cube[0][2][0] = leftRow[2];
    cube[0][2][1] = leftRow[1];
    cube[0][2][2] = leftRow[0];
}

void Cube::rotateFrontAC() {
    //Rotate 90 AC = 3 x Rotate 90 C
    rotateFront();
    rotateFront();
    rotateFront();
}

void Cube::rotateBack() {
    //Rotate back by 90 degrees clockwise
    rotateClockWise90(5);

    //Get rows to rotate along with face
    std::vector<char> topRow = cube[0][0];
    std::vector<char> rightRow = {cube[3][0][2], cube[3][1][2], cube[3][2][2]};
    std::vector<char> bottomRow = cube[1][2];
    std::vector<char> leftRow = {cube[2][0][0], cube[2][1][0], cube[2][2][0]};

    //Shift rows around cube 
    //TOP -> LEFT
    cube[2][0][0] = topRow[2];
    cube[2][1][0] = topRow[1];
    cube[2][2][0] = topRow[0];

    //RIGHT -> TOP
    cube[0][0][0] = rightRow[0];
    cube[0][0][1] = rightRow[1];
    cube[0][0][2] = rightRow[2];

    //BOTTOM -> RIGHT
    cube[3][0][2] = bottomRow[2];
    cube[3][1][2] = bottomRow[1];
    cube[3][2][2] = bottomRow[0];

    //LEFT -> BOTTOM
    cube[1][2][0] = leftRow[0];
    cube[1][2][1] = leftRow[1];
    cube[1][2][2] = leftRow[2];
}

void Cube::rotateBackAC() {
    //Rotate AC = 3 x Rotate C
    rotateBack();
    rotateBack();
    rotateBack();
}

void Cube::rotateTop() {
    //Rotate top face by 90 degrees
    rotateClockWise90(0);

    //Get rows to rotate along with face
    std::vector<char> backRow = cube[5][0];
    std::vector<char> rightRow = cube[3][0];
    std::vector<char> frontRow = cube[4][0];
    std::vector<char> leftRow = cube[2][0];

    //Shift rows around cube 
    //BACK -> RIGHT
    cube[3][0] = backRow;

    //RIGHT -> FRONT
    cube[4][0] = rightRow;

    //FRONT -> LEFT
    cube[2][0] = frontRow;

    //LEFT -> BACK
    cube[5][0] = leftRow;
}

void Cube::rotateTopAC() {
    //Rotate AC = 3 x Rotate C
    rotateTop();
    rotateTop();
    rotateTop();
}

void Cube::rotateBottom() {
    //Rotate bottom by 90 degrees
    rotateClockWise90(1);

    //Get rows to rotate along with face
    std::vector<char> backRow = cube[5][2];
    std::vector<char> rightRow = cube[3][2];
    std::vector<char> frontRow = cube[4][2];
    std::vector<char> leftRow = cube[2][2];

    //Shift rows around cube
    //BACK -> LEFT
    cube[2][2] = backRow;

    //RIGHT -> BACK
    cube[5][2] = rightRow;

    //FRONT -> RIGHT
    cube[3][2] = frontRow;

    //LEFT -> FRONT
    cube[4][2] = leftRow;
}

void Cube::rotateBottomAC() {
    //Rotate 90 AC = 3 x Rotate 90 C 
    rotateBottom();
    rotateBottom();
    rotateBottom();
}

void Cube::rotateLeft() {
    //Rotate left face by 90 degrees
    rotateClockWise90(2);

    //Get rows to rotate along with face
    std::vector<char> topRow = {cube[0][0][0], cube[0][1][0], cube[0][2][0]};
    std::vector<char> frontRow = {cube[4][0][0], cube[4][1][0], cube[4][2][0]};
    std::vector<char> bottomRow = {cube[1][0][0], cube[1][1][0], cube[1][2][0]};
    std::vector<char> backRow = {cube[5][0][2], cube[5][1][2], cube[5][2][2]};

    //Shift rows around cube 
    //TOP -> FRONT
    cube[4][0][0] = topRow[0];
    cube[4][1][0] = topRow[1];
    cube[4][2][0] = topRow[2];

    //FRONT -> BOTTOM
    cube[1][0][0] = frontRow[0];
    cube[1][1][0] = frontRow[1];
    cube[1][2][0] = frontRow[2];

    //BOTTOM -> BACK
    cube[5][2][2] = bottomRow[0];
    cube[5][1][2] = bottomRow[1];
    cube[5][0][2] = bottomRow[2];

    //BACK -> TOP
    cube[0][2][0] = backRow[0];
    cube[0][1][0] = backRow[1];
    cube[0][0][0] = backRow[2];
}

void Cube::rotateLeftAC() {
    //Rotate 90 AC = 3 x Rotate C
    rotateLeft();
    rotateLeft();
    rotateLeft();
}

void Cube::rotateRight() {
    //Rotate right face by 90 degrees
    rotateClockWise90(3);

    //Get rows to rotate along with face
    std::vector<char> topRow = {cube[0][0][2], cube[0][1][2], cube[0][2][2]};
    std::vector<char> frontRow = {cube[4][0][2], cube[4][1][2], cube[4][2][2]};
    std::vector<char> bottomRow = {cube[1][0][2], cube[1][1][2], cube[1][2][2]};
    std::vector<char> backRow = {cube[5][0][0], cube[5][1][0], cube[5][2][0]};

    //Shift rows around cube 
    //TOP -> BACK
    cube[5][0][0] = topRow[2];
    cube[5][1][0] = topRow[1];
    cube[5][2][0] = topRow[0];

    //BACK -> BOTTOM
    cube[1][0][2] = backRow[2];
    cube[1][1][2] = backRow[1];
    cube[1][2][2] = backRow[0];

    //BOTTOM -> FRONT
    cube[4][0][2] = bottomRow[0];
    cube[4][1][2] = bottomRow[1];
    cube[4][2][2] = bottomRow[2];

    //FRONT -> TOP
    cube[0][0][2] = frontRow[0];
    cube[0][1][2] = frontRow[1];
    cube[0][2][2] = frontRow[2];
}

void Cube::rotateRightAC() {
    //Rotate 90 AC = 3 x Rotate 90 C
    rotateRight();
    rotateRight();
    rotateRight();
}

char Cube::getCentrePiece(int face) {
    char piece;
    switch (face) {
        case 0:
            piece = 'Y';
        case 1:
            piece = 'W';
        case 2:
            piece = 'O';
        case 3:
            piece = 'R';
        case 5:
            piece = 'G';
    }

    return piece;
}