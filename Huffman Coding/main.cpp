#include "huffman.h"
#include <windows.h>

int main() {
    // Set console to UTF-8 for better character display
    SetConsoleOutputCP(CP_UTF8);
    
    // Create and run the UI
    HuffmanUI ui;
    ui.run();
    
    return 0;
}
