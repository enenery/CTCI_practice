import java.util.*;
//A program to remove dupulicates from an array of integers
public class RemoveDups{
	public static void main(String args[]){
		System.out.println("HashTableTest");
		Integer[] a = {1, 2, 3, 4, 3, 2, 5, 4, 6};
		System.out.println(Arrays.toString(a));
		a = removeDuplicates(a);
		System.out.println(Arrays.toString(a));
	}
	
	public static Integer[] removeDuplicates(Integer[] arr){
        HashSet<Integer> set = new HashSet<>();
        for (Integer elem : arr){
            set.add(elem);
        }
        Integer[] answer = new Integer[set.size()];
        set.toArray(answer);
        return answer;
	}
}