#include "gameoflife.h"

Board::Board() {
    board = std::vector<std::vector<char>>();
}

std::vector<std::vector<char>> readBoardInputFile(const std::string filename) {

    int rows = 0;
    int columns = 0;
    std::ifstream inputFile(filename);
    std::string line;

    std::getline(inputFile, line);
    sscanf(line.c_str(), "%d,%d", rows, columns);

    std::vector<std::vector<char>> board = std::vector<std::vector<char>>(rows, std::vector<char>(columns, DEAD));

    for (int i = 0; i < rows; ++i) {
        std::getline(inputFile, line);
        for (int j = 0; j < columns; ++j) {
            board[i][j] = line[j];
        }
    }

    return board;
}

void writeBoardOutputFile(const Board &board, const std::string filename) {

    // Write board state to file

}

int countAliveNeighbors(const Board &board, const size_t row, const size_t column) {

    int rows = board.board.size();
    int columns = board.board[0].size();
    int count = 0;

    for (int i = 0; i < 8; ++i) {
        int nextRow = (row + DROW[i] + rows) % rows;
        int nextCol = (column + DCOL[i] + columns) % columns;
        if (board.board[nextRow][nextCol] == ALIVE) {
            ++count;
        }
    }
    return count;

    return 0;
}

void updateCell(Board &board, const int aliveCount, const size_t row, const size_t column) {
        
    if (board.board[row][column] == ALIVE && (aliveCount == 2 || aliveCount == 3)) 
        board.board[row][column] = ALIVE;
    else {
        if (board.board[row][column] == DEAD && aliveCount == 3) 
            board.board[row][column] = ALIVE;
        else 
            board.board[row][column] = DEAD;
    }

}

void calculateNextBoard(const Board &previousBoard, Board &nextBoard) {
    size_t rows = previousBoard.board.size();
    size_t columns = previousBoard.board[0].size();

    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < columns; ++col) {
            int aliveCount = countAliveNeighbors(previousBoard,row,col);
            updateCell(nextBoard, aliveCount, row, col);
        }
    }
}
