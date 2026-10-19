# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next :
            return

        slow = head 
        fast = head
        while(fast and fast.next):
            slow= slow.next
            fast = fast.next.next

        head2 = slow.next
        slow.next = None

        curr = head2
        prev = None
        nxt = None
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        temp1 = head
        temp2 = prev

        while temp2:
            nxt = temp1.next
            nxt2 = temp2.next

            temp1.next = temp2
            temp2.next=nxt

            temp1=nxt
            temp2=nxt2

        

        