#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Template Implementaion
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

//LinkedLists Setup
class LinkedList{
    public:
        Node<string>* head;
        LinkedList(){
            head = NULL;
        }

        void append(string d){
            Node<string>* newNode = new Node(d);

            if (head == NULL)
                head = newNode;
            else{
                Node<string>* temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        void display(){
            if (head == NULL)
                cout << "List is empty!" << endl;
            else{
                Node<string>* temp = head;
                while(temp != NULL){
                    cout << temp->data << endl;
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        Node<string>* goForward(Node<string>* node){
            Node<string>* temp = node;
            if(temp->next == NULL)
                cout << "Reached End of Score Order." << endl;
            else{
                temp = temp->next;
                cout << "Next: ";
                cout << temp->data << endl;
            }
            return temp;
        }

        Node<string>* goBackward(Node<string>* node){
            Node<string>* temp = node;
            if(temp->prev == NULL)
                cout << "Reached Top of Score Order." << endl;
            else{
                temp = temp->prev;
                cout << "Previous: ";
                cout << temp->data << endl;
            }
            return temp;
        }
};

//Queue Setup
class Queue{
    public:
        Node<int> *front, *rear;
        Queue(){
            front = rear = NULL;
        }

        void enqueue(int d){
            Node<int> *temp = new Node(d);
        
            if(rear == NULL){
                front = rear = temp;
            }
            else{
                rear->next = temp;
                rear = temp;
            }
        }

        void dequeue(){
            if(front == NULL){
                cout << "Empty queue." << endl;
            }
            else{
                Node<int> *temp = front;
                front = temp->next;
                delete(temp);
            }
        }
};

//Tree Setup
class TreeNode{
    public:
        string info;
        TreeNode* left;
        TreeNode* right;

        TreeNode(string info, TreeNode* left = NULL, TreeNode* right = NULL){
            this->info = info;
            this->left = left;
            this->right = right;
        }
};

void imSearch(TreeNode* tree, int level = 0){
    char ans;
    if(tree != NULL){
        cout << tree->info << endl;
        ans = ' ';

        if(tree->left == NULL){
            cout << endl;
        }
        else{
            cin >> ans;

            if(ans == 'y'){
                imSearch(tree->left, level+1);
            }
            else if(ans == 'n'){
                imSearch(tree->right, level+1);
            }
            else{
                cout << "Sorry, that was an invalid answer." << endl << endl;
            }
        }
    }
}

//Search Algorithm Setup
int linSearch(string list[], int length, string note){
    for(int i = 0; i < length; i++){
        if(list[i] == note){
            return i;
        }
    }
    return -1;
}

//Sort Algorithm Setup
int partition(int items[], int left, int right){
    int middle = (left+right)/2;
    int pivot = items[middle];
    items[middle] = items[right];
    items[right] = pivot;

    int boundary = left;

    for(int index = left; index < right; index++){
        if(items[index] < pivot){
            int temp = items[index];
            items[index] = items[boundary];
            items[boundary] = temp;

            boundary += 1;
        }
    }

    int temp = items[right];
    items[right] = items[boundary];
    items[boundary] = temp;

    return boundary;
}

void quickRecurse(int items[], int left, int right){
    if(left >= right){
        return;
    }

    int pivotPosition = partition(items, left, right);

    quickRecurse(items, left, pivotPosition-1);
    quickRecurse(items, pivotPosition+1, right);
}

void quickSort(int items[], int length){
    quickRecurse(items, 0, length-1);
}

void case1(){
    char temp;
    string noteSearch;
    int found, nums;
    string cMajor[8] = {"C", "D", "E", "F", "G", "A", "B", "C"};
    int times[5];
    cout << "Reading Sheet Music is integral to wind bands. The four major parts of reading sheet music are the Staff, Notes, Key Signature, and Time Signature." << endl << endl;  
    cout << "Would you like to learn about the (s)taff, (n)otes, (k)ey signature, or (t)ime signature?" << endl;
    cin >> temp;

    switch(temp){
        case 's':
            system("cls");
            cout << "The staff is made up of five lines and four spaces, each meant to hold a note. This is what a staff typically looks like:" << endl << endl;
            cout << " ___|)____/|_________|___________________" << endl;
            cout << "|___/____/_|__|______|___,--.o__|________||" << endl;
            cout << "|__/|______|__|-.__,-.___`--'___|________||" << endl;
            cout << "|_/(|,\\___/|__|/___`-'______|___|__,--.__||" << endl;
            cout << "|_\\_|_/__/_|________________|___|__`--'__||" << endl;
            cout << "  (_|      |" << endl <<endl;
            cout << "The first object on the staff is the Clef. It dictates which lines and spaces are which specific notes." << endl;
            cout << "The second object on the staff is the Time Signature. Input 't' on the previous menu to learn more." << endl;
            cout << "The third object on the staff is the Key Signature. Input 'k' on the previous menu to learn more." << endl;
            cout << "The next two objects on the staff are Notes. Input 'n' on the previous menu to learn more." << endl;
            cout << "The line after the first two notes is a Bar Line. It seperates different measures." << endl;
            cout << "After the bar line is another note. Input 'n' on the previous menu to learn more." << endl;
            cout << "The final object on the staff is a Double Bar Line. This indicates that the piece of music is over." << endl << endl;
            break;
        case 'n':
            system("cls");
            cout << "Notes are the actual music being played on the staff. They are all named after letters of the alphabet, from A to G before repeating." << endl;
            cout << "When eight notes are played in increasing order, that is called a scale. The simplest scale is C Major as it is just the notes without accidentals." << endl;
            cout << "What note in C Major would you like to search for?" << endl;
            cin >> noteSearch;

            //Search Algorithm Implementation
            found = linSearch(cMajor, 8, noteSearch);
            if(found != -1){
                cout << noteSearch << " is in C Major! It is note number " << found << " in the scale." << endl;
                cout << "The full C Major scale is C D E F G A B C." << endl << endl;
            }
            else{
                cout << noteSearch << " is not in C Major. The notes of C Major are C D E F G A B C." << endl << endl; 
            }

            cout << "Some notes can also be flat (b) or sharp (#), meaning they are between the normal notes." << endl;
            cout << "Notes that are flat are lower than their normal counterparts, and notes that are sharp are higher than their normal counterparts." << endl;
            cout << "For example, B-flat (Bb) is between A and B, while C-sharp (C#) is between C and D." << endl << endl;
            break;
        case 'k':
            system("cls");
            cout << "The Key Signature comes after the time signature on the staff and dictates which notes are sharp and flat." << endl;
            cout << "Sharps and flats are added to the key signature in a certain order. Flats are always added in this order:" << endl;
            cout << "B E A D G C F" << endl;
            cout << "while sharps are added in the opposite direction." << endl << endl;

            cout << "For example, adding two sharps to C Major would turn it from this:" << endl;
            cout << "C D E F G A B C" << endl;
            cout << "to this:" << endl;
            cout << "C# D E F# G A B C#" << endl << endl;
            break;
        case 't':
            system("cls");
            cout << "The Time Signature comes just after the clef on the staff and dictates two things:" << endl;
            cout << " * The top number in a time signature dictates how many beats will be in a measure." << endl;
            cout << " * The bottom number in a time signature dictates what type of note gets the beat." << endl << endl;
            
            cout << "For example, in 4/4 time, there are 4 beats in a measure, and the quarter note (1/4) gets the beat." << endl;
            //Sort Algorithm Implementation
            cout << "To help illustate this, please input five numbers:" << endl;
            for(int i = 0; i<5; i++){
                cin >> nums;
                times[i] = nums;
            }

            for(int i = 0; i<5; i++){
                cout << times[i] << "/4 ";
            }
            cout << "are your five time signatures." << endl;
            cout << "From shortest to longest measure length, they are:" << endl;
            quickSort(times, 5);
            for(int i = 0; i<5; i++){
                cout << times[i] << "/4 ";
            }
            cout << endl << endl;

            break;
        default:
            cout << "Sorry, that was not a valid option. Please return to the main menu and try again." << endl << endl;
            break;
    }
}

void case2(TreeNode* ww, TreeNode* brass, TreeNode* perc){
    char search;

    cout << "In most wind bands, there are 2 major classes of instruments: Woodwinds and Brass." << endl;
    cout << "Common Woodwinds include Flutes, Oboes, Clarinets, and Saxophones." << endl;
    cout << "Common Brass Instrumnets include Trumpets, French Horns, Trombones, Euphoniums, and Tubas." << endl;
    cout << "Percussion is also found in wind bands, commonly using Snare Drums, Bass Drums, Timapanis, Xylophones, and Cymbals." << endl;
    cout << "Let's search for some of these instruments. Would you like to search for (w)oodwinds, (b)rass, or (p)ercussion?" << endl;
    cin >> search;

    switch(search){
        case 'w':
            imSearch(ww);
            break;
        case 'b':
            imSearch(brass);
            break;
        case 'p':
            imSearch(perc);
            break;
        default:
            cout << "Sorry, that was not a valid option. Please return to the main menu and try again." << endl << endl;
            break;
    }
}

void case3(){
    char temp, chord;
    string major, minor;
    stack<char> notesS;
    Queue notesQ;

    cout << "When multiple notes are played at the same time, that is called a chord. This class covers to types of chords - major and minor." << endl;
    cout << "Would you like to learn about major (M) or minor (m) chords right now?" << endl;
    cin >> chord;

    switch(chord){
        case 'M':
            //Stack Implementation
            cout << "C D E F G A B C" << endl;
            cout << "This is a C scale. Major chords are made of the first, third, and fifth notes of a scale." << endl << endl;

            for (int i = 0; i<3; i++){
                cout << "Please enter the notes of the C major chord (in caps): ";
                cin >> temp;
                notesS.push(temp);
            }
        
            for (int i = 0; i<3; i++){
                temp = notesS.top();
                notesS.pop();
                major.push_back(temp);
            }
        
            //User Interface Implementation
            if(major == "GEC" || major == "GCE" || major == "EGC" || major == "ECG" || major == "CGE" || major == "CEG"){
                cout << "Correct! The C major chord is made up of the C (first), E (third), and G (fifth)!" << endl << endl;
            }
            else{
                cout << "Sorry, " << major[0] << ", " << major[1] << ", and " << major[2] << " aren't the correct notes in the chord." << endl << endl;
                cout << "The three notes in a C major chord are the C (first), E (third), and G (fifth)." << endl << endl;
            }
            break;
        case 'm':
            //Queue Implementation
            cout << "A B C D E F G A" << endl;
            cout << "This is an A natural minor scale. Minor chords are made of the first, third, and fifth notes of a natural minor scale." << endl << endl;

            for (int i = 0; i<3; i++){
                cout << "Please enter the notes of the A minor chord (in caps): ";
                cin >> temp;
                notesQ.enqueue(temp);
            }
        
            for (int i = 0; i<3; i++){
                temp = notesQ.front->data;
                notesQ.dequeue();
                minor.push_back(temp);
            }
        
            //User Interface Implimentation
            if(minor == "ACE" || minor == "AEC" || minor == "CAE" || minor == "CEA" || minor == "EAC" || minor == "ECA"){
                cout << "Correct! The A natural minor chord is made up of the A (first), C (third), and E (fifth)!" << endl << endl;
            }
            else{
                cout << "Sorry, " << minor[0] << ", " << minor[1] << ", and " << minor[2] << " aren't the correct notes in the chord." << endl;
                cout << "The three notes in an A natural minor chord are the A (first), C (third), and E (fifth)." << endl << endl;
            }
            break;
        default:
            cout << "Sorry, that was not a valid option. Please return to the main menu and try again." << endl << endl;
            break;
    }
}

void case4(LinkedList l){
    //LinkedList Implimentation
    char temp, travel;
    Node<string>* im = l.head;

    cout << "For conductors, sheet music is arranged in a 'Score', where all the parts are stacked on top of each other. This is the typical score order for wind bands:" << endl << endl;
    l.display();

    cout << "In a Score, every note and bar is aligned so the conductor knows exactly what is going on throughout the piece. Scores are also very useful for music studies." << endl; 
    cout << "Would you like to traverse through the score order? (y/n)" << endl;
    cin >> temp;
    switch(temp){
        case 'y':
            system("cls");
            cout << "Top of Score: Flute" << endl;
            cout << "Enter (n)ext instrument, (p)revious instrument, or (e)xit." << endl;
            while (travel != 'e'){
                cin >> travel;
                switch (travel){
                    case 'n':
                        im = l.goForward(im);
                        cout << "Enter (n)ext instrument, (p)revious instrument, or (e)xit." << endl;
                        break;
                    case 'p':
                        im = l.goBackward(im);
                        cout << "Enter (n)ext instrument, (p)revious instrument, or (e)xit." << endl;
                        break;
                    case 'e':
                        break;
                    default:
                        cout << travel << " is an invalid input. Enter (n)ext instrument, (p)revious instrument, or (e)xit)." << endl;
                        break;
                }
            }
            break;
        case 'n':
            break;
        default:
        cout << "Sorry, that was not a valid option. Please return to the main menu and try again." << endl << endl;
        break;
    }

}

int main() {
    char topic, buffer;
    string major, minor;

    //Create LinkedList
    LinkedList scoreOrder;

    scoreOrder.append("Flute");    scoreOrder.append("Oboe");     scoreOrder.append("Clarinet");   scoreOrder.append("Saxophone"); scoreOrder.append("French Horn");
    scoreOrder.append("Trumpet");  scoreOrder.append("Trombone"); scoreOrder.append("Euphonium");  scoreOrder.append("Tuba");      scoreOrder.append("Percussion");

    //------------------------------------------

    //Create Woodwind Tree
    //Tree Base
    TreeNode* wwFind = new TreeNode("Does the instrumnet you're thinking of use a reed? (y/n)");
    //Level 1
    wwFind->left = new TreeNode("Does the instrumnet you're thinking of have a double reed? (y/n)");
    wwFind->right = new TreeNode("You're thinking of a Flute!");
    //Level 2
    wwFind->left->left = new TreeNode("You're thinking of an Oboe!");
    wwFind->left->right = new TreeNode("Is the instrument you're thinking of usually golden? (y/n)");
    //Level 3
    wwFind->left->right->left = new TreeNode("You're thinking of a Saxophone!");
    wwFind->left->right->right = new TreeNode("You're thinking of a Clarinet!");

    //Create Brass Tree
    //Tree Base
    TreeNode* brassFind = new TreeNode("Does the instrument you're thinking of have keys to press? (y/n)");
    //Level 1
    brassFind->left = new TreeNode("Does the instrument you're thinking of use valves? (y/n)");
    brassFind->right = new TreeNode("You're thinking of a Trombone!");
    //Level 2
    brassFind->left->left = new TreeNode("Is the instrument you're thinking of usually silver? (y/n)");
    brassFind->left->right = new TreeNode("You're thinking of a French Horn!");
    //Level 3
    brassFind->left->left->left = new TreeNode("You're thinking of a Euphonium!");
    brassFind->left->left->right = new TreeNode("Is the instrumnet you're thinking of very large? (y/n)");
    //Level 4
    brassFind->left->left->right->left = new TreeNode("You're thinking of a Tuba!");
    brassFind->left->left->right->right = new TreeNode("You're thinking of a Trumpet!");

    //Create Percussion Tree
    //Tree Base
    TreeNode* percFind = new TreeNode("Is the instrument you're thinking of a pitched instrument? (y/n)");
    //Level 1
    percFind->left = new TreeNode("Is the instrumnet you're thinking of a type of drum? (y/n)");
    percFind->right = new TreeNode("Is the instrumnet you're thinking of a type of drum? (y/n)");
    //Level 2
    percFind->left->left = new TreeNode("You're thinking of a Timpani!");
    percFind->left->right = new TreeNode("You're thinking of a Xylophone!");
    percFind->right->left = new TreeNode("Is the instrumnet you're thinking of very large? (y/n)");
    percFind->right->right = new TreeNode("You're thinking of a Cymbal!");
    //Level 3
    percFind->right->left->left = new TreeNode("You're thinking of a Bass Drum!");
    percFind->right->left->right = new TreeNode("You're thinking of a Snare Drum!");

    //---------------------------------

    //Main Menu
    //Data Representation Implementation
    cout << u8"\U0001F3B6";
    cout << "Welcome to the Intro to Wind Band Syllabus. Please select a topic to cover:";
    cout << u8"\U0001F3B6" << endl;
    cout << "1. Reading Sheet Music" << endl << "2. Instrument Classifications" << endl << "3. Chords" << endl << "4. Reading a Score" << endl << endl << "0. Exit Program" << endl;
    cin >> topic;
    while(true){
        system("cls");
        switch(topic){
            case '1':
                case1();
                cout << "Press any key to return to the main menu." << endl;
                cin >> buffer;
                break;
            case '2':
                case2(wwFind, brassFind, percFind);
                cout << "Press any key to return to the main menu." << endl;
                cin >> buffer;
                break;
            case '3':
                case3();
                cout << "Press any key to return to the main menu." << endl;
                cin >> buffer;
                break;
            case '4':
                case4(scoreOrder);
                cout << "Press any key to return to the main menu." << endl;
                cin >> buffer;
                break;
            case '0':
                cout << u8"\U0001F3B6";
                cout << "Thank you for using the Intro to Wind Band Syllabus program.";
                cout << u8"\U0001F3B6" << endl;
                cout << "Press any key to exit." << endl;
                cin >> buffer;
                return 0;
                break;
            default:
                cout << "Sorry, '" << topic << "' is an invalid input. Press any key to try again." << endl;
                cin >> buffer;
                break;
        }
        system("cls");
        //Data Representation Implementation
        cout << "Please select a topic to cover:" << endl;
        cout << "1. The Staff and Notes" << endl << "2. Instrument Classifications" << endl << "3. Chords" << endl << "4. Reading a Score" << endl << endl << "0. Exit Program" << endl;
        cin >> topic;
    }

    return 0;
}