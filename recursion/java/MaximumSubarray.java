import java.util.*;
//with the help from Geek For Geeks
public class MaximumSubarray{
	public static int maxSubArraySum(int arr[], int l, int h){
		if(l == h)
			return arr[l];
		int m = (l + h)/2;
		return Math.max(Math.max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m+1, h)), maxCrossingSum(arr, l, m, h));
	}
	
	static int maxCrossingSum(int arr[], int l, int m, int h)
    {
        int sum = 0;
        int leftSum = Integer.MIN_VALUE;
        for (int i = m; i >= l; i--)
        {
            sum = sum + arr[i];
            if (sum > leftSum)
            leftSum = sum;
        }
 
        sum = 0;
        int rightSum = Integer.MIN_VALUE;
        for (int i = m + 1; i <= h; i++)
        {
            sum = sum + arr[i];
            if (sum > rightSum)
            rightSum = sum;
        }
 
        return leftSum + rightSum;
    }
	
	public static void main(String args[]){
		//int arr[] = {0, -2, 1, -2, 1, 1, 1, 2, -2, 0, -1};
		int[] arr = {-3, -13, -4, -25, -20, -32, -16, -23};
		//int[] arr = {0, 13};
		int lastIndex = arr.length;
		int maxSum = maxSubArraySum(arr, 0, lastIndex-1);
		System.out.println("Max contiguous sum = " + maxSum);
	}
}