#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

const int ALPHABET_SIZE = 26;

class Trie {
private:
    class Node {
    public:
        Node* children[ALPHABET_SIZE];
        set<int> lineNumbers;
        bool isEndOfWord;

        Node() : isEndOfWord(false) {
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

    string formatword(const string& word) {
        string result;
        for (char c : word) {
            if (isalpha(c)) result += tolower(c);
        }
        return result;
    }

    void printIndex(Node* node, string prefix) {
        if (!node) return;

        if (node->isEndOfWord) {
            cout << prefix << " ";
            for (auto it = node->lineNumbers.begin(); it != node->lineNumbers.end(); ++it) {
                if (it != node->lineNumbers.begin()) cout << ", ";
                cout << *it;
            }
            cout << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                printIndex(node->children[i], prefix + char('a' + i));
            }
        }
    }

    void deleteTrie(Node* node) {
        if (!node) return;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            deleteTrie(node->children[i]);
        }
        delete node;
    }

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        deleteTrie(root);
    }

    void insert(const string& word, int line) {
        string sanitizedWord = formatword(word);
        if (sanitizedWord.empty()) return;

        Node* current = root;
        for (char c : sanitizedWord) {
            int index = c - 'a';
            if (!current->children[index]) {
                current->children[index] = new Node();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
        current->lineNumbers.insert(line);
    }

    void printIndex() {
        printIndex(root, "");
    }
};

int main() {
    Trie trie;
    string line;
    int lineNumber = 1;

    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            trie.insert(word, lineNumber);
        }
        ++lineNumber;
    }

    trie.printIndex();

    return 0;
}
