# correct solution to Google Code Jam 2014 Qualification - B
import sys

# input the number of test cases
testCases = int(raw_input())
kase = 1

def findOptimalTime(c, f, x):
	currentRate = float(2.00)
	timeSpent = float(0.00)

	while True :
		withFactory = (c/currentRate) + (x/(currentRate + f))
		withoutFactory = x/currentRate

		if (withFactory < withoutFactory):
			timeSpent += (c/currentRate)
			currentRate += f
		else:
			timeSpent += x/currentRate
			break
	
	return timeSpent
	
	

while (testCases > 0):
	inputs = raw_input().split(" ")
	c = float(inputs[0])
	f = float(inputs[1])
	x = float(inputs[2])
	
	# format the output
	bestTime = findOptimalTime(c,f,x)
	outputString = "Case #{}: {}\n".format(kase,bestTime)

	# render output
	sys.stdout.write(outputString)

	# decrease the testCase number by 1
	testCases -= 1
	kase += 1
	
	


