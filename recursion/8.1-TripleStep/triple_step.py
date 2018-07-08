'''
Triple Step: A child is running up a staircase with n steps and can hop 
either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many 
possible ways the child can run up the stairs.

From CTCI
'''
#Brute Force Solution
def triple_step(n):
	if n > 0:
		if n == 1:
			return 1
		if n == 2:
			return 2
		if n == 3:
			return 4
		return triple_step(n - 1) + triple_step(n - 2) + triple_step(n - 3)

print("Enter the number of steps for your staircase: ")
n = input()
print("The number of ways you can run up the stairs: ", triple_step(int(n)))
