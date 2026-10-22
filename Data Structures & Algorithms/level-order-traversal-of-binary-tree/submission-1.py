from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = deque([root])
        result =[]

        while(q):
            n = len(q)
            p =[]
            for _ in range(n):
                ele = q.popleft()
                p.append(ele.val)
                
                if ele.left:
                    q.append(ele.left)
                if ele.right:
                    q.append(ele.right)
            result.append(p)
        return result