#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 3

// Global board
char board[SIZE][SIZE];

// Function prototypes
void initBoard();
void printBoard();
bool isMoveValid(int row, int col);
void makeMove(int row, int col, char player);
char checkWinner();
bool isBoardFull();
int evaluateBoard();
bool isMovesLeft();
int minimax(int depth, bool isMax);
void findBestMove();
void playGame(int mode);

int main() {
    int choice;
    
    printf("╔═══════════════════════════════╗\n");
    printf("║    TIC-TAC-TOE GAME IN C     ║\n");
    printf("╚═══════════════════════════════╝\n\n");
    
    printf("Select Game Mode:\n");
    printf("1. Human vs Human\n");
    printf("2. Human vs Computer\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice == 1 || choice == 2) {
        playGame(choice);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    printf("     0   1   2\n");
    printf("   ╔═══╦═══╦═══╗\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %d ║", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("║");
        }
        printf("║\n");
        if (i < SIZE - 1) {
            printf("   ╠═══╬═══╬═══╣\n");
        }
    }
    printf("   ╚═══╩═══╩═══╝\n\n");
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

void makeMove(int row, int col, char player) {
    if (isMoveValid(row, col)) {
        board[row][col] = player;
    }
}

char checkWinner() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    
    return ' ';
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int evaluateBoard() {
    char winner = checkWinner();
    if (winner == 'X') return 10;
    if (winner == 'O') return -10;
    return 0;
}

bool isMovesLeft() {
    return !isBoardFull();
}

int minimax(int depth, bool isMax) {
    int score = evaluateBoard();
    
    // Terminal conditions
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (!isMovesLeft()) return 0;
    
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int val = minimax(depth + 1, false);
                    best = (val > best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int val = minimax(depth + 1, true);
                    best = (val < best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void findBestMove() {
    int bestVal = INT_MIN;
    int bestRow = -1, bestCol = -1;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int moveVal = minimax(0, false);
                board[i][j] = ' ';
                
                if (moveVal > bestVal) {
                    bestRow = i;
                    bestCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    
    printf("Computer plays: (%d, %d)\n", bestRow, bestCol);
    makeMove(bestRow, bestCol, 'X');
}

void playGame(int mode) {
    initBoard();
    char currentPlayer = 'O';
    char winner;
    int row, col;
    
    printf("\nGame Start!\n");
    printf("Player O: You\n");
    if (mode == 2) {
        printf("Player X: Computer (AI)\n");
    } else {
        printf("Player X: Player 2\n");
    }
    
    while (true) {
        printBoard();
        
        winner = checkWinner();
        if (winner != ' ') {
            if (winner == 'O') {
                printf("🎉 Player O wins! 🎉\n");
            } else {
                if (mode == 2) {
                    printf("💻 Computer wins! Better luck next time!\n");
                } else {
                    printf("🎉 Player X wins! 🎉\n");
                }
            }
            break;
        }
        
        if (isBoardFull()) {
            printf("🤝 It's a draw! 🤝\n");
            break;
        }
        
        if (currentPlayer == 'O') {
            printf("Player O's turn (You)\n");
            printf("Enter row (0-2): ");
            scanf("%d", &row);
            printf("Enter col (0-2): ");
            scanf("%d", &col);
            
            if (isMoveValid(row, col)) {
                makeMove(row, col, currentPlayer);
                currentPlayer = 'X';
            } else {
                printf("Invalid move! Try again.\n");
            }
        } else {
            if (mode == 2) {
                printf("Computer's turn...\n");
                findBestMove();
                currentPlayer = 'O';
            } else {
                printf("Player X's turn\n");
                printf("Enter row (0-2): ");
                scanf("%d", &row);
                printf("Enter col (0-2): ");
                scanf("%d", &col);
                
                if (isMoveValid(row, col)) {
                    makeMove(row, col, currentPlayer);
                    currentPlayer = 'O';
                } else {
                    printf("Invalid move! Try again.\n");
                }
            }
        }
    }
    
    printBoard();
    printf("\nThanks for playing!\n");
}
