# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        insert = TreeNode(val)
        
        if not root:
            return insert
        
        if val > root.val:
            if not root.right:
                root.right  = insert
            else:
                self.insertIntoBST(root.right, val)
        if val < root.val:
            if not root.left:
                root.left = insert
            else:
                self.insertIntoBST(root.left, val)
        return root