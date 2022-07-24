
n=int(input())
acc=1
c5=0
c2=0
for i in range(2,n+1):
    acc*=i
    while acc%2==0:
        c2+=1
        acc//=2
    while acc%5==0:
        c5+=1
        acc//=5
    if c2>=c5:
        c2-=c5
        c5=0
    else:
        c5-=c2
        c2=0
    acc%=1000
acc*=(5**c5)
acc*=(2**c2)
acc%=1000
answer=str(acc)
while len(answer)<3 and n>6:
    answer='0'+answer
print(answer)