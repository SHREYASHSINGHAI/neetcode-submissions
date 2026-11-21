class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trust_score = [0]*(n+1)
        for p1,p2 in trust:
            trust_score[p1] -= 1
            trust_score[p2] += 1
        
        for i in range(n+1):
            if trust_score[i] == n-1:
                return i
        return -1