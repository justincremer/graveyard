def genList(arr):
        length = len(arr)

        if length <= 1:
            return Node(arr[0], None)
        else:
            val = arr[0]
            arr.pop(0)

            return Node(val, genList(arr))

class Node:
    def __init__(self, val, next):
        self.val = val
        self.next = next

    def getNext(self):
        if self.next:
            return self.next

    def getcurrent(self):
        return self.current

class linkedList:
    def __init__(self, arr) :
        self.head = genList(arr)
        self.current = self.head

    def traverse(self, fn):
        fn(self.current.val)

        while(self.current.next):
            self.current = self.current.next
            fn(self.current.val)

if __name__ == '__main__':
    list = linkedList([0, 1, 2, 3, 4, 5])

    print('\n')
    list.traverse(print)

    list = linkedList(['h', 'e', 'l', 'l', 'o'])

    print('\n')
    list.traverse(print)
