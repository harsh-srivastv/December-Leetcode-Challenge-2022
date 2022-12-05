# https://leetcode.com/problems/middle-of-the-linked-list/

# Definition for singly-linked list.
from typing import Optional


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
         
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        slow = head
        fast = head
        
        if head.next is None: return head
        
        if head.next.next is None:
            return head.next
        
        while fast.next and fast.next.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
            
        if fast.next is None: return slow
        else: return slow.next