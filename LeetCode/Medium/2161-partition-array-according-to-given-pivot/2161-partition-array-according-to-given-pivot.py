class Solution:
    def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
        n = len(nums)
        a = []
        for i in range(n):
            if(pivot > nums[i]):
                a.append(nums[i])
        for i in range(n):
            if(pivot == nums[i]):
                a.append(nums[i])
        for i in range(n):
            if(pivot < nums[i]):
                a.append(nums[i])
        return a