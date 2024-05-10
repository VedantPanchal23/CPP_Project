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
