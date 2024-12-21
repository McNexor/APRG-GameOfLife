#include "gameoflife.h"

int main() {

    std::string inputFilename = "";
    std::string outputFilename = "";

    int generations = 100;

    std::vector<std::vector<char>> inputBoard = readBoardInputFile(inputFilename);

    Board previousBoard(inputBoard);

    Board nextBoard(inputBoard);

    for (int i = 0; i < generations; ++i) {
        calculateNextBoard(previousBoard, nextBoard);
        std::swap(previousBoard, nextBoard);
    }

    writeBoardOutputFile(previousBoard, outputFilename);

    return 0;
}