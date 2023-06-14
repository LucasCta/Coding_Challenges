import math

class No:
    def __init__(self, data):
        self.e = data
        self.ant = None
        self.prox = None

class LinkedList:
    def __init__(self):
        self.head = None
    def insert(self, data):
        if self.head is None:
            self.head = No(data)
            return self.head
        new_node = No(data)
        self.head.ant = new_node
        new_node.prox = self.head
        self.head = new_node
        return new_node
    def print_list(self):
        current_node = self.head
        while current_node is not None:
            print(current_node.e, end=" ")
            current_node = current_node.prox
        print()    

def removeNo(no):
    no.ant = 


def GeraCrivo(n):
    L = LinkedList()
    C = []
    rN = int(n**1/2)
    for i in range(n,1,-1):
        C.append(L.insert(i))
    p = L
    while 
    return L

GeraCrivo(50).print_list()




