class MinStack:

    def __init__(self):
        self.stack = []
        self.min = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.min or val <= self.min[-1]:
            self.min.append(val)

    def pop(self) -> None:
        el = self.stack.pop()
        if el == self.min[-1]:
            self.min.pop()
        return el

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min[-1]

st = MinStack()

st.push(-1)
st.push(0)
st.push(1)
st.push(3)

print(st.pop())
print(st.top())
st.push(6)

print(st.getMin())


#st.print_()