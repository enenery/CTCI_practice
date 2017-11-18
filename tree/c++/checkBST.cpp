//Hackerank 
/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
   bool checkBST(Node* root) {
       if(root == NULL)
           return true;
       else
           return checkBST(root, 10000, 0);
   }

   bool checkBST(Node* root, int max, int min){
       if(root == NULL)
           return true;
       
       if(root->data > max || root->data < min)
           return false;
       
       return checkBST(root->left, root->data, min) && checkBST(root->right, max, root->data);
   }
