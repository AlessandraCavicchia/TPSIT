import random
def randomize_simple():
    for i in range(8):
        opt=random.randint(1, 3)
        if opt2==1:
            a=random.randint(48,57)
        elif opt2==2:
            a=random.randint(65,90)
        else:
            a=random.randint(97,122)
        print(chr(a), end = '')
def randomize_complex():
        for i in range(20):
            a=random.randint(1,255)
            print(chr(a), end='')
opt2=int(input("Premere 1 per la password corta, 2 per password lunga: "))
while opt2!=1 and opt2!=2:
    opt2=int(input("Il carattere selezionato è invalido.  Premere 1 per la password corta, 2 per password lunga: "))
if opt2==1:
    randomize_simple()
if opt2==2:
    randomize_complex()