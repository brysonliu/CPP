<<<<<<< HEAD
#include "Chess.hpp"
#include "Piece.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Chess::Chess() //constructor
{
    cout << endl << "Chess object created at: " << this << endl;
}

Chess::~Chess() //destructor
{
    delete mPtrPiece;
    cout << endl << "Chess object deleted at: " << this << endl << endl;
}

void Chess::play()
{
    makeChessPiece();
    drawBoard();
}

void Chess::makeChessPiece()
{
    // ask mPtrPiece->getRow()
    cout << endl;
    cout << "Which row is your chess piece located?" << endl;
    int row = askInt(1, BOARD_SIZE);
    
    // ask mPtrPiece->getColumn()
    cout << endl;
    cout << "Which column is your chess piece located?" << endl;
    int column = askInt(1, BOARD_SIZE);
    
    // ask mPtrPiece->getType()
    cout << endl;
    cout << "Type \n" << ROOK << " for a Rook attack, " << endl;
    cout << KNIGHT << " for a Knight attack, " << endl;
    cout << BISHOP << " for a Bishop attack, " << endl;
    cout << QUEEN << " for a Queen attack, " << endl;
    cout << KING << " for a King attack." << endl;
    int type = askType();
    
    mPtrPiece = new Piece(row, column, type);
}

int Chess::askInt(int min, int max)
{
    int value = 0;
    while (true)
    {
        cout << "Enter an integer between " << min << " and " << max << ": ";
        cin >> value;
        if (value >= min && value <= max)
        {
            return value;
        }

        cout << endl;
        cout << "Invalid value. Enter again." << endl;
    }
}

bool Chess::isValidType(char pieceType)
{
    if (pieceType == ROOK ||
        pieceType == KNIGHT ||
        pieceType == BISHOP ||
        pieceType == QUEEN ||
        pieceType == KING)
    {
        return true;
    }

    return false;
}

char Chess::askType()
{
    while (true)
    {
        char type;
        cout << "Enter a letter for the piece type: ";
        cin >> type;
        type = toupper(type);

        if (isValidType(type))
        {
            return type;
        }

        cout << endl;
        cout << "Invalid type. Enter again." << endl;
    }
}

void Chess::drawBoard()
{
    cout << "\n   1 2 3 4 5 6 7 8\n";
    
    int indexRow, indexColumn, rowDiff, columnDiff;
    
    for (indexRow = 1; indexRow <= BOARD_SIZE; ++indexRow)
    {
        // print two spaces and then the mPtrPiece->getRow() number
        cout << setw(2) << indexRow;
        
        for (indexColumn = 1; indexColumn <= BOARD_SIZE; ++indexColumn)
        {
            char drawChar = mPtrPiece->getSymbolAt(indexRow, indexColumn);

            if (drawChar == ' ')
            {
                if ((indexColumn + indexRow)%2 == 0)
                {
                    // black square
                    cout << " -";
                }
                else
                {
                    // white square
                    cout << " .";
                }
            }
            else
            {
                cout << " " << drawChar;
            }            
        }
        
        cout << endl;
    }
=======
#include "Chess.hpp"
#include "Piece.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Chess::Chess() //constructor
{
    cout << endl << "Chess object created at: " << this << endl;
}

Chess::~Chess() //destructor
{
    delete mPtrPiece;
    cout << endl << "Chess object deleted at: " << this << endl << endl;
}

void Chess::play()
{
    makeChessPiece();
    drawBoard();
}

void Chess::makeChessPiece()
{
    // ask mPtrPiece->getRow()
    cout << endl;
    cout << "Which row is your chess piece located?" << endl;
    int row = askInt(1, BOARD_SIZE);
    
    // ask mPtrPiece->getColumn()
    cout << endl;
    cout << "Which column is your chess piece located?" << endl;
    int column = askInt(1, BOARD_SIZE);
    
    // ask mPtrPiece->getType()
    cout << endl;
    cout << "Type \n" << ROOK << " for a Rook attack, " << endl;
    cout << KNIGHT << " for a Knight attack, " << endl;
    cout << BISHOP << " for a Bishop attack, " << endl;
    cout << QUEEN << " for a Queen attack, " << endl;
    cout << KING << " for a King attack." << endl;
    int type = askType();
    
    mPtrPiece = new Piece(row, column, type);
}

int Chess::askInt(int min, int max)
{
    int value = 0;
    while (true)
    {
        cout << "Enter an integer between " << min << " and " << max << ": ";
        cin >> value;
        if (value >= min && value <= max)
        {
            return value;
        }

        cout << endl;
        cout << "Invalid value. Enter again." << endl;
    }
}

bool Chess::isValidType(char pieceType)
{
    if (pieceType == ROOK ||
        pieceType == KNIGHT ||
        pieceType == BISHOP ||
        pieceType == QUEEN ||
        pieceType == KING)
    {
        return true;
    }

    return false;
}

char Chess::askType()
{
    while (true)
    {
        char type;
        cout << "Enter a letter for the piece type: ";
        cin >> type;
        type = toupper(type);

        if (isValidType(type))
        {
            return type;
        }

        cout << endl;
        cout << "Invalid type. Enter again." << endl;
    }
}

void Chess::drawBoard()
{
    cout << "\n   1 2 3 4 5 6 7 8\n";
    
    int indexRow, indexColumn, rowDiff, columnDiff;
    
    for (indexRow = 1; indexRow <= BOARD_SIZE; ++indexRow)
    {
        // print two spaces and then the mPtrPiece->getRow() number
        cout << setw(2) << indexRow;
        
        for (indexColumn = 1; indexColumn <= BOARD_SIZE; ++indexColumn)
        {
            char drawChar = mPtrPiece->getSymbolAt(indexRow, indexColumn);

            if (drawChar == ' ')
            {
                if ((indexColumn + indexRow)%2 == 0)
                {
                    // black square
                    cout << " -";
                }
                else
                {
                    // white square
                    cout << " .";
                }
            }
            else
            {
                cout << " " << drawChar;
            }            
        }
        
        cout << endl;
    }
>>>>>>> 10c4515a0cea5087ab530601e4f13d8aefd39cd3
}