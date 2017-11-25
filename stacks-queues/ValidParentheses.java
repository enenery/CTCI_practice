import java.util.*;
/**
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
The brackets must close in the correct order, 
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

@since 11/25/2017
*/
public class ValidParentheses {
	
	public static void main(String args[]){
		System.out.println(isValid("[{}]()"));
	}
	
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        int i = 0;
        while(i < s.length()){
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                stack.push(s.charAt(i));
            }
            
            if(s.charAt(i) == ')' || s.charAt(i) == '}' || s.charAt(i) == ']'){
                if(stack.isEmpty())
                    return false;
                    
                if(stack.peek() == '(' && s.charAt(i) == ')' ||
                        stack.peek() == '{' && s.charAt(i) == '}' ||
                            stack.peek() == '[' && s.charAt(i) == ']'){
                    stack.pop();
                }else
                    return false;
                    
            }
            
            i++;
        }
        
        if(!stack.isEmpty())
            return false;
        else
            return true;
    }
}