def longestPalindrome(s):
	dict = {}
	output = 0
	odd_count = False
	for i in range(len(s)):
		print(s[i])
		dict[s[i]] = dict.get(s[i], 0) + 1

	for key, val in dict.items():
		if val%2 == 0:
			output = output + val
		else:
			odd_count = True
			output = output + val - 1		
		
	if odd_count:
		output = output + 1
	return output 

s = "aaaccc"
print(longestPalindrome(s))
