/**
 * Created by Erii on 4/27/2017.
 */
public class stringCompressed {

    public static String stringCompressed(String word){
        int outerLoop = word.length();
        String compressed = "";
        boolean notFound = true;

        for(int i = 0; i<outerLoop; i++){
            System.out.println("i = " + i + " word.char(i): " + word.charAt(i));
            int count = 1;
            for(int j = i+1; j<word.length()+1 && notFound; j++){
                if(word.charAt(i) == word.charAt(j)) {
                    count++;
                    i = j;
                }
                else{
                    compressed += word.charAt(i) + Integer.toString(count);
                    notFound = false;
                }

                if(j-1 == word.length())
                    compressed += word.charAt(i) + Integer.toString(count);

                System.out.println("count: " + count);
            }
            System.out.println("i: " + i);
        }

        if(word.length() <= compressed.length())
            return word;
        else
            return compressed;
    }
    public static void main(String[] args){
        System.out.println(stringCompressed("aaab"));
    }
}
