# your code goes here
def gcd(a, b):
	if(b == 0):
		return a
	else:
		return gcd(b , a % b)

def main():
	[x , y] = [long(a) for a in raw_input().strip().split()]
	z = gcd(x , y)
	print z
	
if __name__ == '__main__':
	main()