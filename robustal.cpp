#include "robustal.hpp"

#include <iostream>

Board::Board() {
    maskGeneration();
};

void Board::maskGeneration() {
    rows[0] = 0x00000000000000FFULL;
    cols[0] = 0x0101010101010101ULL;
    squares[0] = 0x0000000000000001ULL;

    for (int i = 1; i < 8; i++) {
        rows[i] = rows[i - 1] << 8;
        cols[i] = cols[i - 1] << 8;
    }

    std::cout << "Rows and Columns generated" << std::endl;

    for (int i = 1; i < 64; i++) {
        squares[i] = squares[i - 1] << 1;
    }

    std::cout << "Squares generated" << std::endl;



    for (int i = 0; i < 64; i++) {
        int row = i / 8;
        int col = i % 8;

        for (int j = 1; j < 8; j++) {
            if (row + j < 8 && col + j < 8) {
                diagonals[i][0] = rows[row+j] & cols[col+j];
            }
            if (row - j > 0 && col + j < 8) {
                diagonals[i][1] = rows[row-j] & cols[col+j];
            }
            if (row + j < 8 && col - j > 0) {
                diagonals[i][2] = rows[row+j] & cols[col-j];
            }
            if (row - j > 0 && col - j > 0) {
                diagonals[i][3] = rows[row+j] & cols[col+j];
            }
        }
    }

    std::cout << "Rays generated" << std::endl;
}

void Board::updateBoard() {
    whitePieces = whitePawns | whiteRooks | whiteKnights | whiteBishops | whiteQueens | whiteKing;
    blackPieces = blackPawns | blackRooks | blackKnights | blackBishops | blackQueens | blackKing;
    occupied    = whitePieces | blackPieces;
    empty       = ~occupied;
}
