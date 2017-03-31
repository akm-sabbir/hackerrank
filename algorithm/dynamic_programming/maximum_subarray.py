# Enter your code here. Read input from STDIN. Print output to 

if __name__ == '__main__':
    T = int(raw_input())
    while T:
        T-=1
        n = int(raw_input())
        a = map(int,raw_input().strip().split(' '))
        mem = [-10010 for i in xrange(0,n+1)]
        mem[0] = a[0]
        sofar = a[0]
        for i in xrange(1,n):
            sofar = max(max(mem[i-1],a[i]),max((mem[i-1]+a[i]),sofar))
            mem[i] =max( mem[i-1] + a[i],a[i])
            
        #sofar = max(sofar,mem[n-1])  
        sum_= 0
        for i in xrange(0,n):
            if a[i] > 0:
                sum_+=a[i]
        if sum_ == 0:
            sum_ = max(a)
                
        print str(sofar) +" " + str(sum_)
            