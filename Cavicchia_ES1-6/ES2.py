import random
def Generate():
    for i in range(6):
        opt=random.randint(0, 3)
        if opt==1:
            a=random.randint(48, 57)
        else:
            a=random.randint(65, 70)
        opt=random.randint(0, 3)
        if a==1:
            b=random.randint(48, 57)
        else:
            b=random.randint(65, 70)
        if i<6:
            print(chr(a)+chr(b)+":", end='')
        else:
            print(chr(a)+chr(b))
inizia=input("Premi invio per generare un indirizzo mac: ")
Generate()