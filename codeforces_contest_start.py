t = int(input())
for i in range(t):
    n,x,c = map(int,input().split())
    k = c//x 
    ans = 0
    if k>=n:
        ans = (n*(n-1))//2
    else:
        ans = k*(n-k) + ((k-1)*k)//2
    print(ans)


    # s = "abcdefg"  num = s[0] - 'a' + 1