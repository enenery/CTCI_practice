/**
4.1 Check Balanced Tree from CTCI 4
Challenge: Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes difer in distance
from the root by more than one.

@since 11/27/2017
*/
class TreeNode{
	TreeNode left;
	TreeNode right;
	int val;
	public TreeNode(int x){
		val = x;
		left = right = null;
	}
}
public class CheckBalancedTree{
	public static void main(String args[]){
		TreeNode t1 = new TreeNode(0);
		TreeNode c1 = t1;
		c1.left = new TreeNode(1);
		c1.left.left = new TreeNode(2);
		c1.left.right = new TreeNode(2);
		//c1.right = new TreeNode(1);
		//c1.right.left = new TreeNode(2);
		//c1.right.right = new TreeNode(2);
		
		System.out.println(checkBalancedTree(t1));
	}
	
	public static int maxDepth(TreeNode root){
		if(root == null)
			return 0;
		
		return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
	}
	
	public static int minDepth(TreeNode root){
		if(root == null)
			return 0;
		
		return 1 + Math.min(minDepth(root.left), minDepth(root.right));
	}
	
	public static boolean checkBalancedTree(TreeNode root){
		return (maxDepth(root) - minDepth(root) <= 1);
	}
	
}