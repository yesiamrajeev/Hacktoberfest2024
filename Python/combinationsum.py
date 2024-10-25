class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        def func(subset,index,target):
            if target==0:
                res.append(subset.copy())
                return
            if index>=len(candidates):return
            if candidates[index]<=target:
                subset.append(candidates[index])
                target-=candidates[index]
                func(subset,index,target)
                subset.pop()
                target+=candidates[index]
            func(subset,index+1,target)
        res=[]
        func([],0,target)
        return res
