ok1=0
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end="  ")
            temp = temp.next
        print("\n", end="")

class Carte:
    def Search_author(self,nume1,titlu1):
        Nume=[]
        global asd
        global ok1
        titlu = input("Enter the book title: ")
        nrautori= int(input("Enter the number of authors of the book: "))
        for i in range(nrautori):
            name=input("Enter the author name: ")
            if nume1==name:
                ok1+=1
                print(titlu)
            Nume.append(name)
            if titlu == titlu1:
                print(Nume)

Library=LinkedList()
nume=input("Find the books of an given author (Enter the author name): ")
titlu=input("Find the authors of an given book (Enter the book title): ")
nr_books=int(input("Enter the number of book in the library: "))
for j in range (nr_books):
    j2 = Carte()
    j2.Search_author(nume,titlu)
    Library.append(j2)
Library.printList()