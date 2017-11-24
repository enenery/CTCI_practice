/**
5. Longest Palindromic Substring from LeetCode
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"
		
@since 11/24/2017
*/

public class LongestPalindromicSubstring{
	public static void main(String args[]){
		System.out.println(longestPalindrome("aaabaaaa"));
	}
	
    public static String longestPalindrome(String s) {
        
		if(s == null || s.length() <= 1)
			return s;
	 
		int len = s.length();
		int maxLen = 1;
		boolean [][] dp = new boolean[len][len]; 
		String longest = Character.toString(s.charAt(0));
		
		for(int l = 0; l < len; l++){ //iterate over the string
			for(int i = 0; i < len-l; i++){ //iterate over the string,
				int j = i + l;
				if(s.charAt(i) == s.charAt(j) && (j - i <= 2 || dp[i+1][j-1])){
					dp[i][j] = true;
	 
					if(j - i + 1 > maxLen){
					   maxLen = j - i + 1; 
					   longest = s.substring(i, j+1);
					}
				}
			}
		}
	 
		return longest;
    }
}