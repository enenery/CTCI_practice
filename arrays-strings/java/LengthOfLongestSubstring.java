import java.util.*;
/**
3. Longest Substring Without Repeating Characters from LeetCode
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

@since 11/23/2017
*/
public class LengthOfLongestSubstring {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length(); //n is the length of the input string
        Set<Character> set = new HashSet<>(); //set is a set of type character
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) { //while both i and j are less than n
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){//check if the set doesn't contain the character in the input string 
                set.add(s.charAt(j++)); //if it doesn't, add that chracter to the set and increment j
                ans = Math.max(ans, j - i); //then take the max of previous max and the current answer
            }
            else {
                set.remove(s.charAt(i++)); //if it already contains the character in the input string, remove that character from the character from the set
					   //then increment i
            }
        }
        return ans; //if i or j reaches the length of the input string, return the length of the longest substring of the input string
    }
	
	public static void main(String args[]){
		System.out.println(lengthOfLongestSubstring("bbbbbb"));
	}
}