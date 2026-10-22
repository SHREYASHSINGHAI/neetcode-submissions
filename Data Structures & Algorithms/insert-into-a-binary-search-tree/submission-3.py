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
        
        if(insert.val > root.val):
            if not root.right:
                root.right = insert
            else:
                self.insertIntoBST(root.right, insert.val)

        if(insert.val < root.val):
            if not root.left:
                root.left = insert
            else:
                self.insertIntoBST(root.left, insert.val)
        return root