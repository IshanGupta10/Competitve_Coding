# http://www.codeforces.com/contest/672/problem/A

q = int(raw_input())
s = ""
x = 1
while x < 1001:
	s += str(x)
	x += 1
print s[q-1]