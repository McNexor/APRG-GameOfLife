#include "gameoflife.h"
#include "Timing.h"

#include<omp.h>
#include<iostream>

struct Config {
    std::string inputFile;
    std::string outputFile;
    int generations;
    bool openmp;
    int threadnum;
    bool measure;
};

Config parseArguments(int argc, char* argv[]) {
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
        } else if (arg == "--mode" && i + 1 < argc) {
            std::string mode = argv[++i];
            if (mode == "omp")
                config.openmp = true;
            else
                config.openmp = false;
        } else if (arg == "--threads" && i + 1 < argc) {
            config.threadnum = std::stoi(argv[++i]);
        }
    }
    return config;
}

int main(int argc, char* argv[]) {

    Timing *timing = Timing::getInstance();
    timing->startSetup();

    Config config = parseArguments(argc, argv);

    std::vector<std::vector<char>> inputBoard = readBoardInputFile(config.inputFile);

    Board previousBoard(inputBoard);
    Board nextBoard(inputBoard);

    timing->stopSetup();

    
    timing->startComputation();

    if (!config.openmp) {

        for (int i = 0; i < config.generations; ++i) {
            calculateNextBoard(previousBoard, nextBoard);
            previousBoard.board = nextBoard.board;
        }

    }
    else {

        omp_set_num_threads(config.threadnum);

        for (int i = 0; i < config.generations; ++i) {
            calculateNextBoardParallel(previousBoard, nextBoard);
            previousBoard.board = nextBoard.board;
        }

    }

    timing->stopComputation();
    timing->startFinalization();

    writeBoardOutputFile(previousBoard, config.outputFile);

    timing->stopFinalization();

    if (config.measure)
        std::cout << timing->getResults() << std::endl;

    return 0;
}