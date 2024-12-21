#include<vector>
#include<string>
#include <fstream>

const char ALIVE = 'x';
const char DEAD = '.';

const int DROW[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DCOL[] = {-1, 0, 1, -1, 1, -1, 0, 1};

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