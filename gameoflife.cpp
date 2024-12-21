#include "gameoflife.h"

Board::Board() {
    board = std::vector<std::vector<char>>();
}

std::vector<std::vector<char>> readBoardInputFile(std::string filename) {

    int rows = 0;
    int columns = 0;
    std::ifstream inputFile(filename);
    std::string line;

    std::getline(inputFile, line);
    sscanf(line.c_str(), "%d,%d", rows, columns);

    std::vector<std::vector<char>> board = std::vector<std::vector<char>>(rows, std::vector<char>(columns, '.'));

    for (int i = 0; i < rows; ++i) {
        std::getline(inputFile, line);
        for (int j = 0; j < columns; ++j) {
            board[i][j] = line[j];
        }
    }

    return board;
}

void writeBoardOutputFile(const Board &board, std::string filename) {

    // Write board state to file

}

int countAliveNeighbors(const Board &board, size_t row, size_t column) {

    // Count the number of neighboring, alive cells

    return 0;
}

void updateCell(Board &board, size_t row, size_t column) {
    int aliveCount = countAliveNeighbors(board,row,column);
    
    // Apply Game rules and update cell

}

void calculateNextBoard(const Board &previousBoard, Board &nextBoard) {
    size_t rows = previousBoard.board.size();
    size_t columns = previousBoard.board[0].size();

    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < columns; ++col) {
            updateCell(nextBoard, row, col);
        }
    }
}
