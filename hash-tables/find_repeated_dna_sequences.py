def find_repeated_dna_sequences(sqs):
	dict = {}
	result = []
	for i in range(len(sqs) - 9):
		substr = sqs[i:i+10]
		print(substr)
		dict[substr] = dict.get(substr, 0) + 1
	for key, val in dict.items():
		if val > 1:
			result.append(key)
	return result

sqs = "AAAAACCCCCAAAAACCCCCCCAAAAAGGGTTT"
print(find_repeated_dna_sequences(sqs))