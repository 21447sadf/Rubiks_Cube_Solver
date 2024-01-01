#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <vector>

class Cube {
    public:
        //Default Constructor
        Cube(std::vector<std::vector<std::vector<char>>> scrambledCube);

        std::vector<std::vector<std::vector<char>>> getCube();

        //Functions to perform rotations on cube
        void rotateFront();
        void rotateFrontAC();

        void rotateBack();
        void rotateBackAC();

        void rotateTop();
        void rotateTopAC();

        void rotateBottom();
        void rotateBottomAC();

        void rotateLeft();
        void rotateLeftAC();

        void rotateRight();
        void rotateRightAC();

    private:
        std::vector<std::vector<std::vector<char>>> cube;
        bool solved = false;
};

#endif //CUBE_H