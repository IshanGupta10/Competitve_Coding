# http://codeforces.com/problemset/problem/697/B
import math

def main():
    inp = raw_input()
    [ab,ma] = inp.split('e')
    val = double(ab)
    x = 10**(int(ma))
    ans = val*x
    answ = str(ans)
    if (answ[len(answ) - 1] == '0' and answ[len(answ) - 2] == '.'):
    	[a,b] = answ.split('.')
    	print a
    else:
	    print str(ans)
    
if __name__ == '__main__':
    main()