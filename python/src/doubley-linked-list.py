class Node:
    def __init__(self, current, next, previous):
        self.current = current
        self.next = next
        self.previous = previous

def generateList(nodes):
    length = len(nodes)

    if nodes:
        for i in range(length):
            if i == 0:
                nodes[i].next = nodes[i + 1]
            elif i == length - 1:
                nodes[i].previous = nodes[i - 1]
            else:
                nodes[i].next = nodes[i + 1]
                nodes[i].previous = nodes[i - 1]

    return nodes

def traverseForward(list, fn):
    fn(list.current)

    if list.next:
        traverseForward(list.next, fn)

def traverseBackward(list, fn): 
    fn(list.current)

    if list.previous:
        traverseBackward(list.previous, fn)


if __name__ == '__main__':
    nodes = [
        Node(0, None, None),
        Node(1, None, None),
        Node(2, None, None),
        Node(3, None, None),
        Node(4, None, None),
        Node(5, None, None),
    ]

    nodes = generateList(nodes)
    head = nodes[0]
    tail = nodes[len(nodes) - 1]

    print('\nForward')
    traverseForward(head, print)
    print('\nBackward')
    traverseBackward(tail, print)

