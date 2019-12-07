

def serch_node(root, key):

    if not root:
        return False
    
    node = root
    parent = None
    while node and  root.val != key:
        if node.val > key:
            parent = node
            node = root.left
        elif node.val < key:
            parent = node
            node = root.right
        elif node.val == key:
            return node, parent
        
    else:
        return False


serch_node([5,3,6,2,4,null,7], 3)