/**
14. Longest Common Prefix from LeetCode

Write a function to find the longest common prefix string amongst an array of strings.

@comment I couldn't know that it was asking to find the longest common prefix amongst 
all the elements in the array. 

@since 11/26/2017
*/

public class LongestCommonPrefix{
	public static void main(String args[]){
		System.out.println(longestCommonPrefix(new String[]{"apple", "application", "appease", "sand"}));
	}
	
	public static String longestCommonPrefix(String[] strs) {
		if (strs.length == 0) return "";
		String prefix = strs[0];
		for (int i = 1; i < strs.length; i++)
			while (strs[i].indexOf(prefix) != 0) {
				prefix = prefix.substring(0, prefix.length() - 1);
				if (prefix.isEmpty()) return "";
			}        
		return prefix;
	}
}