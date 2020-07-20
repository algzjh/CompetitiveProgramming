t = int(input().strip())

while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().strip().split()))
    dic = {}
    first = True
    for i in a:
        if i not in dic:
            if not first:
                print(' ', end='')
            else:
                first = False
            print(i, end='')
            dic[i] = True
    print('')
