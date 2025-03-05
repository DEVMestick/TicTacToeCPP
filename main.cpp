#include <iostream> // Including the header file for input/output operations.

using namespace std;

// A 3x3 matrix representing the Tic-Tac-Toe board, initialized with characters '1' to '9'.
char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X'; // Variable to store the current player's symbol ('X' or 'O').

// Function to print the current state of the board.
void printBoard()
{
    cout << "\n"; // Print a newline for better formatting.
    for (int i = 0; i < 3; i++)
    { // Loop through the rows of the matrix.
        for (int j = 0; j < 3; j++)
        {                                       // Loop through the columns of the matrix.
            cout << " " << matrix[i][j] << " "; // Print each cell value.
            if (j < 2)
                cout << "|"; // Add a vertical divider if not the last column.
        }
        cout << "\n"; // Print a newline after each row.
        if (i < 2)
            cout << "---+---+---\n"; // Add a horizontal divider if not the last row.
    }
    cout << "\n"; // Print a final newline for formatting.
}

// Function to check if there is a winner.
bool checkWin()
{
    for (int i = 0; i < 3; i++)
    { // Check each row for three equal marks.
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return true;
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return true;
    }
    // Check both diagonals for three equal marks.
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return true;
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return true;
    return false; // Return false if no winner is found.
}

// Function to check if the game is a draw (no empty cells left).
bool isDraw()
{
    for (int i = 0; i < 3; i++)
    { // Loop through the rows.
        for (int j = 0; j < 3; j++)
        { // Loop through the columns.
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                return false; // Check if any cell is still empty.
        }
    }
    return true; // Return true if all cells are filled.
}

// Function to handle the player's move.
void makeMove()
{
    int move; // Variable to store the player's chosen position.
    cout << "Player " << player << ", choose a position: ";
    cin >> move; // Get the player's input.

    // Check if the move is within valid bounds (1 to 9).
    if (move < 1 || move > 9)
    {
        cout << "Invalid move! Try again.\n";
        makeMove(); // Recursively prompt for a valid move.
        return;
    }

    // Calculate the row and column based on the move number (1 to 9).
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    // Check if the chosen position is already occupied.
    if (matrix[row][col] == 'X' || matrix[row][col] == 'O')
    {
        cout << "Position occupied! Choose another.\n";
        makeMove(); // Recursively prompt for a new move.
    }
    else
    {
        matrix[row][col] = player; // Update the board with the player's symbol.
    }
}

// Function to switch the current player.
void switchPlayer()
{
    player = (player == 'X') ? 'O' : 'X'; // Switch between 'X' and 'O'.
}

// Main function to run the Tic-Tac-Toe game.
int main()
{
    while (true)
    {
        printBoard(); // Print the current board.
        makeMove();   // Get and apply the player's move.

        // Check if the current player has won.
        if (checkWin())
        {
            printBoard();                              // Print the final board.
            cout << "Player " << player << " wins!\n"; // Announce the winner.
            break;                                     // End the game.
        }

        // Check if the game is a draw.
        if (isDraw())
        {
            printBoard();      // Print the final board.
            cout << "Draw!\n"; // Announce a draw.
            break;             // End the game.
        }

        switchPlayer(); // Switch to the next player.
    }
    return 0; // End the program.
}
