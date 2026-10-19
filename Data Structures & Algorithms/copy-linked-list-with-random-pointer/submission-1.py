"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None

        list2=Node(head.val)
        temp1=head.next
        temp2=list2

        while(temp1):
            node = Node(temp1.val)
            temp2.next = node
            temp2=temp2.next
            temp1 = temp1.next
        
        temp2 = list2
        temp1 = head
        mapp = {None : None}
        while(temp1):
            mapp[temp1]=temp2
            temp1 = temp1.next
            temp2 = temp2.next
        
        temp1 = head
        temp2 = list2

        while(temp2):
            temp2.random = mapp.get(temp1.random)
            temp2 = temp2.next
            temp1 = temp1.next
        return list2