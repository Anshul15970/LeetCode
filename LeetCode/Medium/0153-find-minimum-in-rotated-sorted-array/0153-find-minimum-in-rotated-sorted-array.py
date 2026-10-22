class Solution:
    def findMin(self, nums: list[int]) -> int:
        n = len(nums)
        if(n==1):
            return nums[0]
        if(n == 2):
            return min(nums[0],nums[1])
        s = 0
        e = n-1
        ans = float('inf')
        if(nums[s] < nums[e]):
            return nums[s]
        while(s <= e):
            mid = s + (e-s)//2
            if (mid-1 >= 0 and mid+1 < n and (nums[mid-1] > nums[mid] and nums[mid] < nums[mid+1])):
                return nums[mid]
            elif(mid-1 >= 0 and mid+1 < n and
            (nums[mid-1] < nums[mid] and nums[mid+1] < nums[mid])):
                return nums[mid+1]
            elif(nums[s] > nums[mid]):
                e = mid
            else:
                s = mid
        return nums[0]