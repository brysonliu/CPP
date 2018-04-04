<<<<<<< HEAD
#include "Chess.hpp"
#include "Piece.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Piece::Piece(int row, int column, char type)
{
    cout << endl << "Piece object crated at: " << this << endl << endl;
    mRow = row;
    mColumn = column;
    mType = type;
    this->print();
}

Piece::~Piece()
{
    cout << endl << "Piece object deleted at: " << this << endl;
}

void Piece::print()
{
    cout << "Type: " << mType << endl;
    cout << "Row: " << mRow << endl;
    cout << "Column: " << mColumn << endl;
}

char Piece::getSymbolAt(int row, int column)
{
    if (row == mRow && column == mColumn)
    {
        return mType;
    }

    int rowDiff = mRow - row;
    int columnDiff = mColumn - column;

    switch (mType)
    {
        case ROOK:
            if (column == mColumn ||
                row == mRow)
            {
                return 'X';
            }
            break;
            
        case BISHOP:
            if (columnDiff + rowDiff == 0 ||
                columnDiff == rowDiff)
            {
                return 'X';
            }
            break;
            
        case QUEEN:
            if (column == mColumn ||
                row == mRow ||
                columnDiff + rowDiff == 0 ||
                columnDiff == rowDiff)
            {
                return 'X';
            }
            break;
            
        case KING:
            if (column >= mColumn - 1 &&
                column <= mColumn + 1 &&
                row >= mRow - 1 &&
                row <= mRow + 1)
            {
                return 'X';
            }
            break;
            
        case KNIGHT:
            if (columnDiff * columnDiff + rowDiff * rowDiff == 5)
            {
                return 'X';
            }
            break;
    }

    return ' ';
}

int Piece::getRow()
{
    return mRow;
}

int Piece::getColumn()
{
    return mColumn;
}

char Piece::getType()
{
    return mType;
=======
#include "Chess.hpp"
#include "Piece.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Piece::Piece(int row, int column, char type)
{
    cout << endl << "Piece object crated at: " << this << endl << endl;
    mRow = row;
    mColumn = column;
    mType = type;
    this->print();
}

Piece::~Piece()
{
    cout << endl << "Piece object deleted at: " << this << endl;
}

void Piece::print()
{
    cout << "Type: " << mType << endl;
    cout << "Row: " << mRow << endl;
    cout << "Column: " << mColumn << endl;
}

char Piece::getSymbolAt(int row, int column)
{
    if (row == mRow && column == mColumn)
    {
        return mType;
    }

    int rowDiff = mRow - row;
    int columnDiff = mColumn - column;

    switch (mType)
    {
        case ROOK:
            if (column == mColumn ||
                row == mRow)
            {
                return 'X';
            }
            break;
            
        case BISHOP:
            if (columnDiff + rowDiff == 0 ||
                columnDiff == rowDiff)
            {
                return 'X';
            }
            break;
            
        case QUEEN:
            if (column == mColumn ||
                row == mRow ||
                columnDiff + rowDiff == 0 ||
                columnDiff == rowDiff)
            {
                return 'X';
            }
            break;
            
        case KING:
            if (column >= mColumn - 1 &&
                column <= mColumn + 1 &&
                row >= mRow - 1 &&
                row <= mRow + 1)
            {
                return 'X';
            }
            break;
            
        case KNIGHT:
            if (columnDiff * columnDiff + rowDiff * rowDiff == 5)
            {
                return 'X';
            }
            break;
    }

    return ' ';
}

int Piece::getRow()
{
    return mRow;
}

int Piece::getColumn()
{
    return mColumn;
}

char Piece::getType()
{
    return mType;
>>>>>>> 10c4515a0cea5087ab530601e4f13d8aefd39cd3
}