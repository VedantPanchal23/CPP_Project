#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>> &board)
{
    /*for (int i = 0; i < 3; ++i) {
            // cout << "-";
        // cout<< "| ";
        for (int j = 0; j < 3; ++j) {
            cout <<board[i][j] << "|" <<" ";
        }
        cout << endl;
    }*/
    cout << "  1   2   3\n";

    for (int i = 0; i < 3; ++i)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "  ---------\n";
    }
}

// Function to check if a player has won
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

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move for the computer
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
            cout << endl <<"Computer wins!" << endl;
            break;
        }

        if (isBoardFull(board))
        {
            cout <<endl <<"It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
