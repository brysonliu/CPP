<<<<<<< HEAD
#ifndef Chess_hpp
#define Chess_hpp

#include "Piece.hpp"

const int BOARD_SIZE = 8;

// pieces
const char ROOK = 'R';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char QUEEN = 'Q';
const char KING = 'K';

class Chess
{
    public:
        Chess();
        ~Chess();

        void play();
        void makeChessPiece();
        void drawBoard();
    
    private:
        Piece* mPtrPiece;

        int askInt(int min, int max);
        char askType();
        bool isValidType(char pieceType);
};

=======
#ifndef Chess_hpp
#define Chess_hpp

#include "Piece.hpp"

const int BOARD_SIZE = 8;

// pieces
const char ROOK = 'R';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char QUEEN = 'Q';
const char KING = 'K';

class Chess
{
    public:
        Chess();
        ~Chess();

        void play();
        void makeChessPiece();
        void drawBoard();
    
    private:
        Piece* mPtrPiece;

        int askInt(int min, int max);
        char askType();
        bool isValidType(char pieceType);
};

>>>>>>> 10c4515a0cea5087ab530601e4f13d8aefd39cd3
#endif