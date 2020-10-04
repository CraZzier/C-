
import random

def wylosuj():
    num = random.randint(0,36)
    return num

def color(liczba):
    czerwony = (3,12,7,18,9,14,1,16,5,23,30,27,36,34,25,21,19,32)
    zielony = (0,-1)
    if liczba in czerwony:
        return "czerwony"
    elif liczba in zielony:
        return "zielony"
    else:
        return "czarny"




saldo = 1000
while(saldo>0):
    print("Saldo wynosi:{} ".format(saldo))
    [kwota,kolor]=raw_input().split(" ")
    kwota = int(kwota)
    if kwota > saldo:
        print("Brak funduszy sprobuj raz jeszcze".decode('UTF8'))
        continue
    saldo -= kwota
    wyl = wylosuj()
    col = color(wyl)
    if col==kolor and col=="zielony":
        saldo += kwota*36
        print("Wypadla liczba {} jest ona przypisana do koloru {} .Wygrales {} masz teraz {}".format(wyl,col,kwota*36,saldo).decode('UTF8'))
    elif col==kolor and col!="zielony":
        saldo += kwota*2
        print("Wypadla liczba {} jest ona przypisana do koloru {} .Wygrales {} masz teraz {}".format(wyl,col,kwota*2,saldo).decode('UTF8'))
    else:
        print("Wypadla liczba {} jest ona przypisana do koloru {} . Nic nie wygrales. Obstawiales {}".format(wyl,col,kolor).decode('UTF8'))
print("Przegrales".decode('UTF8'))




