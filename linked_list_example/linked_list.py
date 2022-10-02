class Node:
    def __init__(self,val):
        self.val = val
        self.next:Node = None
    def __repr__(self) -> str:
        return self.val
    
class LinkedList:
    def __init__(self,val):
        self.head = Node(val)
    
    def insert(self,val,position=-1):
        current = self.head
        #caso seja -1 o valor será adicionado na última posição
        if(position==-1):
            while(current.next != None):
                current = current.next
            current.next = Node(val)
            return

        elif(position==0):
            self.push(val)
            return

        for _ in range(position-1):
            current = current.next
        
        new_node = Node(val)
        new_node.next = current.next
        current.next = new_node
        return
    def push(self,val):
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node
        return
    
    def remove(self,pos):
        if(pos == 0):
            self.head = self.head.next
            return
        current = self.head

        for _ in range(pos-1):
            current = current.next
        next = current.next
        current.next = next.next
        return

    def removeByKey(self,key):
        current = self.head

        if(current.val == key):
            self.head = self.head.next
            return

        while current.next.val != key:
            current = current.next

        next = current.next
        current.next = next.next
        return

    def __repr__(self) -> str:
        node = self.head
        value_list = []

        while node is not None:
            value_list.append(node.val)
            node = node.next
        return "->".join(value_list)

def main():
    lista = LinkedList("Anta")
    lista.insert("Paca")
    lista.insert("Tatu")
    lista.insert("Cotia")
    lista.insert("Prea")
    print(lista)    
    lista.remove(0)
    print(lista)
    lista.insert("leão")
    print(lista)
    lista.remove(3)
    print(lista)
    lista.removeByKey("Tatu")
    print(lista)
if __name__ == "__main__":
    main()