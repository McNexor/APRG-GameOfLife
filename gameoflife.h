#include<vector>
#include<string>

struct Board {
    std::vector<std::vector<char>> board;

    Board();

    Board(std::vector<std::vector<char>> board) : board{board} {}
};

std::vector<std::vector<char>> readBoardInputFile(std::string filename);

void writeBoardOutputFile(Board &board, std::string filename);

int countAliveNeighbors(Board &board, size_t row, size_t column);

void updateCell(Board &board, size_t row, size_t column);

void calculateNextBoard(Board &previousBoard, Board &nextBoard);