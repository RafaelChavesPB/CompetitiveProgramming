from math import pi

n = int(input())
arr = [int(x) for x in input().split()]
arr.append(0)
arr.sort()
ans = 0
if n%2==0:
    for i in range(2,len(arr),2):
        ans+=(pi*(arr[i])**2-pi*(arr[i-1])**2)
else:
    for i in range(1,len(arr),2):
        ans+=(pi*(arr[i])**2-pi*(arr[i-1])**2)
print(f'{ans:.5f}')