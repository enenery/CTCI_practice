/*
question: Write a function that takes two integer-valued arrays 
A and Q and computes a minimum length subarray A[i:j] that sequentially
covers Q. Assume all elements in Q are distinct.
source from careercup.com

*/
public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11 };
		int[] Q = { 9, 10, 12 };
		int[] indices = getIndicesForSubset(A, Q);
		System.out.println("beginIndex: " + indices[0] + " endIndex: " + indices[1]);

	}

	private static int[] getIndicesForSubset(int[] a, int[] q) {
		int[] indices = { -1, -1 };
		int limit = a.length;
		int qCounter = 0;

		for (int i = 0; i < limit; i++) {
			if (a[i] == q[qCounter])
				qCounter++;
			else
				qCounter = 0;

			if (qCounter == q.length) {
				indices[0] = i - qCounter + 1;
				indices[1] = i;
				break;
			}
		}
		return indices;
	}