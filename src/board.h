#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>

class board {
    public:
    //Etiquetas de piezas. Para legibilidad
        enum Pieces {
            EMPTY,
            W_PAWN,
            B_PAWN,
            W_ROOK,
            B_ROOK,
            W_KNIGHT,
            B_KNIGHT,
            W_JUICER,
            B_JUICER,
            W_KING,
            B_KING,
            W_QUEEN,
            B_QUEEN
        };
    
    //Declaración del estado interno inicial del tablero
    //Por ahora no debe ser el objeto    
        int boardMatrix[8][8] = {
            {B_ROOK,   B_KNIGHT, B_JUICER, B_QUEEN, B_KING, B_JUICER, B_KNIGHT, B_ROOK},
            {B_PAWN,   B_PAWN,   B_PAWN,   B_PAWN,  B_PAWN, B_PAWN,   B_PAWN,   B_PAWN},
            {EMPTY,    EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,    EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,    EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,    EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {W_PAWN,   W_PAWN,   W_PAWN,   W_PAWN,  W_PAWN, W_PAWN,   W_PAWN,   W_PAWN},
            {W_ROOK,   W_KNIGHT, W_JUICER, W_QUEEN, W_KING, W_JUICER, W_KNIGHT, W_ROOK}
        };

        void printBoard() {
            for (int i = 0; i <= 7; i++) {
                std::cout << "\n" << 8-i << "  ";
                for (int j = 0; j <= 7; j++) {
                    std::cout << ' ' << readSquare(boardMatrix[i][j]);
                }
            }
            std::cout << "\n\n    A B C D E F G H"; 
        }

        /*La cadena de texto "e2 e4" se descompone:
        en columna y fila de origen a destino*/
        void movePiece() {

        }
        
    private:
        //Me devuelve el tablero como caracteres PROVISIONALMENTE    
        char readSquare(int p_sq) {
            switch (p_sq) {
                case 0:
                return ' ';
                break;
                case 1:
                return 'P';
                break;
                case 2:
                return 'p';
                break;
                case 3:
                return 'R';
                break;
                case 4:
                return 'r';
                break;
                case 5:
                return 'N';
                break;
                case 6:
                return 'n';
                break;
                case 7:
                return 'B';
                break;
                case 8:
                return 'b';
                break;
                case 9:
                return 'K';
                break;
                case 10:
                return 'k';
                break;
                case 11:
                return 'Q';
                break;
                case 12:
                return 'q';
                break;
                default:
                return 'e';
                break;
            }
        }

        std::array<int, 4> moveInput() {
            std::string movement;

            std::cout << "Indique movimiento: ";
            std::cin >> movement;
            
            int origCol = movement[0];
            int origRow = 8 - (movement[1] - 'a');
            int destCol = movement[3];
            int destRow = 8 - (movement[4] - 'a');

            return { origCol,
                origRow,
                destCol,
                destRow
            };
        }

        
};

//int origCol, origRow, destCol, destRow;

#endif