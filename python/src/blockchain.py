import hashlib


def genHash(input):
    return hashlib.sha512(str(input).encode('utf-8')).hexdigest()


def blockHash(transaction, previousHash):

    content = genHash(transaction), previousHash
    return genHash(content)


class Block:
    def __init__(self, transaction, previousHash):
        self.transaction = transaction
        self.previousHash = previousHash
        self.blockHash = blockHash(self.transaction, self.previousHash)
        self.observer = None

    def getPreviousHash(self):
        return self.previousHash

    def getTransaction(self):
        return self.transaction

    def setTransaction(self, input):
        self.transaction = input

    def getBlockHash(self):
        return self.blockHash

    def setBlockHash(self, input):
        self.blockHash = input

    def _bind(self, callback):
        self.observer = callback

    def __str__(self):
        print("\nTransaction:", self.getTransaction(),
              "\nHash:", self.getBlockHash())


class BlockChain:
    def __init__(self, transactions: None):
        self.head = Block
        self.blocks = [Block("head", genHash("head"))]
        self.length = 1

        for t in transactions:
            self.blocks.append(Block(t, self.blocks[-1].getBlockHash()))
            self.length += 1

    def getLength(self):
        return self.length

    def getBlockByIndex(self, i):
        return self.blocks[i]

    def __str__(self):
        for b in self.blocks:
            b.__str__()


if __name__ == '__main__':
    numbers = ["one", "two", "three", "four", "five",
               "six", "seven", "eight", "nine", "ten"]
    chains = []

    chains.append(BlockChain(numbers))
    numbers[9] = "tens"

    chains.append(BlockChain(numbers))
    numbers[6] = "sevens"

    chains.append(BlockChain(numbers))

    for i in range(chains[0].getLength()):
        print("\n\nBlock:", i, "\n")

        for c in chains:
            block = c.getBlockByIndex(i)
            print(block.__str__())

            # blockchain = []
            # blockchain.append(Block("head", hashlib.sha512(
            #     "head".encode('utf-8')).hexdigest()))

            # for n in numbers:
            #     blockchain.append(Block(n, blockchain[-1].getBlockHash()))

            # for b in blockchain:
            #     b.__str__()

            # blockchain[7].setTransaction("sevens")
