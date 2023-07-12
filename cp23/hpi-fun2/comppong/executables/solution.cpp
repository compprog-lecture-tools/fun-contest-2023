#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// Implementation of Kadane's algorithm for
// 1D array. The function returns the maximum
// sum and stores starting and ending indexes
// of the maximum sum subarray at addresses
// pointed by start and finish pointers
// respectively.
int kadane(vector<int> &arr, int &start, int &finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
    finish = -1;
    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }
    if (finish != -1)
        return maxSum;

    maxSum = arr[0];
    start = finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            start = finish = i;
        }
    }
    return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(vector<vector<int>> &M, ll h, ll w)
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int sum, start, finish;

    // Set the left column
    for (left = 0; left < w; ++left)
    {
        // Initialize all elements of temp as 0
        vector<int> temp(h, 0);

        // Set the right column for the left
        // column set by outer loop
        for (right = left; right < w; ++right)
        {

            // Calculate sum between current left
            // and right for every row 'i'
            for (i = 0; i < h; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[].
            // The kadane() function also sets values
            // of start and finish. So 'sum' is sum of
            // rectangle between (start, left) and
            // (finish, right) which is the maximum sum
            // with boundary columns strictly as left
            // and right.
            sum = kadane(temp, start, finish, h);

            // Compare sum with maximum sum so far.
            // If sum is more, then update maxSum and
            // other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    cout << "(Top, Left) (" << finalTop << ", " << finalLeft
         << ")" << endl;
    cout << "(Bottom, Right) (" << finalBottom << ", "
         << finalRight << ")" << endl;
    cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
    int w, h;
    cin >> w >> h;
    vector<vector<int>> matrix(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> matrix[i][j];
        }
    }
    findMaxSum(matrix, h, w);

    return 0;
}