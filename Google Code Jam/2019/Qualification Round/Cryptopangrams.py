"""
Google Code Jam 2019
Qualification Round 2019
Cryptopangrams
"""
import math


def get_gcd(a, b):
    if b == 0:
        return a
    else:
        return get_gcd(b, a % b)


def is_square(x):
    if int(math.sqrt(x) + 0.5) ** 2 == x:
        return True
    else:
        return False


T = int(input())
cas = 1
while T > 0:
    ans = []
    T -= 1

    N, L = map(int, input().strip().split())
    a = [int(x) for x in input().strip().split()]

    p = 0
    for i in range(L):
        ans.append([0, 0])
    for i in range(L - 1):
        # if a[i] != a[i + 1]:
        #     g = int(get_gcd(a[i], a[i + 1]))
        #     ans[i] = [int(a[i] // g), g]
        #     p = i
        #     break
        # else:
        #     pass
        if is_square(a[i]):
            rt = int(math.sqrt(a[i]) + 0.5)
            ans[i] = [rt, rt]
            p = i
            break
        elif is_square(a[i + 1]):
            rt = int(math.sqrt(a[i + 1]) + 0.5)
            ans[i + 1] = [rt, rt]
            p = i + 1
            break
        elif a[i] != a[i + 1]:
            g = int(get_gcd(a[i], a[i + 1]))
            ans[i] = [int(a[i] // g), g]
            p = i
            break
        else:
            pass

    for i in range(p + 1, L, 1):
        ans[i] = [ans[i - 1][1], int(a[i] // ans[i - 1][1])]
    for i in range(p - 1, -1, -1):
        ans[i] = [int(a[i] // ans[i + 1][0]), ans[i + 1][0]]

    s = set()
    for i in range(L):
        s.add(ans[i][0])
        s.add(ans[i][1])
    slist = list(s)
    slist.sort()

    my_d = {}
    slen = len(slist)
    for i in range(slen):
        my_d[slist[i]] = chr(ord('A') + i)

    print("Case #%d: " % cas, end="")
    cas += 1
    first = True
    for pair in ans:
        if first:
            print(my_d[pair[0]], end="")
            first = False
        print(my_d[pair[1]], end="")
    print("")

"""
3
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
103 33
49 49 217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053

"""
