#763. Partition Labels

class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        last = {c: i for i,c in enumerate(s)}
        j = anchor =0
        ans = []
        for i,c in enumerate(s):
            j = max(j, last[c])
            if i==j:
                ans.append(i-anchor + 1)
                anchor = i+1
        return ans

#find first and last occurance of i
#strings cannot be less than that
#but if a character from in bwt comes after the end, we will update the end