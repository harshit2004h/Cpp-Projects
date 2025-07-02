# Huffman Coding System

A comprehensive C++ implementation of Huffman coding algorithm with an interactive terminal-based user interface.

## Features

- **Text Encoding**: Compress text using Huffman coding algorithm
- **Text Decoding**: Decompress Huffman-encoded text
- **File Support**: Read from and write to text files
- **Encoding Table**: Display the Huffman encoding table
- **Compression Statistics**: Show compression ratio and space saved
- **Beautiful UI**: Clean and intuitive terminal interface

## How to Build and Run

### Prerequisites
- C++ compiler (g++, MSVC, etc.)
- Windows OS (for console-specific features)

### Build Instructions

1. **Using g++ (recommended):**
   ```bash
   g++ -o huffman main.cpp huffman.cpp ui.cpp
   ```

2. **Using Visual Studio:**
   - Create a new C++ console project
   - Add all `.cpp` and `.h` files to the project
   - Build and run

### Run the Program
```bash
./huffman.exe
```

## Usage

### Main Menu Options

1. **Encode Text**
   - Enter text manually or read from a file
   - Displays compression statistics
   - Saves encoded result to file (if input was from file)

2. **Decode Text**
   - Enter encoded binary text manually or read from file
   - Displays decoded text
   - Saves decoded result to file (if input was from file)

3. **Show Encoding Table**
   - Displays the Huffman encoding table for the last encoded text
   - Shows character, ASCII value, and corresponding Huffman code

4. **Show Last Result**
   - Displays the last encoding/decoding operation results
   - Shows compression statistics

5. **Exit**
   - Safely exit the program

### File Operations

- **Encoding from file**: Saves as `filename_encoded.ext`
- **Decoding from file**: Saves as `filename_decoded.ext`
- Supports any text file format

## Algorithm Details

### Huffman Coding Process

1. **Frequency Analysis**: Count character frequencies in input text
2. **Tree Construction**: Build Huffman tree using priority queue
3. **Code Generation**: Generate variable-length codes for each character
4. **Encoding**: Replace characters with their Huffman codes
5. **Decoding**: Traverse the tree using encoded bits to retrieve original text

### Key Features

- **Optimal Compression**: Minimizes average code length
- **Lossless**: Perfect reconstruction of original text
- **Variable Length Codes**: Frequent characters get shorter codes
- **Memory Efficient**: Tree-based storage of encoding table

## Example Usage

### Encoding Example
```
Input: "hello world"
Frequency: h(1), e(1), l(3), o(2), space(1), w(1), r(1), d(1)
Encoded: 110010100111100001101001011110011
Compression: ~27% space saved
```

### File Processing
```
Input file: "sample.txt"
Output files: 
  - "sample_encoded.txt" (encoded binary)
  - "sample_decoded.txt" (decoded text)
```

## Technical Specifications

- **Language**: C++
- **Data Structures**: Binary trees, priority queues, hash maps
- **Memory Management**: Proper cleanup of dynamically allocated nodes
- **Error Handling**: File I/O errors, empty input validation
- **Platform**: Windows (uses `conio.h` and `windows.h`)

## Code Structure

- `huffman.h` - Header file with class declarations
- `huffman.cpp` - Core Huffman algorithm implementation
- `ui.cpp` - User interface and menu system
- `main.cpp` - Program entry point

## Contributing

Feel free to enhance the program by:
- Adding support for binary file compression
- Implementing other compression algorithms
- Improving the user interface
- Adding cross-platform compatibility

## License

This project is open source and available under the MIT License.
