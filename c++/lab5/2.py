from turtle import *
def draw_circles(angle: int, length: int, count_circle: int):
    pencolor("black")
    pensize(3)

    def circle_color(color: str):
        fillcolor(color)
        begin_fill()
        circle(length)
        end_fill()

    for x in range(count_circle):
        if x % 2 == 0:
            circle_color("red")
        else:
            circle_color("green")
        left(angle)


import unittest
class TestDrawCircles(unittest.TestCase):
    def test_draw_circles(self):
        try:
            draw_circles(40, 100, 10)
            executed = True
        except Exception as e:
            executed = False
            print(f"Test failed with error: {e}")

        self.assertTrue(executed, "draw_circles should execute without errors")

if __name__ == '__main__':
    unittest.main()
