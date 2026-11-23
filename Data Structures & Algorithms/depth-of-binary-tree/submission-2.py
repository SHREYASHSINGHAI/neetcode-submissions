# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root :
            return 0
        height = 0
        leftht = self.maxDepth(root.left)
        rightht = self.maxDepth(root.right)
        height = max(leftht,rightht)+1
        return height