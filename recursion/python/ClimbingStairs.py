#70. Climbing Stairs from Leetcode

#A1
def climb_stairs(n):

	mem = [-1 for x in range(n + 1)]

	def count(n, mem):
		if n < 0:
			return 0
		elif n == 0:
			return 1
		elif mem[n] != -1:
			return mem[n]
		else:
			mem[n] = count(n - 1, mem) + count(n - 2, mem)
			return mem[n]

	return count(n, mem)

print("Enter the number of steps for your staircase: ")
n = input()
print("The number of ways you can run up the stairs: ", climb_stairs(int(n)))