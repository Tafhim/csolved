# Solved [ https://code.google.com/codejam/contest/2974486/dashboard#s=p1 ]


import sys

# Read the number of test cases
testCase = int(raw_input())
kase = 1

while (testCase > 0):
	answerFirst = int(raw_input())	
	firstAnswerRow = [] 
	for i in range(4):
		if i is answerFirst-1:
			rowInput = raw_input()
			rowIntegers = rowInput.split(" ")
			firstAnswerRow = rowIntegers
		else:
			x = raw_input()

	answerSecond = int(raw_input())	
	secondAnswerRow = [] 
	for i in range(4):
		if i is answerSecond-1:
			rowInput = raw_input()
			rowIntegers = rowInput.split(" ")
			secondAnswerRow = rowIntegers
		else:
			x = raw_input()

	intersectList = list(set(firstAnswerRow) & set(secondAnswerRow))

	sys.stdout.write("Case #{}: ".format(kase))
	if len(intersectList) > 1:
		sys.stdout.write("Bad magician!\n")
	elif len(intersectList) < 1:
		sys.stdout.write("Volunteer cheated!\n")
	else:
		sys.stdout.write(intersectList[0] + "\n")
	kase += 1

	testCase -= 1
