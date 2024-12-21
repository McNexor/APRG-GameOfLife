#include "gameoflife.h"

struct Board {
    std::vector<std::vector<char>> board;

    Board() {
        board = std::vector<std::vector<char>>();
    }

    Board(std::vector<std::vector<char>> board) : board{board} {}
};

std::vector<std::vector<char>> readBoardInputFile(std::string filename) {

    // Read input file

    return std::vector<std::vector<char>>();
}

void writeBoardOutputFile(Board &board, std::string filename) {

    // Write board state to file

}

int countAliveNeighbors(Board &board, size_t row, size_t column) {

    // Count the number of neighboring, alive cells

    return 0;
}

void updateCell(Board &board, size_t row, size_t column) {
    int aliveCount = countAliveNeighbors(board,row,column);
    
    // Apply Game rules and update cell

}

void calculateNextBoard(Board &previousBoard, Board &nextBoard) {
    size_t rows = previousBoard.board.size();
    size_t columns = previousBoard.board[0].size();

    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < columns; ++col) {
            updateCell(nextBoard, row, col);
        }
    }
}
