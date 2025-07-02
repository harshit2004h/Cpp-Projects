# 🗜️ Huffman Coding System - User Guide

## Quick Start

1. **Run the program**: Double-click `huffman.exe` or run it from command line
2. **Choose an option** from the main menu (1-5)
3. **Follow the prompts** for each operation

## 📋 Menu Options Detailed Guide

### 1️⃣ Encode Text

**Purpose**: Compress text using Huffman coding algorithm

**Options**:
- **Manual Input**: Type text directly
- **File Input**: Select a text file to encode

**What happens**:
- Analyzes character frequencies
- Builds Huffman tree
- Generates optimal codes
- Shows compression statistics
- Saves encoded file (if input was from file)

**Example**:
```
Input: "hello world"
Output: 110010100111100001101001011110011
Compression: ~27% space saved
```

### 2️⃣ Decode Text

**Purpose**: Decompress Huffman-encoded text back to original

**Requirements**: 
- Must have encoded text first (to build the tree)
- Binary string containing only 0s and 1s

**Options**:
- **Manual Input**: Paste encoded binary text
- **File Input**: Select encoded file

**What happens**:
- Uses existing Huffman tree
- Traverses tree based on binary input
- Reconstructs original text
- Saves decoded file (if input was from file)

### 3️⃣ Show Encoding Table

**Purpose**: Display the Huffman encoding table

**Shows**:
- Each character and its frequency
- ASCII values
- Corresponding Huffman codes
- Sorted alphabetically

**Example Table**:
```
Character    ASCII    Huffman Code
[SPACE]      32       001
a            97       010
e            101      11
h            104      000
...
```

### 4️⃣ Show Last Result

**Purpose**: Review previous encoding/decoding operation

**Displays**:
- Original input text
- Encoded binary string
- Decoded text (if applicable)
- Compression statistics
- File savings information

### 5️⃣ Exit

**Purpose**: Safely close the program

## 📁 File Operations

### File Naming Convention

When processing files, the program automatically creates output files:

- **Encoding**: `original_encoded.txt`
- **Decoding**: `original_decoded.txt`

**Example**:
- Input: `sample.txt`
- Encoded output: `sample_encoded.txt`
- Decoded output: `sample_decoded.txt`

### Supported File Types

- `.txt` files (recommended)
- Any text-based file format
- Files with any extension containing readable text

## 🔧 Technical Features

### Compression Algorithm

1. **Frequency Analysis**: Counts how often each character appears
2. **Tree Building**: Creates binary tree with frequent characters closer to root
3. **Code Generation**: Assigns shorter codes to frequent characters
4. **Encoding**: Replaces characters with their binary codes

### Compression Effectiveness

- **Best for**: Text with repeated characters
- **Average savings**: 20-50% for typical text
- **Worst case**: Minimal savings for very random text
- **Best case**: Up to 70%+ savings for repetitive text

### Special Character Handling

- **Spaces**: Displayed as `[SPACE]` in tables
- **Newlines**: Displayed as `[NEWLINE]`
- **Tabs**: Displayed as `[TAB]`
- **All printable characters**: Supported

## 🚀 Usage Tips

### For Best Compression

1. **Use longer texts**: Better frequency analysis
2. **Repetitive content**: More repeated characters = better compression
3. **Avoid very short texts**: Overhead may exceed savings

### File Processing Tips

1. **Backup original files**: Program creates new files, doesn't overwrite
2. **Use descriptive filenames**: Makes tracking easier
3. **Process larger files**: Better compression ratios

### Troubleshooting

**"No encoding table available"**
- Solution: Encode some text first

**"Decoding failed"**
- Solution: Make sure you've encoded text first to build the tree
- Check that input contains only 0s and 1s

**"Could not read file"**
- Solution: Check file path and permissions
- Ensure file exists and contains readable text

## 📊 Understanding Compression Statistics

### Key Metrics

- **Original size**: Size in bits (characters × 8)
- **Compressed size**: Number of bits in encoded string
- **Compression ratio**: Percentage of space saved
- **Character frequency**: How often each character appears

### Reading the Stats

```
Original size: 88 bits (11 bytes)
Compressed size: 32 bits
Compression ratio: 63.64%
```

This means:
- Original text was 11 characters (88 bits)
- Compressed to 32 bits
- Saved 63.64% of space

## 🎯 Example Workflow

### Complete Encoding/Decoding Process

1. **Start program** → Main menu appears
2. **Select "1" (Encode)** → Choose input method
3. **Enter text or file** → Program analyzes and encodes
4. **View results** → See compression stats
5. **Select "3" (Show Table)** → Review encoding table
6. **Select "2" (Decode)** → Enter encoded text
7. **View decoded result** → Verify original text restored
8. **Select "4" (Last Result)** → Review complete operation

### Sample Text Processing

Try the included `sample.txt` file:
1. Choose "Encode Text" → "Read from file"
2. Enter path: `sample.txt`
3. View compression results
4. Check generated `sample_encoded.txt`
5. Test decoding with the encoded file

## ⚡ Advanced Features

### Batch Processing

While the program processes one file at a time, you can:
1. Process multiple files sequentially
2. Keep the program running between operations
3. Use "Show Last Result" to compare different texts

### Integration Tips

- **Text Analysis**: Use to study character frequencies in documents
- **Compression Study**: Compare compression ratios of different text types
- **Educational**: Learn about information theory and compression algorithms

---

**Enjoy using the Huffman Coding System! 🎉**
