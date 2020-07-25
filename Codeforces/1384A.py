t = int(input().strip())

while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().strip().split()))
    ans = []
    pre_s = "".join(['a' for i in range(50)])
    ans.append(pre_s)
    for i in range(len(a)):
        new_s = ""
        for j in range(50):
            if j < a[i]:
                new_s += ans[i][j]
            else:
                new_s += chr((ord(ans[i][j]) - ord('a') + 1) % 26 + ord('a'))
        ans.append(new_s)
    for s in ans:
        print(s)
