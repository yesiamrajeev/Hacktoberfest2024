# Brute Force Solution
def max_subarray_brute_force(nums):
    max_sum = float('-inf')
    n = len(nums)

    # Check every possible subarray
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += nums[j]
            max_sum = max(max_sum, current_sum)

    return max_sum

# Example usage
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print("Brute Force Solution:", max_subarray_brute_force(nums))
