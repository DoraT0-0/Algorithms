from turtle import *
angle = 40
length = 100
count_circle = 10

pencolor("black")
pensize(3)

def circle_color(color: str):
    fillcolor(color)
    begin_fill()
    circle(length)
    end_fill()

for x in range(count_circle):
    match x%2 == 0:
        case True: circle_color("red")
        case False: circle_color("green")
    left(angle)
done()