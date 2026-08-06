#ifndef ROBUSTAL_H
#define ROBUSTAL_H
#include <cstdint>

using Bitboard = uint64_t;

enum columns {
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6,
    H = 7,
};

enum pieces {
    whitePawn = 0,
    blackPawn = 1,
    whiteRook = 2,
    blackRook = 3,
    whiteKnight = 4,
    blackKnight = 5,
    whiteBishop = 6,
    blackBishop = 7,
    whiteQueen = 8,
    blackQueen = 9,
    whiteKing = 10,
    blackKing = 11
};

class Board {
    public:
    Board();
    //Initial position of each piece by type
        Bitboard whitePawns     =   0x000000000000FF00ULL;
        Bitboard blackPawns     =   0x00FF000000000000ULL;
        Bitboard whiteRooks     =   0x0000000000000081ULL;
        Bitboard blackRooks     =   0x8100000000000000ULL;
        Bitboard whiteKnights   =   0x0000000000000042ULL;
        Bitboard blackKnights   =   0x4200000000000000ULL;
        Bitboard whiteBishops   =   0x0000000000000024ULL;
        Bitboard blackBishops   =   0x2400000000000000ULL;
        Bitboard whiteQueens    =   0x0000000000000008ULL;
        Bitboard blackQueens    =   0x0800000000000000ULL;
        Bitboard whiteKing      =   0x0000000000000010ULL;
        Bitboard blackKing      =   0x1000000000000000ULL;

        void maskGeneration(); //Generates all the masks needed (movement, rows, columns, squares...)

        void updateBoard(); //Updates derived board masks

    private:
        Bitboard occupied;
        Bitboard empty;
        Bitboard blackPieces;
        Bitboard whitePieces;

        Bitboard squares[64];
        Bitboard rows[8];
        Bitboard cols[8];
        Bitboard diagonals[64][4];


};


#endif