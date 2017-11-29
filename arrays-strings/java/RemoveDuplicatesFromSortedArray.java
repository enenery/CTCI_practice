import java.util.*;
/**
26. Remove Duplicates from Sorted Array from LeetCode

Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

public class RemoveDuplicatesFromSortedArray{
	public static void main(String args[]){
		removeDuplicates(new int[]{1,2,2,3,4,4,4,5});
	}
	public static int removeDuplicates(int[] nums) {
        if(nums.length < 2)
            return nums.length;
        
        int n = nums[0];
        int len = nums.length;
        int c = 1;
        
        for(int i = 1; i < nums.length; i++){
            if(n == nums[i]){
                len--;
            }else{
                nums[c++] = nums[i];
            }
            n = nums[i];
        }
		
		System.out.println(Arrays.toString(nums));
        
        return len;
    }
}