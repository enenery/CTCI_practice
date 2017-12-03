import java.util.*;
/**
1.3 from CTCI 4
Question: Design an algorithm and write code to remove the 
duplicate characters in a string without using any additional
buffer. NOTE: One or two additional variables are fine.
An extra copy of the array is not. 
@since 11/28/2017
*/
public class RemoveDupsNoExtraBuffer {
	
	public static void main(String args[]){
		char[] s = new char[]{'a', 'b', 'c'};
		//System.out.println(s.length);
		int i = 0;
		while(i < s.length && s[i] != 0){
			System.out.print(s[i]);
			i++;
		}
		System.out.print("\n");
		//System.out.println(Arrays.toString(s));
		removeDupsNoBuffer(s);
		i = 0;
		while(i < s.length && s[i] != 0){
			System.out.print(s[i]);
			i++;
		}
		//System.out.println(s.length);
		//System.out.println(Arrays.toString(s));	
	}
	
	public static void removeDupsNoBuffer(char[] s){
		if(s == null)
			return;
		
		int len = s.length;
		if(len < 2)
			return;
		
		int tail = 1;
		
		for(int i = 1; i < len; ++i){
			int j;
			for(j = 0; j < tail; ++j){
				if(s[i] == s[j])
					break;
			}
			
			if(j == tail){
				s[tail] = s[i];
				++tail;
			}
		}
		
		if(tail < len)
			s[tail] = 0;
	}
}