class State:
    def __init__(self, n, A, B, C):
        self.n = n
        self.A = A
        self.B = B
        self.C = C


class Hannoi:
    def __init__(self, n, A, B, C):
        self.n = n
        self.A = A
        self.B = B
        self.C = C

    def solve(self):
        if self.n == 0:
            print("Please input vaild n, it should > 0")
            return
        stack = []
        s = State(self.n, "A", "B", "C")
        stack.append(s)
        while stack:
            cur = stack.pop()
            if cur.n == 1:
                print("move " + cur.A + " to " + cur.C)
            else:
                stack.append(State(cur.n - 1, cur.B, cur.A, cur.C))
                stack.append(State(1, cur.A, cur.B, cur.C))
                stack.append(State(cur.n - 1, cur.A, cur.C, cur.B))


h = Hannoi(3, "A", "B", "C")
h.solve()
