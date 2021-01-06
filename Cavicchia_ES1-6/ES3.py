def sequenza_fib(fibonacci,n,a,b):
    if n<=0:
        return
    else:
        fibonacci.append(fibonacci[a]+fibonacci[b])
        a+=1
        b+=1
        n-=1
        sequenza_fib(fibonacci,n,a,b)
fibonacci=[0, 1]
a=0
b=1
n=int(input("Inserisci il numero di numeri che vuoi calcolare: "))
sequenza_fib(fibonacci,n,a,b)
print(fibonacci[1:])