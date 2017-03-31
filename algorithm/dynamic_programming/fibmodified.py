# Enter your code here. Read input from STDIN. Print output to 
import math
def compute_fib(t1,t2,n):
    t = [0 for i in xrange(0,n + 1)]
    t[0] = t1
    t[1] = t2
    for i in xrange(2,n):
        t[i] = t[i-2]+ t[i-1]*t[i-1]
    print t[n-1]
    return
if __name__ == '__main__':
    t1 = map(int,raw_input().strip().split(' '))
    compute_fib(t1[0],t1[1],t1[2])