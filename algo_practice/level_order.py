class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
def printLevelOrder(root):
    h = height(root)
    for i in range(1, h+1):
        printGivenLevel(root, i)
            
            
            
            
def printGivenLevel(root, level):
    if not root:
        return 
    if level == 1:
        print(root.val)
    elif level > 1:
        printGivenLevel(root.left, level-1)
        printGivenLevel(root.right, level-1)
    
    
def height(node):
    if not node:
        print("0")
        return 0
    else:
        print("LH")
        lheight = height(node.left)
        print("RH")
        rheight = height(node.right)
        
            
        if lheight > rheight:
            print("L", lheight, "R", rheight)
            return lheight +1
        else:
            return rheight +1
                
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
printLevelOrder(root) 