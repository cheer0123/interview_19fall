
class Node: 
    # A utility function to create a new node 
    def __init__(self ,val): 
        self.val = val
        self.left = None
        self.right = None

def level_order(root):
    if not root:
        return 
    queue = []
    queue.append(root)
    
    while queue:
        print(queue[0].val)
        node = queue.pop(0)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
level_order(root)