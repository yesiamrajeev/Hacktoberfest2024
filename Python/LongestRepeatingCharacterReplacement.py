class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_freq=0
        l,r=0,0
        hash_map={}
        max_l=0
        n=len(s)
        while r<n:
            hash_map[s[r]]=hash_map.get(s[r],0)+1
            max_freq=max(max_freq,hash_map[s[r]])
            changes=(r-l+1)-max_freq
            if changes>k:
                hash_map[s[l]]-=1
                l+=1
            if changes<=k:
                max_l=max(max_l,r-l+1)
            r+=1
        return max_l
