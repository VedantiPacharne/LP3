#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// A Tree node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to print the Huffman codes
void printCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // If we reach a leaf node, we store the code for this character
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Main function to build the Huffman tree and generate codes
void huffmanCoding(const string& text) {
    // Count the frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue (min-heap) to store the nodes
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a leaf node for each character and add it to the heap
    for (auto pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() != 1) {
        // Extract the two nodes with the lowest frequency
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with these two nodes as children and
        // frequency equal to the sum of the two nodes' frequencies.
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        // Add the new node to the heap
        minHeap.push(sum);
    }

    // Root of the Huffman Tree
    Node* root = minHeap.top();

    // Traverse the Huffman Tree to store codes in a map
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Display the Huffman codes for each character
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    // Display the encoded string
    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }
    cout << "\nEncoded String:\n" << encodedStr << endl;
}

int main() {
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);
    huffmanCoding(text);
    return 0;
}

