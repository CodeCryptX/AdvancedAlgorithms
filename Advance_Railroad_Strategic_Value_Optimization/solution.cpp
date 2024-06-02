#include <iostream>
using namespace std;

const int MX = 1001; // Maximum number of depots
int vals[MX]; // Array to store the strategic values of each depot
int dp[MX][MX]; // 2D array for memoization

// Function to calculate the interaction cost between depots from index s to e
int calcInt(int s, int e) {
    int sum = 0;
    for (int i = s; i < e; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            sum += vals[i] * vals[j];
        }
    }
    return sum;
}

// Function to find the minimum interaction cost for splitting depots from s to e into sp parts
int minInt(int s, int e, int sp)
{
    // Base cases
    if (s >= e)
    {
        return 0; // No interaction cost if no depots or only one depot
    }
    if (sp == 0)
    {
        return calcInt(s, e); // Return the interaction cost if no splits allowed
    }

    // Check if the value has already been computed
    if (dp[s][sp] != -1)
    {
        return dp[s][sp];
    }

    int minVal = calcInt(s, e);
    // Try splitting at each depot and calculate the minimum interaction cost
    for (int p = s; p < e; p++)
    {
        int intSplit = minInt(s, p, 0) + minInt(p + 1, e, sp - 1);
        minVal = min(minVal, intSplit);
    }

    dp[s][sp] = minVal; // Memoize the result
    return minVal;
}

int main() {
    int n, ms;
    cin >> n >> ms; // Input the number of depots and maximum splits

    for (int i = 0; i < n; i++) {
        cin >> vals[i]; // Input the strategic values of each depot
    }

    // Initialize the memoization array with -1
    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < MX; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Output the minimum interaction cost for the given railroad
    cout << "Min interaction cost: " << minInt(0, n - 1, ms) << endl;

    return 0;
}
