package q51_3;

public class CheckPermutation {

	public static void main(String args[]){
		String str1 = "dance";
		String str2 = "raced";
		
		if(str1.length() == str2.length()){
			int[] letters = new int [128];
			char[] array = str1.toCharArray();
			char[] array2 = str2.toCharArray();
			
			for(char c: array)
				letters[c]++;
			
			for(char c: array2)
				if(--letters[c]<0)
					System.out.println("Two strings are not permutations");
				
			
		}else{
			System.out.println("Two strings are not permutations");
		}
	}
}
