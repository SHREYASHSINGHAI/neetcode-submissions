"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        copies = {}

        def dfs(cur):
            if cur in copies:
                return copies[cur]

            clone = Node(cur.val)
            copies[cur]=clone

            for nei in cur.neighbors:
                clone.neighbors.append(dfs(nei))
            return clone
        return dfs(node)

