#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

class HuffmanCoding {
public:

    void buildCodes(Node* root, string str, unordered_map<char, string>& hCodes) {
        if (!root) return;

        // Leaf node
        if (!root->left && !root->right) {
            hCodes[root->ch] = str;
        }

        buildCodes(root->left, str + "0", hCodes);
        buildCodes(root->right, str + "1", hCodes);
    }

    void encode(const string& input) {
        // Step 1: Frequency count
        unordered_map<char, int> freq;
        for (char c : input) {
            freq[c]++;
        }

        // Step 2: Min-heap with custom comparator
        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (auto p : freq) {
            pq.push(new Node(p.first, p.second));
        }

        // Step 3: Build the Huffman Tree
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* parent = new Node('$', left->freq + right->freq);
            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        Node* root = pq.top();

        // Step 4: Generate codes
        unordered_map<char, string> hCodes;
        buildCodes(root, "", hCodes);

        // Print Huffman Codes
        cout << "Huffman Codes:\n";
        for (auto p : hCodes) {
            cout << p.first << " : " << p.second << endl;
        }

        // Encode the input string
        cout << "\nEncoded string: ";
        for (char c : input) {
            cout << hCodes[c]<<" ";
        }
        cout << endl;
    }
};

int main() {
    HuffmanCoding hc;
    string text = "hello world";
    hc.encode(text);
    return 0;
}
