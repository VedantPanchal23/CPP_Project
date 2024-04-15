int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;

    cout << "Tic Tac Toe - Computer Wins!" << endl;
    cout << "Player: X, Computer: O" << endl;

    // Main game loop
    while (true)
    {
        // Player's move
        cout << "Enter your move (row column): ";
        cin >> row >> col;
        row--; // Adjust for 0-based indexing
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = 'X';
        displayBoard(board);

        if (checkWin(board, 'X'))
        {
            cout << "Congratulations! You won!" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            cout << "It's a draw!" << endl;
            break;
        }

        // Computer's move
        cout << "Computer's move:" << endl;
        computerMove(board);
        displayBoard(board);

        if (checkWin(board, 'O'))
        {
            cout << endl
                 << "Computer wins!" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            cout << endl
                 << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
