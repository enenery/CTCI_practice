import javafx.util.*;
/**
102 Binary Tree Level Order Traversal from LeetCode
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
NOTE: I haven't run it yet on my machine
@since 11/26/2017
 */
 
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
 
public class BinaryTreeLevelOrderTraversal {
	
	public static void main(String args[]){
		
	}
	
    public static List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        
        TreeNode current = root;
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        List<List<Integer>> container = new ArrayList<>();
        List<Integer> list = new ArrayList<Integer>();
        
        int prevLevel = 0;
        q.add(new Pair(current, 0));
        
        while(!q.isEmpty()){
            Pair<TreeNode, Integer> pair = q.remove();
            
            if(prevLevel != pair.getValue()){
                container.add(list);
                list = new ArrayList<Integer>();
            }
                list.add(pair.getKey().val);
                prevLevel = pair.getValue();
          
            if(pair.getKey().left != null)
                q.add(new Pair(pair.getKey().left, prevLevel+1));
            if(pair.getKey().right != null)
                q.add(new Pair(pair.getKey().right, prevLevel+1));
            
        }
        
        container.add(list);
        
        return container;
    }
}