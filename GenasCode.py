# http://codeforces.com/contest/614/problem/B
# your code goes here
def main():
	 k = int(raw_input())
	 arr = [int(a) for a in raw_input().strip().split()]
	 mul = 1
	 #print len(arr)
	 for x in arr:
	 	mul *= x
	 print mul
	 
if __name__ == "__main__":
	main()