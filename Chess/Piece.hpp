<<<<<<< HEAD
#ifndef Piece_hpp
#define Piece_hpp

class Piece
{
    public:
        Piece(int row, int column, char type);
        ~Piece();

        void print();
        char getSymbolAt(int row, int column);

        int getRow();
        int getColumn();
        char getType();

    private:
        int mRow;
        int mColumn;
        char mType;
};

=======
#ifndef Piece_hpp
#define Piece_hpp

class Piece
{
    public:
        Piece(int row, int column, char type);
        ~Piece();

        void print();
        char getSymbolAt(int row, int column);

        int getRow();
        int getColumn();
        char getType();

    private:
        int mRow;
        int mColumn;
        char mType;
};

>>>>>>> 10c4515a0cea5087ab530601e4f13d8aefd39cd3
#endif