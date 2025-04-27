# SSE 554 - Final Project - Intro to Wind Band Syllabus
## Software Purpose
This program is the Intro to Wind Band Syllabus. More often than not, high school students that have never been in a wind band setting don’t know the basics: reading sheet music, classifying instruments, chord fundamentals, and score studies. This program aims to offer a syllabus that covers these four topics, while also including the tools taught in SSE 554, including trees, linked lists, sorting algorithms, and search algorithms.

The first section of the program covers reading sheet music, including the fundamentals of a staff, note names, key signatures, and time signatures. This section includes the use of Search and Sorting Algorithms. The second section of the program covers instrument classifications, focusing on Woodwinds, Brass, and Percussion instruments. This section includes the use of Trees. The third section of the program covers the fundamentals of chords. This section includes the use of Stacks, Queues, and Templates. The fourth and final section of the program covers reading a score, including the score order of wind instruments. This section includes the use of Linked Lists and Templates. Data Representation and User Interfaces appear in the main menu.

## Running the Program
To run this program,

## Topics Covered
This project covers the following topics:
* Templates
* Linked Lists
* Stacks
* Queues
* Trees
* Big-O Notation
* Search Algorithms
* Sorting Algorithms
* Data Representation
* User Interfaces
As such, it uses many different classes to implement them all. This section will document how each topic is implimented and the relevant Classes and Methods.

### Templates
Temaplates are implemented as part of the ```Node``` class, which is used by the Linked Lists and Queues.
```
template <typename T> class Node{
    public:
        T data;
        Node* next;
        Node* prev;
        Node(T d){
            data = d;
            prev = NULL;
            next = NULL;
        }
};
```
The flexible ```typename T``` is used by the Linked List to implement a ```string``` and by the Queue to implement a ```int```.

### Linked Lists
Linked Lists appear in section four, which covers reading a score. The Linked List class has four built-in methods: ```append()```, ```display()```, ```goForward()```, and ```goBackward()```.
#### ```append()```
The ```append()``` method takes a string and adds it to the list. This method has a time and space complexity of O(n).
### ```display()```
The ```display()``` method has no input and simply prints the data in every ```Node<string>``` of the list. This method has a time complexity of O(n) and a space complexity of O(1).
### ```goForward()```
The ```goForward()``` method takes a ```Node<string>*``` and returns the next 

### Stacks and Queues


### Trees


### Big-O Notation


### Search Algorithms


### Sorting Algorithms


### Data Representation


### User Interfaces


## Testing

###
