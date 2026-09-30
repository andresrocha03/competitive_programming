//Problem: given a valid VPS, return a division of the VPS such that the depth of the VPS is minimized
//Solution: keep track of the depth, evry opening bracket adds 1, every closing subtracts 1. Even depth to one group and piar to other.

class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        depth = 0
        openings = []
        choice = 0
        cont = False
        res = []
        for i in range(len(seq)):
            if seq[i] == '(':
                if (seq[i+1]==')'):
                    res.append(choice)
                    res.append(choice)
                    cont = True
                    continue
                depth += 1
                res.append(choice)
                openings.append(choice)
                choice = abs(choice-1)
                
            else:
                if cont:
                    cont = False
                    continue
                res.append(openings[-1])
                openings.pop(-1)

        return res
