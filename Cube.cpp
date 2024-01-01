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

void Cube::rotateFront() {
    //Rotate front 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[4][j][i];
            cube[4][j][i] = cube[4][i][j];
            cube[4][i][j] = tempVal;
        }
    }

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
    cube[1][0][0] = rightRow[0];
    cube[1][0][1] = rightRow[1];
    cube[1][0][2] = rightRow[2];

    //BOTTOM -> LEFT
    cube[2][0][2] = bottomRow[0];
    cube[2][1][2] = bottomRow[1];
    cube[2][2][2] = bottomRow[2];

    //LEFT -> TOP
    cube[0][2][0] = leftRow[0];
    cube[0][2][1] = leftRow[1];
    cube[0][2][2] = leftRow[2];
}

void Cube::rotateFrontAC() {
    //Rotate 90 AC = 3 x Rotate 90 C
    rotateFront();
    rotateFront();
    rotateFront();
}

void Cube::rotateBack() {
    //Rotate back by 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[5][j][i];
            cube[5][j][i] = cube[5][i][j];
            cube[5][i][j] = tempVal;
        }
    }

    //Get rows to rotate along with face
    std::vector<char> topRow = cube[0][0];
    std::vector<char> rightRow = {cube[3][0][2], cube[3][1][2], cube[3][2][2]};
    std::vector<char> bottomRow = cube[1][2];
    std::vector<char> leftRow = {cube[2][0][0], cube[2][1][0], cube[2][2][0]};

    //Shift rows around cube 
    //TOP -> RIGHT
    cube[3][0][2] = topRow[0];
    cube[3][1][2] = topRow[1];
    cube[3][2][2] = topRow[2];

    //RIGHT -> BOTTOM
    cube[1][2][0] = rightRow[0];
    cube[1][2][1] = rightRow[1];
    cube[1][2][2] = rightRow[2];

    //BOTTOM -> LEFT
    cube[2][0][0] = bottomRow[0];
    cube[2][1][0] = bottomRow[1];
    cube[2][2][0] = bottomRow[2];

    //LEFT -> TOP
    cube[0][0][0] = leftRow[0];
    cube[0][0][1] = leftRow[1];
    cube[0][0][2] = leftRow[2];
}

void Cube::rotateBackAC() {
    //Rotate AC = 3 x Rotate C
    rotateBack();
    rotateBack();
    rotateBack();
}

void Cube::rotateTop() {
    //Rotate top by 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[0][j][i];
            cube[0][j][i] = cube[0][i][j];
            cube[0][i][j] = tempVal;
        }
    }

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
    //Rotate bottom by 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[1][j][i];
            cube[1][j][i] = cube[1][i][j];
            cube[1][i][j] = tempVal;
        }
    }

    //Get rows to rotate along with face
    std::vector<char> backRow = cube[5][2];
    std::vector<char> rightRow = cube[3][2];
    std::vector<char> frontRow = cube[4][2];
    std::vector<char> leftRow = cube[2][2];

    //Shift rows around cube
    //BACK -> RIGHT
    cube[3][2] = backRow;

    //RIGHT -> FRONT
    cube[4][2] = rightRow;

    //FRONT -> LEFT
    cube[2][2] = frontRow;

    //LEFT -> BACK
    cube[5][2] = leftRow;
}

void Cube::rotateBottomAC() {
    //Rotate 90 AC = 3 x Rotate 90 C 
    rotateBottom();
    rotateBottom();
    rotateBottom();
}

void Cube::rotateLeft() {
    //Rotate left by 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[2][j][i];
            cube[2][j][i] = cube[2][i][j];
            cube[2][i][j] = tempVal;
        }
    }

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
    cube[5][0][2] = bottomRow[0];
    cube[5][1][2] = bottomRow[1];
    cube[5][2][2] = bottomRow[2];

    //BACK -> TOP
    cube[0][0][0] = backRow[0];
    cube[0][1][0] = backRow[1];
    cube[0][2][0] = backRow[2];
}

void Cube::rotateLeftAC() {
    //Rotate 90 AC = 3 x Rotate C
    rotateLeft();
    rotateLeft();
    rotateLeft();
}

void Cube::rotateRight() {
    //Rotate left by 90 degrees by transposing vector
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            char tempVal = cube[3][j][i];
            cube[3][j][i] = cube[3][i][j];
            cube[3][i][j] = tempVal;
        }
    }

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