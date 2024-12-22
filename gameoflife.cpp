#include "gameoflife.h"

Board::Board() {
    board = std::vector<std::vector<char>>();
}

std::vector<std::vector<char>> readBoardInputFile(const std::string filename) {

    int rowLength = 0;
    int columnLength = 0;
    std::ifstream inputFile(filename);
    std::string line;

    std::getline(inputFile, line);
    sscanf(line.c_str(), "%d,%d", &rowLength, &columnLength);

    auto board = std::vector<std::vector<char>>(columnLength, std::vector<char>(rowLength, DEAD));

    for (int i = 0; i < columnLength; ++i) {
        std::getline(inputFile, line);
        for (int j = 0; j < rowLength; ++j) {
            board[i][j] = line[j];
        }
    }

    return board;
}

void writeBoardOutputFile(const Board &board, const std::string outputFilename) {

    std::ofstream outputFile(outputFilename);
    int rows = board.board[0].size();
    int columns = board.board.size();

    outputFile << rows << "," << columns << std::endl;

    for (const auto& row : board.board) {
        for (const char cell : row) {
            outputFile << cell;
        }
        outputFile << std::endl;
    }

    outputFile.close();

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

}

void updateCell(Board &board, const int aliveCount, const size_t row, const size_t column) {
        
    if (aliveCount == 3 || (board.board[row][column] == ALIVE && aliveCount == 2)) 
        board.board[row][column] = ALIVE;
    else {
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

void calculateNextBoardParallel(const Board &previousBoard, Board &nextBoard) {
    size_t rows = previousBoard.board.size();
    size_t columns = previousBoard.board[0].size();

    #pragma omp parallel for shared(rows, columns, previousBoard, nextBoard)
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < columns; ++col) {

            int aliveCount = 0;

            for (int i = 0; i < 8; ++i) {
                int nextRow = (row + DROW[i] + rows) % rows;
                int nextCol = (col + DCOL[i] + columns) % columns;
                if (previousBoard.board[nextRow][nextCol] == ALIVE) {
                    ++aliveCount;
                }
            }

            if (aliveCount == 3 || (previousBoard.board[row][col] == ALIVE && aliveCount == 2)) 
                nextBoard.board[row][col] = ALIVE;
            else {
                nextBoard.board[row][col] = DEAD;
            }
        }
    }
}
