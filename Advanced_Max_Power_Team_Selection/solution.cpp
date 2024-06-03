#include<iostream>
#include<climits>
using namespace std;

// Function to calculate the maximum power level achievable
int max_power(int **hunters, int **dp, int numRows, int numColumns) {
    // Initialize the first column of dp with the values from the hunters array
    for (int i = 0; i < numRows; i++) {
        dp[i][0] = hunters[i][0];
    }

    // Calculate maximum power level column by column
    for (int j = 1; j < numColumns; j++) {
        int highest = INT_MIN;
        int secondHighest = INT_MIN;

        // Find the highest and second highest values from the previous column
        for (int i = 0; i < numRows; i++) {
            if (dp[i][j - 1] > highest) {
                secondHighest = highest;
                highest = dp[i][j - 1];
            } else if (dp[i][j - 1] > secondHighest) {
                secondHighest = dp[i][j - 1];
            }
        }

        // Calculate maximum power level for each cell in the current column
        for (int k = 0; k < numRows; k++) {
            if (dp[k][j - 1] == highest) {
                dp[k][j] = max(dp[k][j - 1], hunters[k][j] + secondHighest);
            } else {
                dp[k][j] = max(dp[k][j - 1], hunters[k][j] + highest);
            }
        }
    }

    // Find the maximum power level from the last column of dp
    int maxPower = INT_MIN;
    for (int i = 0; i < numRows; i++) {
        if (dp[i][numColumns - 1] > maxPower) {
            maxPower = dp[i][numColumns - 1];
        }
    }
    return maxPower;
}

int main() {
    int numRows, numColumns;
    cout << "Enter number of rows: ";
    cin >> numRows;
    cout << "Enter number of columns: ";
    cin >> numColumns;

    // Check for invalid input
    if (numColumns <= 0 || numRows <= 0) {
        cout << "Invalid Input" << endl;
        return 0;
    }

    // Handle special case for numRows = 1
    if (numRows == 1) {
        // Dynamically allocate memory for hunters array
        int **hunters = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            hunters[i] = new int[numColumns];
        }

        // Input values for hunters array
        cout << "Enter values for hunters array:" << endl;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                cin >> hunters[i][j];
            }
        }

        // Find the maximum power level achievable
        int maxPower = INT_MIN;
        for (int i = 0; i < numColumns; i++) {
            if (hunters[0][i] > maxPower) {
                maxPower = hunters[0][i];
            }
        }

        // Output the maximum power level
        cout << "Maximum power level: " << maxPower << endl;

        // Free dynamically allocated memory
        for (int i = 0; i < numRows; ++i) {
            delete[] hunters[i];
        }
        delete[] hunters;
    } else {
        // Dynamically allocate memory for hunters array
        int **hunters = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            hunters[i] = new int[numColumns];
        }

        // Dynamically allocate memory for dp array
        int **dp = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            dp[i] = new int[numColumns];
        }

        // Input values for hunters array
        cout << "Enter values for hunters array:" << endl;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                cin >> hunters[i][j];
            }
        }

        // Calculate and output the maximum power level achievable
        cout << "Maximum power level: " << max_power(hunters, dp, numRows, numColumns) << endl;

        // Free dynamically allocated memory
        for (int i = 0; i < numRows; ++i) {
            delete[] hunters[i];
            delete[] dp[i];
        }
        delete[] hunters;
        delete[] dp;
    }
    return 0;
}
