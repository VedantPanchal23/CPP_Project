void computerMove(vector<vector<char>> &board)
{
    int row, col;
    // Check if there is a winning move for the computer
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                if (checkWin(board, 'O'))
                {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if there is a winning move for the player, and block it
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'X';
                if (checkWin(board, 'X'))
                {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Choose a random empty cell
    srand(time(nullptr));
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}
