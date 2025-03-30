class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastIndex = {}

        for i, c in enumerate(s):
            lastIndex[c] = i
        
        res = []
        size,e = 0,0
        for i, c in enumerate(s):
            size += 1
            e = max(e,lastIndex[c])

            if i == e:
                res.append(size)
                size = 0
        return res