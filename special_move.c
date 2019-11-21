#include <stdio.h>
#include "tipe_bentukan.h"
#include "stack.h"



void enPassant(piece P, stack* history)
{
  //  if (TOP(history) = );

}
/*

boolean HasMoved(piece P, stack history)
{
    int counter = 1;
    boolean Moved = false;

    infotype_stack X;
    
    while ((!Moved) && (counter < (history.T[(history).TOP].turn))){   
        X = (history).T[(history).TOP];
        history.TOP--;
    
        if (X.nama == P.nama){
            Moved = true;
        }

       counter++;
    }

    return Moved;
}

void Castling(piece Raja, piece Benteng , stack history, papan* board[10][10])
{
    if (!(HasMoved(Raja,history)))
    {
        if (((*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ') && ((*board[Raja.posisiR][Raja.posisiC+1]).nama == " ") && (!(HasMoved(Benteng, history))))
        {
            (*board[Raja.posisiR][Raja.posisiC+2]).nama == ' ';
        }
    }
*/