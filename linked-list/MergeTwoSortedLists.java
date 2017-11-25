class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
}

public class MergeTwoSortedLists{
	
	public static void main(String args[]){
		ListNode l1 = new ListNode(0);
		ListNode currl1 = l1;
		currl1.next = new ListNode(2);
		currl1 = currl1.next;
		currl1.next = new ListNode(4);
		currl1 = currl1.next;
		currl1.next = new ListNode(6);
		currl1 = currl1.next;
		
		ListNode l2 = new ListNode(1);
		ListNode currl2 = l2;
		currl2.next = new ListNode(3);
		currl2 = currl2.next;
		currl2.next = new ListNode(9);
		currl2 = currl2.next;
		currl2.next = new ListNode(10);
		currl2 = currl2.next;
		
		ListNode result = mergeTwoLists(l1.next, l2.next);
		ListNode currRes = result;	
		
		while(currRes != null){
			System.out.print(currRes.val + " -> ");
			currRes = currRes.next;
		}
	}
	
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode newList = new ListNode(0);
        ListNode p = l1;
        ListNode q = l2;
        ListNode curr = newList;
        
        while(p != null || q != null){
            int x = (p != null) ? p.val : Integer.MAX_VALUE;
            int y = (q != null) ? q.val : Integer.MAX_VALUE;
            int z = 0;
            if(x < y){
                z = x;
                if(p != null)
                    p = p.next;
            }else{
                z = y;
                if(q != null)
                    q = q.next;
            }
            curr.next = new ListNode(z);
            curr = curr.next;
            
        }
        
        return newList.next;
    }
}