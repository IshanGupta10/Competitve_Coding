# http://codeforces.com/contest/630/problem/L
def main():
	s = raw_input()
	n = int(s[0]) * 10000 + int(s[2]) * 1000 + int(s[4]) * 100 + int(s[3]) * 10 + int(s[1])
	print '%05d' % (n ** 5 % 100000)

if __name__ == '__main__':
	main()