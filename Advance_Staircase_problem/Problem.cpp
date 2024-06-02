#include <iostream>
using namespace std;

// Function to count the number of combinations
// n: remaining blocks to be used
// prevHeight: height of the previous stage
// memo: 2D array to store already computed values
int countCombinations(int n, int prevHeight, int** memo)
{
    // Base case: if no blocks remaining, return 1 (valid combination found)
    if (n == 0) return 1;

    // If there are no blocks left to use or the previous stage had a height of 0,
    // no valid combination can be formed
    if (n < 0 || prevHeight == 0) return 0;

    // If the value has already been computed, return it from memoization
    if (memo[n][prevHeight] != -1)
    {
        return memo[n][prevHeight];
    }

    int combinations = 0;

    // Try all possible heights for the current stage
    for (int height = 1; height <= min(n, prevHeight); ++height)
    {
        // Recursively count combinations for the remaining blocks and the next stage
        combinations += countCombinations(n - height, height - 1, memo);
    }

    // Memoize the result
    memo[n][prevHeight] = combinations;
    return combinations;
}

// Function to initialize memoization array and call the recursive function
int call(int n)
{
    // Initialize memoization array
    int** memo = new int* [n + 1];
    for (int i = 0; i <= n; ++i) {
        memo[i] = new int[n];
    }

    // Fill memoization array with -1 (indicating no value computed yet)
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = -1;
        }
    }

    // Call the recursive function to count combinations
    int result = countCombinations(n, n - 1, memo);

    // Free memory allocated for memoization array
    for (int i = 0; i <= n; ++i) {
        delete[] memo[i];
    }
    delete[] memo;

    return result;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    // Call the function and output the result
    cout << "Number of combinations for N = " << n << ": " << call(n) << endl;

    return 0;
}
