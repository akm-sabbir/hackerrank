# Enter your code here. Read input from STDIN. Print output to STDOUTdef main():
def main():
    n = int(input())
    queuee = []
    for i in range(n):
        arr = input().split(' ')
        command = [int(j) for j in arr]
        if command[0] == 1:
            queuee.append(command[1])
        elif command[0] == 2:
            queuee = queuee[1:]
        else:
            print(queuee[0])
    return
main()