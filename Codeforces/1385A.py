import sys

t = int(input().strip())

while t > 0:
    t -= 1
    arr = list(map(int, input().strip().split()))
    arr.sort()
    if arr[1] != arr[2]:
        print("NO")
    else:
        print("YES")
        print(arr[2], arr[0], arr[0])
