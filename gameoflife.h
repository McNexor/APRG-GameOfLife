#include<vector>
#include<string>
#include <fstream>

struct Board {
    std::vector<std::vector<char>> board;

    Board();

    Board(std::vector<std::vector<char>> board) : board{board} {}
};

std::vector<std::vector<char>> readBoardInputFile(std::string filename);

void writeBoardOutputFile(const Board &board, std::string filename);

int countAliveNeighbors(const Board &board, size_t row, size_t column);

void updateCell(Board &board, size_t row, size_t column);

void calculateNextBoard(const Board &previousBoard, Board &nextBoard);