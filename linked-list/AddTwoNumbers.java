/**
2. Add Two Numbers from LeetCode
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

{T:O(n), S:O(n)}
@since 11/23/2017
*/
class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
}

public class AddTwoNumbers{
	
	public static void main(String args[]){
		ListNode l1 = new ListNode(0);
		ListNode currl1 = l1;
		currl1.next = new ListNode(2);
		currl1 = currl1.next;
		currl1.next = new ListNode(4);
		currl1 = currl1.next;
		currl1.next = new ListNode(3);
		currl1 = currl1.next;
		
		ListNode l2 = new ListNode(0);
		ListNode currl2 = l2;
		currl2.next = new ListNode(5);
		currl2 = currl2.next;
		currl2.next = new ListNode(6);
		currl2 = currl2.next;
		currl2.next = new ListNode(4);
		currl2 = currl2.next;
		
		ListNode result = addTwoNumbers(l1.next, l2.next);
		ListNode currRes = result;
		while(currRes != null){
			System.out.print(currRes.val + " -> ");
			currRes = currRes.next;
		}
	}

	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode newList = new ListNode(0);
		ListNode p = l1;
		ListNode q = l2;
		ListNode curr = newList;
		int carry = 0;
		while (p != null || q != null) {
			int x = (p != null) ? p.val : 0;
			int y = (q != null) ? q.val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr.next = new ListNode(sum % 10);
			curr = curr.next;
			if (p != null) p = p.next;
			if (q != null) q = q.next;
		}
		if (carry > 0) {
			curr.next = new ListNode(carry);
		}
		return newList.next;
	}
}