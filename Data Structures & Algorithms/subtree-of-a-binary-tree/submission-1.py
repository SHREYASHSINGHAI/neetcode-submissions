# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSame(self, p:optional[TreeNode], q:optional[TreeNode])->bool:
        if not p or not q:
            return p==q
        left_same = self.isSame(p.left, q.left)
        right_same = self.isSame(p.right, q.right)
        return left_same and right_same and p.val == q.val
        
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        if not subRoot:
            return True
        if self.isSame(root, subRoot):
            return True
        else:
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)