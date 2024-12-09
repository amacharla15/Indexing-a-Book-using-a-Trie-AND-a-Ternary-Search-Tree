Indexing a Book Using Trie and Ternary Search Tree
Project Description
This project implements an alphabetical index of words appearing in a text file and their corresponding line numbers using two data structures:

Trie
Ternary Search Tree (TST)
The program reads a text file from standard input, tokenizes the text into words (ignoring case and punctuation), and builds an index for word occurrences. The index can then be printed in lexicographical order.

Files
Project3Part1.cpp: Contains the implementation of the Trie data structure.
Project3Part2.cpp: Contains the implementation of the Ternary Search Tree (TST).
README.md: This file, providing an overview of the project.
Test files:
input1.txt, expectedoutput1.txt
input2.txt, expectedoutput2.txt
input3.txt, expectedoutput3.txt
Instructions
Compilation
To compile the code for the Trie implementation:

bash
Copy code
g++ -o trie.out -std=c++11 -Wall Project3Part1.cpp
To compile the code for the TST implementation:

bash
Copy code
g++ -o tst.out -std=c++11 -Wall Project3Part2.cpp
Execution
Run the program using standard input redirection:

bash
Copy code
./part1 < input1.txt > trieoutput1.txt
bash
Copy code
./part2 < input1.txt > tstoutput1.txt
Compare the generated output with the expected output:

bash
Copy code
diff -w trieoutput1.txt expectedoutput1.txt
diff -w tstoutput1.txt expectedoutput1.txt
Example Input and Output
Input (in input1.txt):
bash
Copy code
It was the best of times,
it was the worst of times,
it was the age of wisdom,
it was the age of foolishness,
Expected Output:
bash
Copy code
age 3, 4
best 1
foolishness 4
it 1, 2, 3, 4
of 1, 2, 3, 4
the 1, 2, 3, 4
times 1, 2
was 1, 2, 3, 4
wisdom 3
worst 2
