class Solution:
    def countSubArrayLessThanOrEqualToGoal(self, nums, goal):
        if goal < 0:
            return 0
        count = 0
        n = len(nums)
        left = 0
        right = 0
        Sum = 0
        while right < n:
            Sum += nums[right]
            while Sum > goal:
                Sum -= nums[left]
                left += 1
            count = count + ((right - left) + 1)
            right += 1
        return count

    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.countSubArrayLessThanOrEqualToGoal(
            nums, goal
        ) - self.countSubArrayLessThanOrEqualToGoal(nums, goal - 1)
