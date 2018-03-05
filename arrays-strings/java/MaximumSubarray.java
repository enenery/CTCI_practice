import java.lang.*;

/**
Introduction to Algorithms Third Edition
Exercise #4.1-5
@author Erii Sugimoto
@since 02/13/2018
*/

public class MaximumSubarray{
	public MaximumSubarray(){
		
	}
	
	public static void main(String args[]){
		int maxSum = -1*Integer.MAX_VALUE;		
		int bestLowIndex = -1;
		int bestHighIndex = -1;
		int currentSum = 0;
		int currentLowIndex = 1;
		
		//int[] a = {0, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
		int[] a = {0, -3, -3, -3};
		
		for(int i = 1; i < a.length; i++){
			currentSum += a[i];
			if(currentSum > maxSum){
				bestLowIndex = currentLowIndex;
				bestHighIndex = i;
				maxSum = currentSum;
			}
			
			if(currentSum < 0){
				currentSum = 0;
				currentLowIndex = i + 1;
			}
		}
		
		System.out.println(bestLowIndex + " " + bestHighIndex + " " + maxSum);
	}
}