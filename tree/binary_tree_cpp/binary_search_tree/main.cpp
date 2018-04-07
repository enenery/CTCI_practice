#include "BinarySearchTree.cpp"
#include "BinaryTree.cpp"
#include "StackLL.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	BinarySearchTree<int> x, y;
	x.insert(50);
	x.insert(40);
	x.insert(30);
	x.insert(70);	
	x.insert(60);
	x.insert(100);
	x.insert(90);
	x.insert(110);
	x.insert(95);
	
	cout << "\ninorder: ";
	x.inorderDummy();

	//cout << "\ndeleteNode(7) ";
	//x.deleteNode(7);

	cout << "\ninorderIterative(): ";
	x.inorderIterative();

	cout << "\npreorder: ";
	x.preorderDummy();
	cout << "\npreorderIterative(): ";
	x.preorderIterative();

	cout << "\npostorder: ";
	x.postorderDummy();
	cout << "\npostorderIterative(): ";
	x.postorderIterative();

	cout << "\nx.searhRecDummy(3): " << x.searchRecDummy(3);
	cout << "\nx.searhRecDummy(0): " << x.searchRecDummy(0);
	cout << "\ny.searhRecDummy(3): " << y.searchRecDummy(3);

	cout << "\nx.printDescendants(7): ";
	x.printDescendantsRecDummy(7);

	cout << "\nx.findNumOfDescendants(7): ";
	cout << x.findNumOfDescendants(7);

	cout << "\nx.printAscendants(3): " ;
	x.printAscendantsRecDummy(3);

	cout << "\nfindNumOfAscendants(2): ";
	cout << x.findNumOfAscendants(2);

	cout << "\nx.printLargest(): ";
	x.printLargestRecDummy();

	cout << "\ny.printLargest(): ";
	y.printLargestRecDummy();

	cout << "\ngetMax(): ";
	int m = 0;
	x.getMax(m);
	cout << "\nm = " << m;

	cout << "\nx.printSmallest(): ";
	x.printSmallestRecDummy();

	cout << "\nx.printLarger(4): ";
	x.printLargerRecDummy(4);

	cout << "\nprintSmaller(6): ";
	x.printSmallerRecDummy(6);

	cout << "\nyes!countLeaves(): ";
	x.countLeavesDummy();

	cout << "\nprintLeaves(): ";
	x.printLeavesDummy();

	cout << "\ncountNodeWatLeastOneChild(): ";
	x.countNodeWatLeastOneChildDummy();

	cout << "\nprintNodeWatLeastOneChild(): ";
	x.printNodeWatLeastOneChildDummy();

	cout << "\ncountNodeWExactlyTwoChildren(): ";
	x.countNodeWexactlyTwoChildrenDummy();

	cout << "\nprintNodeWExactlyTwoChildren(): ";
	x.printNodeWexactlyTwoChildrenDummy();

	cout << "\ncountNodeWExactlyOneChild(): ";
	x.countNodeWexactlyOneChildDummy();

	cout << "\nprintNodeWExactlyOneChild(): ";
	x.printNodeWexactlyOneChildDummy();

	cout << "\ngetSumDummy(): ";
	cout << x.getSumDummy();

	cout << "\n.getHeight(): ";
	cout << x.getHeightDummy();

	cout << "\n.copy(y): ";
	

	cout << "\ndestroyTree(): ";
	x.destroyTreeDummy();

	cout << "\ninorder():";
	x.inorderDummy();

	cout << endl;
	return 0;
}