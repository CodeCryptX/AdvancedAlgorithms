# Advanced Algorithms with Time Complexity Analysis

This repository contains four challenging problems that delve into advanced algorithms and their time complexity analysis. Each problem requires a comprehensive understanding of data structures, dynamic programming, and optimization techniques to devise efficient solutions. The solutions are implemented in C++.

## Problem Overview

### Problem 1: Block Structure Construction
**Description**: Given a set of blocks, determine the number of different structures that can be built. Each structure consists of stages, with each stage being lower in height than the previous one, and no two stages at the same height. The height of a stage is defined by the number of blocks in that stage.

**Key Concepts**: Dynamic Programming, Combinatorics

**Input**: A positive integer \( n \) (3 ≤ \( n \) ≤ 200)

**Output**: Number of possible structures

### Problem 2: Optimal Railroad Destruction
**Description**: Assist Abdullah in minimizing the Strategic Value of a railroad by determining the best place to attack. The Strategic Value is computed based on the product of Strategic Importance values of connected depots.

**Key Concepts**: Dynamic Programming, Greedy Algorithms

**Input**: Multiple datasets with the number of depots \( n \) and the number of attacks \( m \), followed by the Strategic Value of each depot.

**Output**: Smallest Strategic Value after attacks

### Problem 3: Minimum Not Presented Number (MNPN)
**Description**: Determine if an array can be divided into segments such that each segment has the same MNPN, which is the smallest non-negative integer not present in that segment.

**Key Concepts**: Data Structures, Segment Trees

**Input**: Length of array \( N \) and the array elements

**Output**: Number of segments and their indices, or -1 if not possible

### Problem 4: Maximum Power Team Selection
**Description**: Select a team of adventurers from a grid of hunters, ensuring maximum total power. Hunters are chosen from left to right, with no consecutive selections from the same row.

**Key Concepts**: Dynamic Programming, Matrix Manipulation

**Input**: Number of rows \( M \) and columns \( N \), followed by a matrix of power levels

**Output**: Maximum power of the selected team

## Repository Structure
- **Source Code**: Implementation of the algorithms in C++.
- **Reports**: Detailed analysis of each problem including pseudocode, time complexity, and space complexity.
- **Test Cases**: Sample inputs and outputs to verify the correctness of the algorithms.

## How to Use
1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/your-username/advanced-algorithms.git
    ```
2. Navigate to the problem directory you want to explore:
    ```bash
    cd advanced-algorithms/problemX
    ```
3. Compile the C++ source code:
    ```bash
    g++ -o solution solution.cpp
    ```
4. Run the executable with the sample inputs to see the solutions in action:
    ```bash
    ./solution < input.txt
    ```
5. Review the reports for a deep dive into the algorithmic approach and complexity analysis.

## Contributions
Contributions are welcome! If you have improvements or additional test cases, feel free to open a pull request.

---

Happy coding!
