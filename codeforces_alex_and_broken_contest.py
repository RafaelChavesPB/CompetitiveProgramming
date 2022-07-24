# Problema disponivel em: https://codeforces.com/problemset/problem/877/A
s = input()
acc = 0
names ={"Danil","Olya","Slava","Ann","Nikita"}
for i in range(len(s)):
    for j in range(i+1,len(s)+1):
        if s[i:j] in names:
            acc+=1
if acc == 1:
    print("YES")
else:
    print("NO")   
    