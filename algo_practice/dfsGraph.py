class Node:
    # Constructor to create a new node 
    def __init__(self, val): 
        self.val = val
        self.left = None
        self.right = None

def in_order(root):
    stack =[]
    cur = root
    done = False
    
    while not done:
        if cur:
            stack.append(cur)
            cur = cur.left
        else:
            if stack:
                cur = stack.pop()
                print(cur.val)
                cur = cur.right
            else:
                done = True

""" Constructed binary tree is 
            1 
          /   \ 
         2     3 
       /  \ 
      4    5   """
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
in_order(root) 