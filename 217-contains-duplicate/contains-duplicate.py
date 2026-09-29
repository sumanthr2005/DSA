class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        dup=False
        a=set()
        for i in nums:
            if i in a:
                return True
            a.add(i)
        return dup