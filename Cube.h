#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <vector>

class Cube {
    public:
        //Default Constructor
        Cube(std::vector<std::vector<std::vector<char>>> scrambledCube);

        //Return cube structure
        std::vector<std::vector<std::vector<char>>> getCube();

        //Function to rotate any face - excluding all other adjacent faces -
        //by 90 degrees clockwise
        void rotateClockWise90(int face);

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

        //Get centrepiece of a face 
        char getCentrePiece(int face);

        //Get piece at specified coordinates (face, row, column) 
        char getPiece(int face, int row, int col);

    private:
        std::vector<std::vector<std::vector<char>>> cube;
        bool solved = false;
};

#endif //CUBE_H