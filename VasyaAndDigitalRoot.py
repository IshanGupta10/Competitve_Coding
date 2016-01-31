# your code goes here
# https://ideone.com/3pEqSb
def calculate(x,t):
	if(t==0 and x==1):
		return 0
	elif(t==0 and x>1):
		return "No solution"
	elif(t>0):
		q = 10**(x-1)
		num = q*t
		return num
	

def main():
	[aux,temp] = [int(a) for a in raw_input().strip().split()]
	rox = calculate(aux,temp)
	print rox
	
if __name__ == "__main__":
	main()