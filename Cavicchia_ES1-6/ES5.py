import turtle
import time
import random

def move():
    if punta.direction == "up":
        y = punta.ycor()
        punta.sety(y + 20)

    if punta.direction == "down":
        y = punta.ycor()
        punta.sety(y - 20)

    if punta.direction == "left":
        x = punta.xcor()
        punta.setx(x - 20)

    if punta.direction == "right":
        x = punta.xcor()
        punta.setx(x + 20)

def move_up():
    if punta.direction != "down":
        punta.direction = "up"
def move_down():
    if punta.direction != "up":
        punta.direction = "down"
def move_left():
    if punta.direction != "right":
        punta.direction = "left"
def move_right():
    if punta.direction != "left":
        punta.direction = "right"
def eat():
    x = random.randint(-sp, sp)
    y = random.randint(-sp, t_sp - 40)
    cibo.goto(x, y)

    coda_agg= turtle.Turtle()
    coda_agg.speed(0)
    coda_agg.shape("square")
    coda_agg.color("green")
    coda_agg.penup()
    coda.append(coda_agg)

def move_coda():
    for index in range(len(coda)-1, 0, -1):
        x = coda[index-1].xcor()
        y = coda[index-1].ycor()
        coda[index].goto(x, y)

    if len(coda) > 0:
        x = punta.xcor()
        y = punta.ycor()
        coda[0].goto(x, y)

def reset():
    time.sleep(1)
    for index in coda:
        index.goto(d + 1000, d + 1000)
    coda.clear()
    punta.goto(0,0)
    punta.direction = "stop"

coda = []

d = 600
sp = d/2 - 20
t_sp = sp - 30
delay = 0.07
punti = 0
h_punti = 0

sc = turtle.Screen()
sc.title("Snake...or Python?")
sc.bgcolor("black")
sc.setup(width = d, height = d)
sc.tracer(0)

line = turtle.Turtle()
line.speed(0)
line.color("yellow", "green")
line.penup()
line.hideturtle()
line.goto(d/2, t_sp)
line.begin_fill()
line.pendown()
line.goto(-d/2, t_sp)
line.goto(-d/2, d/2)
line.goto(d/2, d/2)
line.goto(d/2, t_sp)
line.end_fill()

text = turtle.Turtle()
text.speed()
text.color("yellow")
text.penup()
text.hideturtle()
text.goto(0, 260)
text.write("Punteggio: {} ".format(punti, h_punti), align = "center", font = ("Helvetica", 10, "normal"))
punta = turtle.Turtle()
punta.speed(0)
punta.shape("circle")
punta.color("green")
punta.penup()
punta.goto(0,0)
punta.direction = "stop"

cibo = turtle.Turtle()
cibo.speed(0)
cibo.shape("circle")
cibo.color("red")
cibo.penup()
x = random.randint(-sp, sp)
y = random.randint(-sp, sp - 40)
cibo.goto(x, y)

sc.listen()
sc.onkeypress(move_up, "Up")
sc.onkeypress(move_down, "Down")
sc.onkeypress(move_left, "Left")
sc.onkeypress(move_right, "Right")

sc.onkeypress(move_up, "w")
sc.onkeypress(move_down, "s")
sc.onkeypress(move_left, "a")
sc.onkeypress(move_right, "d")

while True:
    sc.update()
    if punta.xcor() > sp or punta.xcor() < -sp or punta.ycor() > t_sp - 20 or punta.ycor() < -sp:
        reset()
        punti = 0
    if punta.distance(cibo) < 20:
        eat()
        punti += 10
        if punti > h_punti:
            h_punti = punti
    move_coda()
    move()
    text.clear()
    text.write("Score: {}".format(punti, h_punti), align = "center", font = ("Helvetica", 10, "normal"))
    for index in coda:
        if index.distance(punta) <20:
            reset()
            punti = 0
    time.sleep(delay)

sc.mainloop()