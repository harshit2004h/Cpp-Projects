#include "huffman.h"
#include <sstream>
#include <algorithm>

// HuffmanCoder Implementation
HuffmanCoder::HuffmanCoder() : root(nullptr) {}

HuffmanCoder::~HuffmanCoder() {
    deleteTree(root);
}

void HuffmanCoder::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void HuffmanCoder::buildHuffmanTree(const std::string& text) {
    if (text.empty()) return;
    
    // Clear previous data
    codes.clear();
    reverseCodes.clear();
    deleteTree(root);
    
    // Count frequencies
    std::unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    
    // Special case: single character
    if (freq.size() == 1) {
        char ch = freq.begin()->first;
        codes[ch] = "0";
        reverseCodes["0"] = ch;
        root = new Node(ch, freq[ch]);
        return;
    }
    
    // Build priority queue
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    
    // Build Huffman tree
    while (pq.size() > 1) {
        Node* right = pq.top(); pq.pop();
        Node* left = pq.top(); pq.pop();
        
        Node* merged = new Node(left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    
    root = pq.top();
    
    // Generate codes
    buildCodes(root, "");
}

void HuffmanCoder::buildCodes(Node* node, std::string code) {
    if (!node) return;
    
    if (!node->left && !node->right) {
        // Leaf node
        if (code.empty()) code = "0"; // Single character case
        codes[node->ch] = code;
        reverseCodes[code] = node->ch;
        return;
    }
    
    buildCodes(node->left, code + "0");
    buildCodes(node->right, code + "1");
}

std::string HuffmanCoder::encode(const std::string& text) {
    lastInputText = text;
    buildHuffmanTree(text);
    
    std::string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }
    
    lastEncodedText = encoded;
    return encoded;
}

std::string HuffmanCoder::decode(const std::string& encodedText) {
    if (!root || encodedText.empty()) return "";
    
    std::string decoded = "";
    Node* current = root;
    
    // Special case: single character tree
    if (!root->left && !root->right) {
        for (char bit : encodedText) {
            if (bit == '0' || bit == '1') {
                decoded += root->ch;
            }
        }
        lastDecodedText = decoded;
        return decoded;
    }
    
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        } else {
            continue; // Skip invalid characters
        }
        
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    
    lastDecodedText = decoded;
    return decoded;
}

void HuffmanCoder::displayEncodingTable() {
    if (codes.empty()) {
        std::cout << "\n❌ No encoding table available. Please encode some text first.\n";
        return;
    }
    
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "           HUFFMAN ENCODING TABLE\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << std::left << std::setw(15) << "Character" << std::setw(15) << "ASCII" << "Huffman Code\n";
    std::cout << std::string(50, '-') << "\n";
    
    // Sort characters for better display
    std::vector<std::pair<char, std::string>> sortedCodes(codes.begin(), codes.end());
    std::sort(sortedCodes.begin(), sortedCodes.end());
    
    for (const auto& pair : sortedCodes) {
        char ch = pair.first;
        std::string code = pair.second;
        
        std::string charDisplay;
        if (ch == ' ') charDisplay = "[SPACE]";
        else if (ch == '\n') charDisplay = "[NEWLINE]";
        else if (ch == '\t') charDisplay = "[TAB]";
        else charDisplay = ch;
        
        std::cout << std::left << std::setw(15) << charDisplay 
                  << std::setw(15) << static_cast<int>(ch) 
                  << code << "\n";
    }
    std::cout << std::string(50, '=') << "\n";
}

void HuffmanCoder::displayLastResult() {
    if (lastEncodedText.empty() && lastDecodedText.empty()) {
        std::cout << "\n❌ No previous results available.\n";
        return;
    }
    
    std::cout << "\n" << std::string(60, '=') << "\n";
    std::cout << "                LAST OPERATION RESULTS\n";
    std::cout << std::string(60, '=') << "\n";
    
    if (!lastInputText.empty()) {
        std::cout << "📝 Original Text:\n";
        std::cout << "\"" << lastInputText << "\"\n\n";
    }
    
    if (!lastEncodedText.empty()) {
        std::cout << "🔒 Encoded (Binary):\n";
        std::cout << lastEncodedText << "\n\n";
        
        // Show compression ratio
        int originalBits = lastInputText.length() * 8;
        int compressedBits = lastEncodedText.length();
        double ratio = (double)(originalBits - compressedBits) / originalBits * 100;
        
        std::cout << "📊 Compression Stats:\n";
        std::cout << "   Original size: " << originalBits << " bits (" << lastInputText.length() << " bytes)\n";
        std::cout << "   Compressed size: " << compressedBits << " bits\n";
        std::cout << "   Compression ratio: " << std::fixed << std::setprecision(2) << ratio << "%\n\n";
    }
    
    if (!lastDecodedText.empty()) {
        std::cout << "🔓 Decoded Text:\n";
        std::cout << "\"" << lastDecodedText << "\"\n\n";
    }
    
    std::cout << std::string(60, '=') << "\n";
}

bool HuffmanCoder::saveToFile(const std::string& content, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

std::string HuffmanCoder::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

void HuffmanCoder::clearLastResults() {
    lastEncodedText.clear();
    lastDecodedText.clear();
    lastInputText.clear();
}
