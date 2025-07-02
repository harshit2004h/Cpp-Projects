#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <fstream>
#include <bitset>
#include <vector>
#include <iomanip>

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
    Node(int frequency) : ch('\0'), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq) {
            return a->ch > b->ch; // For consistent ordering
        }
        return a->freq > b->freq;
    }
};

class HuffmanCoder {
private:
    Node* root;
    std::unordered_map<char, std::string> codes;
    std::unordered_map<std::string, char> reverseCodes;
    std::string lastEncodedText;
    std::string lastDecodedText;
    std::string lastInputText;
    
    void buildCodes(Node* node, std::string code);
    void deleteTree(Node* node);
    std::string charToBinary(char c);
    char binaryToChar(const std::string& binary);
    
public:
    HuffmanCoder();
    ~HuffmanCoder();
    
    void buildHuffmanTree(const std::string& text);
    std::string encode(const std::string& text);
    std::string decode(const std::string& encodedText);
    void displayEncodingTable();
    void displayLastResult();
    bool saveToFile(const std::string& content, const std::string& filename);
    std::string readFromFile(const std::string& filename);
    void clearLastResults();
};

// UI Class for better interface
class HuffmanUI {
private:
    HuffmanCoder coder;
    void printHeader();
    void printMenu();
    void printSeparator();
    void encodeOption();
    void decodeOption();
    void showEncodingTable();
    void showLastResult();
    std::string getFileExtension(const std::string& filename);
    std::string removeExtension(const std::string& filename);
    
public:
    void run();
};

#endif
