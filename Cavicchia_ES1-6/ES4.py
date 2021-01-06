def encode ():
    parola=input("Inserisci la parola di cui fare encode: ")
    for let in parola:
        let=ord(let)+15
        if (let>90 and let<97) or let>122:
            let=let-26
        print(chr(let),end='')
def decode ():
    parola=input("Inserisci la parola di cui fare decode: ")
    for let in parola:
        let=ord(let)-15
        if let<65 or (let<97 and let>90):
            let=let+26
        print(chr(let),end='')
option=int(input("Premi 1 per encode; 2 per decode."))
while option!=1 and option!=2:
    option= int(input("Hai inserito un carattere invalido. Premi 1 per encode; 2 per decode.  "))
if option==1:
    encode()
if option==2:
    decode()