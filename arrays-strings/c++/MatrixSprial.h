#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  int colSize = inputMatrix[0].size();
  int rowSize = inputMatrix.size();
  
  vector<int> answer;
  answer.push_back(colSize);
  // your code goes here
  int rowIndex = 0;
  int colIndex = 0;
  
  for(int i = 0; i<rowSize; i++){
    std::cout << "1";
    rowIndex = i;
    for(int j = rowIndex; j < colSize; j++){
      std::cout << "2";
      colIndex = j;
      answer.push_back(inputMatrix[rowIndex][colIndex]);
    
        for(int x = rowIndex; x < rowSize; x++){
          std::cout << "3";
          rowIndex = x;
          answer.push_back(inputMatrix[rowIndex][colIndex]);
        
            for(int y = colSize; y >= 0; y--){
              std::cout << "4";
              colIndex = y;
              answer.push_back(inputMatrix[rowIndex][y]);

                for(int z = rowIndex; z >= 0; z--){
                  std::cout << "5";
                  rowIndex = z;
                  answer.push_back(inputMatrix[rowIndex][colIndex]);
        }
    }
  }
}
    rowSize--;
    colSize--;
  }
  return answer;
}

// I think you can just click run tests. LOL. 14042 ms? I feel like it timed out. Maybe
// you're getting stuck in a loop? I would just print-debug a bunch of stuff.
// It's a pretty big step in the right direction from an infinite loop tho :)
// You can keep trying if you like. You had the right approach, your code just didn't work.
// There's too many edge cases and index-errors in this question for someone to do it in 30 mins.
// After I click "end", you'll get an email with the solution so you can look at that if you like.
// Thanks for the interview and good luck! Just copy and paste it.
int main() {
  
  return 0;
}