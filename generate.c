#include "generate.h"
#include "vector.h"

bool nextCellToFill(char board[9][9], Point* position) {

    //search for the first unknown cell. can be chosen more intelligently
    int col, row;
    for (col=0; col < 9; col++){
        for (row=0; row < 9; row++){
            if (board[row][col] == '.')
            {
                position->y = row;
                position->x = col;
                return true;
            }
        }
    }
    return false;
}

char getNumberToInsert(char board[9][9], char possibilities[9][9], Point* position,){
    // loop over everything that is still possible
    // insert first one (something smarter is also possible)
   
    // rank options
    
    // return ranked options, best one first.
    return possibilities[position->y][position->x];

}

void getPossibilities(char board[9][9], vector* possibilities[9][9]){
    // calc possibilities with board
    
    int i, j, row, col;
    vector* testVect
    // loop over all fixed board numbers to initialize possibilities
    for (row = 0; row < 9; row ++){
        for (col = 0; col < 9; col ++) {
            if (board[col][row] != '.') {
                // vector_free(possibilities[col][row]);
                // Null or 'x' for no possibility? choose Null;

                // check current col
                for (i = 1; i < 9 i++)
                    vector_delete_element_with_value(possibilities[(col + i) % 9][row], board[col][row])

                // check current row
                for (i = 1; i < 9 i++)
                    vector_delete_element_with_value(possibilities[(col)][(row + i) % 9], board[col][row])

                // check current box
                for (i = (col/3)*3, i < (col/3 + 1)*3, i++){
                    for (j = (row/3)*3, j < (row/3 +1)*3, j++){
                        vector_delete_element_with_value(possibilities[(col)][(row + i) % 9], board[col][row])
                    }
                }

                // vector_init(possibilities[col][row]);
            }
        }
    }

}

bool solve(char board[9][9]) {
    vector possibilities[9][9];
    char options;

    int col, row;
    Point pos;
    pos.x = 0;
    pos.y = 0;
    if (nextCellToFill(board, &pos))
    {
        // printf("position %d, %d, value %c \n", row, col, board[row][col]);
        // options is a vector
        options = getNumberToInsert(board, possibilities, &pos);
        while (options.next) {
            board[pos.x][pos.y] = options;
            // solve cells that are currently empty
            if (solve(board)== true)
                return true;
        }
        return false
    }

    return true;
}
