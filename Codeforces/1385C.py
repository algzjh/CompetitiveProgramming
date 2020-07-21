t = int(input().strip())
 
while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().strip().split()))
    p = len(a) - 1
    while p - 1 >= 0 and a[p-1] >= a[p]:
        p = p - 1
    while p - 1 >= 0 and a[p-1] <= a[p]:
        p = p - 1
    print(p)
