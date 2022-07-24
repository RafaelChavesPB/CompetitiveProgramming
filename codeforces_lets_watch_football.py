a,b,c = map(int,input().split())
d = a*c
print(d//b+(d%b!=0)-c)