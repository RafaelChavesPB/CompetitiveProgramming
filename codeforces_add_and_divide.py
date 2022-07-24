from math import *
n = int(input())
for i in range(n):
    a,b = map(int,input().split())
    ans = 0 
    if b == 1:
        ans += 1
        b += 1
    while a > 0:
        if int(log(a,b)) >= int(log(a,b+1))+1:
            b+=1
        else:
            a = a // b
        ans+=1
    print(ans)
