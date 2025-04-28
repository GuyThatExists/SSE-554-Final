# SSE 554 - Final Project - Intro to Wind Band Syllabus
## Software Purpose
This program is the Intro to Wind Band Syllabus. More often than not, high school students that have never been in a wind band setting don’t know the basics: reading sheet music, classifying instruments, chord fundamentals, and score studies. This program aims to offer a syllabus that covers these four topics, while also including the tools taught in SSE 554, including trees, linked lists, sorting algorithms, and search algorithms.

The first section of the program covers reading sheet music, including the fundamentals of a staff, note names, key signatures, and time signatures. This section includes the use of Search and Sorting Algorithms. The second section of the program covers instrument classifications, focusing on Woodwinds, Brass, and Percussion instruments. This section includes the use of Trees. The third section of the program covers the fundamentals of chords. This section includes the use of Stacks, Queues, and Templates. The fourth and final section of the program covers reading a score, including the score order of wind instruments. This section includes the use of Linked Lists and Templates. Data Representation and User Interfaces appear in the main menu.

## Running the Program
This program can be run by simply downloading and clicking on the .exe file.

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
Temaplates are implemented as part of the ```Node``` class, which is used by the Queue and Linked List, in sections three and four respectively.
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
The ```goForward()``` method takes a ```Node<string>*``` and returns the next ```Node<string>*``` in the list. Both it and the following ```goBackward()``` method have a time and space complexity of O(1).
### ```goBackward()```
The ```goBackward()``` method takes a ```Node<string>*``` and returns the previous ```Node<string>*``` in the list.

### Stacks and Queues
Stacks and Queues appear in section three, which covers chords. Stacks are implimented with ```#include <stack>```, and the Queue class has two built-in methods: ```enqueue()``` and ```dequeue()```. They add or remove items from the queue respectivley, and have a time and space complexity of O(1).

### Trees
Trees appear in section two, which covers the classifications of different instruments. The ```TreeNode``` class, rather than the templated ```Node``` class, needs two more inputs than the base ```Node``` class. The main method used to traverse the trees is ```imSearch()```, or **i**nstru**m**ent **search**. This method takes a ```TreeNode*``` and a ```level``` on the tree and then traverses down the tree based on answers to questions, stored on the ```TreeNode```s. This method has a time and space complexity of O(n).

### Big-O Notation
Big-O notation appears in this documentation rather than the code of the project itself. Each subheading in this setion displays the time and space complexity of the relevant methods. Overall, the program has a time complexity of O(kn), where k is the number of interactions with the program, and a space complexity of O(n).

### Search Algorithms
A search algorithm appears in section one, which covers reading sheet music. More specifically, a Linear Search Algorithm is used to explain note names in the C Major scale. The Linear Search Algorithm has a time complexity of O(n) and a space complexity of O(1).

### Sorting Algorithms
A sorting algorithm appears in section one, which covers reading sheet music. More specifically, a QuickSort Algorithm is used to explan time signatures and their relation to each other. The QuickSort algorithm has a time complexity of O(n log n) and a space complexity of O(log n)

### Data Representation
Data Representation, specifically the use of unicode emoji characters. When the program first opens, the menu is captioned with:
```🎶Welcome to the Intro to Wind Band Syllabus. Please select a topic to cover:🎶```

When the program is closed, this line is used:
```🎶Thank you for using the Intro to Wind Band Syllabus program.🎶```

### User Interfaces
User Interfaces are used throughout the program, as user interaction occurs at nearly every step. 

## Testing
Testing of this program occured as it was being developed, with stress tests on every ```char```, ```string```, and ```int``` input to make sure that invalid inputs were accounted for, and the sorting and search algorithms were tested to make sure that they ran correctly. Logic testing was also performed before the vast majority of text was added to the program to make sure that the program flowed into the intended methods.
