bool checkWin(const vector<vector<char>> &board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Horizontal win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Vertical win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}