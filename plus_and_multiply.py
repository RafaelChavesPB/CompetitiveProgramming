t = int(input())
for i in range(t):
    flag = False
    n, a, b = [int(x) for x in input().split()]
    p = 1
    while p <= n:
        res = n - p
        if res % b == 0: 
            flag = True
            break
        if a == 1:
            break
        p *= a
    if flag:
        print("YES")
    else:
        print("NO")