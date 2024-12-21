#include "gameoflife.h"

struct Config {
    std::string inputFile;
    std::string outputFile;
    int generations;
    bool measure;
};

Config parseArguments(const int argc, const char* argv[]) {
    Config config;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--load" && i + 1 < argc) {
            config.inputFile = argv[++i];
        } else if (arg == "--save" && i + 1 < argc) {
            config.outputFile = argv[++i];
        } else if (arg == "--generations" && i + 1 < argc) {
            config.generations = std::stoi(argv[++i]);
        } else if (arg == "--measure") {
            config.measure = true;
        }
    }
    return config;
}

int main(int argc, char* argv[]) {

    Config config = parseArguments(argc, argv);

    std::vector<std::vector<char>> inputBoard = readBoardInputFile(config.inputFile);

    Board previousBoard(inputBoard);

    Board nextBoard(inputBoard);

    for (int i = 0; i < config.generations; ++i) {
        calculateNextBoard(previousBoard, nextBoard);
        std::swap(previousBoard, nextBoard);
    }

    writeBoardOutputFile(previousBoard, config.outputFile);

    return 0;
}