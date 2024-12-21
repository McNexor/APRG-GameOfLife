# APRG-GameOfLife

This project implements Conway's Game of Life in C++ for the Course Advanced Programming. It simulates cellular automaton dynamics based on a predefined grid, where each cell's state is determined by its neighbors' states. 

## Features

- **Configurable Input:** Reads the initial game board from a file.
- **Generations Simulation:** Simulates multiple generations based on Conway's rules.
- **Wrap-Around Logic:** The grid is treated as a toroidal surface (edges wrap around).
- **Performance Measurement:** Measures setup, computation, and finalization times using the `Timing` utility.

## Prerequisites

- C++17 or later.
- A compiler such as `g++` or `clang++`.

## File Structure

- **gameoflife.h / gameoflife.cpp**: Core game logic.
- **Timing.h / Timing.cpp**: Utilities for performance measurement.
- **gol.cpp**: Main program entry point.

## Build Instructions

1. Clone or download the repository.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -std=c++17 -o gol gol.cpp gameoflife.cpp Timing.cpp
   ```

## Usage

Run the program with the following command:
```bash
./gol --load <input_file> --save <output_file> --generations <n> [--measure]
```

### Parameters:
- `--load <input_file>`: Specifies the input file containing the initial board configuration.
- `--save <output_file>`: Specifies the file to save the final board configuration.
- `--generations <n>`: Specifies the number of generations to simulate.
- `--measure` (optional): Prints timing details for setup, computation, and finalization.

### Example Input File Format
```
5,5
.....
..xx.
.xx..
.....
.....
```

### Example Command
```bash
./gol --load input.txt --save output.txt --generations 10 --measure
```

## Example Output
After running 10 generations, the output file might look like this:
```
5,5
.....
.xxx.
.x.x.
.xxx.
.....
```

If the `--measure` flag is used, timing information is displayed:
```
0:00.007;0:08.082;0:00.017
```

## Testing

- Create a test input file as described above.
- Run the program and compare the results against expected outcomes.
