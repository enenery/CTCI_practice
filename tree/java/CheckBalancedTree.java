/**
4.1 Check Balanced Tree from CTCI 4
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is de!ned to be a tree such that no two leaf nodes di#er in distance
from the root by more than one.
@comment to be modified and tested
@since 11/27/2017
*/

public class CheckBalancedTree{
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
	public static void main(String args[]){
		
	}
}