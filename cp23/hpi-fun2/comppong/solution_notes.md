# Naive Approach (not sufficient)

- generate all possible submatrices O(n^2 * n^2) and calculate their sum
- print maximum sum obtained
- = O(n^6)
# Faster Approach

- One submatrix can be described by two columns and two rows.
- Rough idea: We look at every pair of columns, save the sum between start- and end-column of every row in an array and calulate the maximum sum subarray using Kadane's Algorithm .
- Trick1: Easier sum-calculation of the row with prefix-sum calculation before: for each field f in a row r calculate sum from column 0 to f. To now obtain the sum over some columns L and R we can easily calculate prefix_sum[r, R] - prefix_sum[r, L]. This way we can calculate the sum of a row in O(1).
