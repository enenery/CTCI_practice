import java.util.*;

/**
*/

public class FindMostCommonWord{
	
	public static void main(String args[]){
		String s = "I am going to the coffee shop and the bakery.";
		System.out.println(s);
		System.out.println(findMostCommonWord(s));
	}

	public static String findMostCommonWord(String s) {
			if(s.length()==0) return "";
			
			String[] words = s.split(" ");
			Map<String, Integer> countMap = new HashMap<>();
			
			for(String word : words) {
				if(countMap.containsKey(word)) {
					int count = (Integer)countMap.get(word);
					countMap.put(word, ++count);
				} else {
					countMap.put(word, 1);
				}
			}
			
			int max = 0;
			String maxWord = "";
			for(Map.Entry<String, Integer> entry: countMap.entrySet()) {
				int count = entry.getValue();
				if (count>max) {
					maxWord = entry.getKey();
					max = count;
				}
			}
			
			return maxWord;
		}
}