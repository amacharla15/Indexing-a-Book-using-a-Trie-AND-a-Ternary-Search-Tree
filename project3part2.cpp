#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

class TST {
private:
    class Node {
    public:
        char data;
        bool isEndOfWord;
        set<int> lineNumbers;
        Node* left;
        Node* equal;
        Node* right;

        Node(char val) : data(val), isEndOfWord(false), left(nullptr), equal(nullptr), right(nullptr) {}
    };

    Node* root;

    string formatword(const string& word) {
        string result;
        for (char c : word) {
            if (isalpha(c)) result += tolower(c);
        }
        return result;
    }

    Node* insert(Node* node, const char* word, int line) {
        if (!node) {
            node = new Node(*word);
        }

        if (*word < node->data) {
            node->left = insert(node->left, word, line);
        } else if (*word > node->data) {
            node->right = insert(node->right, word, line);
        } else {
            if (*(word + 1)) {
                node->equal = insert(node->equal, word + 1, line);
            } else {
                node->isEndOfWord = true;
                node->lineNumbers.insert(line);
            }
        }
        return node;
    }

    void printIndex(Node* node, string prefix) {
        if (!node) return;

        printIndex(node->left, prefix);

        prefix += node->data;
        if (node->isEndOfWord) {
            cout << prefix << " ";
            for (auto it = node->lineNumbers.begin(); it != node->lineNumbers.end(); ++it) {
                if (it != node->lineNumbers.begin()) cout << ", ";
                cout << *it;
            }
            cout << endl;
        }

        printIndex(node->equal, prefix);
        prefix.pop_back();

        printIndex(node->right, prefix);
    }

    void deleteTST(Node* node) {
        if (!node) return;
        deleteTST(node->left);
        deleteTST(node->equal);
        deleteTST(node->right);
        delete node;
    }

public:
    TST() : root(nullptr) {}

    ~TST() {
        deleteTST(root);
    }

    void insert(const string& word, int line) {
        string sanitizedWord = formatword(word);
        if (!sanitizedWord.empty()) {
            root = insert(root, sanitizedWord.c_str(), line);
        }
    }

    void printIndex() {
        printIndex(root, "");
    }
};

int main() {
    TST tst;
    string line;
    int lineNumber = 1;

    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            tst.insert(word, lineNumber);
        }
        ++lineNumber;
    }

    tst.printIndex();

    return 0;
}
