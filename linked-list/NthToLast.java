/**
2.2 Nth to Last from CTCI 4
Implement an algorithm to find the nth to last element of a singly linked list.
@since 11/27/2017
*/

class ListNode {
	ListNode next;
	int val;
	ListNode(int x){val = x;};
}

public class NthToLast{
	public static void main(String args[]){
		ListNode x = new ListNode(0);
		ListNode xCurr = x;
		xCurr.next = new ListNode(1);
		xCurr = xCurr.next;
		xCurr.next = new ListNode(2);
		xCurr = xCurr.next;
		xCurr.next = new ListNode(3);
		xCurr = xCurr.next;
		xCurr.next = new ListNode(4);
		xCurr = xCurr.next;
		xCurr.next = new ListNode(5);
		xCurr = xCurr.next;

		ListNode res = nthToLast(x.next, 1);
		while(res != null){
			System.out.println(res.val + " -> ");
			res = res.next;
		}
	}
	
	public static ListNode nthToLast(ListNode root, int nth){
		if(root == null || n < 1)
			return null;
		
		ListNode curr = root;
		int count = 0;
		
		while(curr != null){
			if(++count == nth)
				return curr;
			else
				curr = curr.next;
		}
		
		return null;	
	}
}