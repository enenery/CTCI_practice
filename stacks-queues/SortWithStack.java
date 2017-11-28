/**
3.6 from CTCI 4
Write a program to sort a stack in ascending order. You should not make any assumptions
about how the stack is implemented. The following are the only functions that
should be used to write this program: push | pop | peek | isEmpty.
@comment To be tested
@since 11/27/2017
*/

class SortWithStack{
	public static void sortWithStack(Stack<Integer> s){
		if(s == null)
		 return null;
		
		Stack<Integer> s2 = new Stack<>();
		s2.push(s.pop());
		
		while(!s.isEmpty()){
			int x = s.pop();
			while(s2.top() < x){
				s.push(s2.pop());
			}
			s2.push(x);
		}

		return s2;

	}
	public static void main(String args[]){
		sortWithStack();
	}
}