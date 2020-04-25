
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def serialize(node):
    traverse_in_order(node)

def traverse_in_order(node):
    serialized = ""
    stack = []
    visited = {} 

    
    current = node
    while len(stack) > 0:

        stack.push(current)
        current =  

        if n not in visited:
            visited.add(n)

    if node == None:
        serialized += '-'
        return

    serialized += '('
    traverse_in_order(node.left)
    serialized += ',' + node.val + ','
    traverse_in_order(node.right)
    serialized += ')'


def deserialize(string):
    pass

if __name__ == '__main__':
    node = Node('root',Node('left',Node('left.left')),Node('right'))
    serialize(node)
    print(serialized)


