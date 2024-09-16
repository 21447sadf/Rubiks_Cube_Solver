#include "Cube.h"
#include <vector>
#include <iterator>

//Solve the white cross (bottom of cube)
void Cross(Cube &cube) {

    //First, look for any single white centre piece on bottom
    //and match it with its face
    // Start with top most edge piece, checking clockwise
    // faces to check in order: front(3), right(4), back(5), left(2)
    std::vector<char> pieces = {cube.getPiece(1, 0, 1), cube.getPiece(1, 1, 2), cube.getPiece(1, 2, 1), cube.getPiece(1, 1, 0)};
    std::vector<int> faces = {3, 4, 5, 2};
    std::vector<char>::iterator pieceIter;
    int n = faces.size();

    for (auto pieceIter = pieces.begin(); pieceIter != pieces.end(); ++pieceIter) {
        if ((*pieceIter) == 'W') {
            //Face of the cube to check is the index of piece in faces vector
            int face = faces[std::distance(pieces.begin(), pieceIter)];
            //Store the piece to match with its respective face
            char piece = cube.getPiece(face, 2, 1);

            //Rotate the bottom face until the piece is matched
            for (int i = 0; i < n; i++) {   
                if (piece == cube.getCentrePiece(face)) {
                    break;
                }
                cube.rotateBottom();
                face = faces[i % n];
            }
        }
    }

    // //Rearrange the rest of the middle white pieces to form the cross
    // //Check the top face first
    // // faces to check in order: front(3), right(4), back(5), left(2)
    // std::vector<char> topMiddleEdges = {cube.getPiece(0, 2, 1), cube.getPiece(0, 1, 2), cube.getPiece(0, 0, 1),  cube.getPiece(0, 1, 0)};
    // auto it = find(topMiddleEdges.begin(), topMiddleEdges.end(), 'W');

    // if (it != topMiddleEdges.end()) {
    //     //Face of the cube to check is the index of piece in faces vector
    //     int face = faces[std::distance(pieces.begin(), pieceIter)];
    //     //Store the piece to match with its respective face
    //     char piece = cube.getPiece(face, 0, 1);

    //     //Rotate the top face until the piece is matched
    //     for (int i = 0; i < n; i++) {   
    //         if (piece == cube.getCentrePiece(face)) {
    //             break;
    //         }
    //         cube.rotateBottom();
    //         face = faces[i % n];
    //         piece = cube.getPiece(face, 0, 1);
    //     }
    // }


}