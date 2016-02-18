# http://codeforces.com/contest/630/problem/F
def main():
	n = int(raw_input())
	mul = n
	k = 1
	while k < 7:
		mul *= (n-k)
		if(k == 4):
			x = mul
		elif(k == 5):
			y = mul
		elif(k == 6):
			z = mul
		k += 1
	# print x
	# print y
	# print z
	sum_ = z/5040 + y/720 + x/120
	print sum_

if __name__ == '__main__':
	main()