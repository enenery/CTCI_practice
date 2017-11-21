import java.util.Arrays;
/**
Triple Step: A child is running up a staircase with n steps and can hop 
either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many 
possible ways the child can run up the stairs.
*/

public class TripleStep{
	
	public static int count(int n){
		int[] mem = new int[n + 1];
		Arrays.fill(mem, -1);
		return count(n, mem);
	}
	
	public static int count(int n, int[] mem){
		if(n == 0)
			return 1;
		else if(n < 0)
			return 0;
		else if(mem[n] > -1)
			return mem[n];
		else{
			mem[n] = count(n-1, mem) + count(n-2, mem) + count(n-3, mem);
		}
		return mem[n];
	}
	
	public static void main(String args[]){
		System.out.println(count(5));
	}
}