/**
7. Reverse Integer from LeetCode
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
@since 11/24/2017
*/

public class ReverseInteger {
	
	public static void main(String args[]){
		System.out.println(reverse(-123));
	}
	
    public static int reverse(int x) {
        String s = Integer.toString(x);
        StringBuffer sb = new StringBuffer(s);
        int i = 0;
        int ans = 0;
        boolean neg = false;
        char tmp = ' ';
        
        if(!Character.isDigit(s.charAt(0))){
            neg = true;
            sb = new StringBuffer(sb.substring(1, s.length()));
			//System.out.println(sb);
        }
        
        while(i < sb.length()/2){
            tmp = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(sb.length()-1-i));
            sb.setCharAt(sb.length()-1-i, tmp);
            i++;
        }
    
        try{
            ans = Integer.parseInt(sb.toString());
        }catch (NumberFormatException e) {
    
        }
        
        if(neg)
            ans *= -1;
        
        return ans;
    }
}