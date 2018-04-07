import java.util.*;
/**
1. Two sum from LeetCode
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

{T:O(n) S:O(n)}

@since 11/23/2017
*/
class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap<Integer, Integer> map = new HashMap<>();
        int i = 0;
        boolean found = false;
        
        while(i < nums.length && !found){
			int diff = target-nums[i];
			System.out.println(diff);
            if(map.containsKey(diff)){
                found = true;
                ans[0] = map.get(diff);
                ans[1] = i;
            }else{
                map.put(nums[i], i);
                i++;
            }
        }
        
        return ans;
    }
	
	public static void main(String args[]){
		System.out.println(Arrays.toString(twoSum(new int[] {2, 7, 11, 15}, 9)));
	}
}