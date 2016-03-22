# http://stackoverflow.com/questions/15692149/taking-multiline-input-with-sys-stdin ->For input code
 
 
#Takes the logs and prints the count of parameters in the log file.
#@Author - Ishan Gupta
 
 
import sys
 
def main():
	log = []															#Stores the lines of log
	param = []															#Stores the parameters to check
	first = True														#For iterating over whole log
	second = 0															#For iterating after input delimiter
	count = []
	val = 0
 
 
	while first:														#Loop makes buffer log and buffer parameter log
		line = sys.stdin.readline().rstrip('\n')
		if line == '***************###############***************':
			while second < 5:
				line = sys.stdin.readline().rstrip('\n')
				param.append(line)
				second = second + 1
			first = False
		else:
			log.append(line)
 
 
	size_l = len(log)													#Stores the size of log
	size_p = len(param)													#Stores the size of paramaters
 
 
	if param[3] == "" or param[3] is None:								#Checks and substitutes if REQUEST_FORMAT is null
		param[3] = "HTML" 												#or blank
 
 
	while val < size_p:													#Calculates the count of each parameter to be
		sumval = 0														#tested. 		
		aux = 0
 
		if val == 0:
			temp = "Started " + param[val]
		else:
			temp = param[val]
 
		if param[1] == "/":
			param[1] = "\"" + param[1] + "\""
		else:
			param[1] = "\"" + param[1]
 
		while aux < size_l:
			sumval += log[aux].count(temp)
			aux += 1
		count.append(sumval)
		val += 1
 
	for x in count:														#Prints the desired output
		print x
 
 
if __name__ == "__main__":
	main()
