def knapsack(weights, values, capacity):
    n = len(values)  # Number of items
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Build the dp table bottom-up
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[n][capacity]

# Example usage
weights = [2, 3, 4, 5]
values = [3, 4, 5, 6]
capacity = 5
max_value = knapsack(weights, values, capacity)
print("The maximum value that can be obtained is:", max_value)
