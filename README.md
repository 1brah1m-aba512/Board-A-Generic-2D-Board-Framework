# Board-A-Generic-2D-Board-Framework
The **Board** project is a templated C++ framework for managing and manipulating 2D grid-based data. It supports various data types, dynamic memory allocation, and features like randomization, deep copying, and operator overloading. Ideal for simulations, games, or tabular data processing.

## Features
- **Templated Design**: Supports grids of various data types (e.g., integers, characters).
- **Dynamic Allocation**: Manages memory efficiently for dynamic row and column sizes.
- **Randomization**: The `()` operator swaps values in the grid based on a seed for randomization.
- **Operator Overloading**:
  - Double indexing (`[]`) for accessing and modifying individual grid elements.
  - Stream insertion (`<<`) for displaying the grid in a structured format.
  - Assignment (`=`) for deep copying between `Board` objects.

## Use Cases
This framework is ideal for:
- Storing and manipulating tabular data.
- Simulating grid-based systems or processes.
- Building the foundation for board games, puzzles, or similar applications.

## How to Use
1. **Create a Board**: Define a `Board` object with the desired size and type.
2. **Randomize Data**: Use the `()` operator with a seed to shuffle grid values.
3. **Access and Modify**: Use double indexing (`Board[row][column]`) to interact with the grid.
4. **Display Data**: Use the `<<` operator to print the grid in a readable format.

## How to Run
1. Clone the repository: `git clone https://github.com/1brah1m-aba412/Board-A-Generic-2D-Board-Framework.git`
2. Navigate to the directory: `cd Board-A-Generic-2D-Board-Framework`
3. Compile the program: `g++ *.cpp -o Board`
4. Run the program: `./Board`

## Note
1. An example main.cpp has been provided to help with testing of the program
