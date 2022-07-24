while True:
    try:
        n=int(input())
        cont=0
        rest=0
        while True:
            rest=rest*10+1
            rest%=n
            cont+=1
            if not rest:
                print(cont)
                break
    except:
        break
