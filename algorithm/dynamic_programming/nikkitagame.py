# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
def get_max(mem, memr, sindex, eindex) :
    max_score = 0
    if (int(math.fabs(sindex - eindex)) == 1 or sindex == eindex) :
        return 0
    for i in xrange(sindex + 1, eindex) :
        left_ = mem[i - 1] - (0 if sindex == 0 else mem[sindex - 1])
        right_ = memr[i] - (0 if eindex == len(memr) else memr[eindex])
        #print str(left_)+" " + str(right_)
        if (left_ == right_) :
            #print str(left_)+" " + str(right_)
            return 1 + max(get_max(mem, memr, sindex, i), get_max(mem, memr, i, eindex))
        
    return 0
if __name__ == '__main__':
   
    t = int(raw_input())
    while t > 0:
        t -= 1
        n = int(raw_input())
        a = map(int, raw_input().strip().split(' '))
        mem = [0 for i in xrange(0,n)]
        memr = [0 for i in xrange(0, n)]
        mem[0] = a[0]
        memr[n-1] = a[n-1]
        if sum(a) == 0:
            print len(a)-1
        else:
            for i in xrange(1,n):
                mem[i] = a[i] + mem[i - 1]
                memr[n-1 - i] = a[n-1-i] + memr[n - 1 - i + 1]
            score = get_max(mem,memr,0,len(mem))
            if(score  != 0):
                print score
            else:
                print 0
    