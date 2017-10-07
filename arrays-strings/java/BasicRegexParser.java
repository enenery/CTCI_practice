import java.io.*;
import java.util.*;

/**
From pramp.com
Implement a regular expression function isMatch that supports the '.' and '*' symbols.
The function receives two strings - text and pattern - and should return true 
if the text matches the pattern as a regular expression. 
For simplicity, assume that the actual symbols '.' and '*' do not appear in the text string 
and are used as special symbols only in the pattern string.
*/

class BasicRegexParser {
  
  static boolean isMatch(String text, String pattern) {
    // your code goes here
    int j = 0;
    for(int i = 0; i < text.length(); i++){
      if(j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
        char toBeMatched = ' ';
        
        if(pattern.charAt(j) == '.')
          toBeMatched = text.charAt(i);
        else
          toBeMatched = pattern.charAt(j);
        
        if(text.charAt(i) != toBeMatched)
          i--;
        while(i < text.length() && text.charAt(i) == toBeMatched)
          i++;
        j += 2;
      }else{
        if(j >= pattern.length() || 
           text.charAt(i) != pattern.charAt(j) && pattern.charAt(j) != '.')
            return false;
        j++;
      }
    }
    
    return true;
  }

  public static void main(String[] args) {

  }

}