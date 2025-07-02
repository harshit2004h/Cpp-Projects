#include "huffman.h"
#include <conio.h>
#include <windows.h>

// UI Implementation
void HuffmanUI::printHeader()
{
    system("cls");
    std::cout << "\n";
    std::cout << "██╗  ██╗██╗   ██╗███████╗███████╗███╗   ███╗ █████╗ ███╗   ██╗\n";
    std::cout << "██║  ██║██║   ██║██╔════╝██╔════╝████╗ ████║██╔══██╗████╗  ██║\n";
    std::cout << "███████║██║   ██║█████╗  █████╗  ██╔████╔██║███████║██╔██╗ ██║\n";
    std::cout << "██╔══██║██║   ██║██╔══╝  ██╔══╝  ██║╚██╔╝██║██╔══██║██║╚██╗██║\n";
    std::cout << "██║  ██║╚██████╔╝██║     ██║     ██║ ╚═╝ ██║██║  ██║██║ ╚████║\n";
    std::cout << "╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝\n";
    std::cout << "                    🗜️  CODING SYSTEM 🗜️                     \n";
    std::cout << std::string(65, '=') << "\n";
}

void HuffmanUI::printMenu()
{
    std::cout << "\n📋 MAIN MENU:\n";
    std::cout << std::string(30, '-') << "\n";
    std::cout << "1️⃣  Encode Text\n";
    std::cout << "2️⃣  Decode Text\n";
    std::cout << "3️⃣  Show Encoding Table\n";
    std::cout << "4️⃣  Show Last Result\n";
    std::cout << "5️⃣  Exit\n";
    std::cout << std::string(30, '-') << "\n";
    std::cout << "👉 Enter your choice (1-5): ";
}

void HuffmanUI::printSeparator()
{
    std::cout << "\n"
              << std::string(65, '=') << "\n";
}

std::string HuffmanUI::getFileExtension(const std::string &filename)
{
    size_t pos = filename.find_last_of('.');
    if (pos != std::string::npos)
    {
        return filename.substr(pos);
    }
    return "";
}

std::string HuffmanUI::removeExtension(const std::string &filename)
{
    size_t pos = filename.find_last_of('.');
    if (pos != std::string::npos)
    {
        return filename.substr(0, pos);
    }
    return filename;
}

void HuffmanUI::encodeOption()
{
    printSeparator();
    std::cout << "                    📝 ENCODE TEXT\n";
    printSeparator();

    std::cout << "\nChoose input method:\n";
    std::cout << "1️⃣  Enter text manually\n";
    std::cout << "2️⃣  Read from file\n";
    std::cout << "👉 Enter choice (1 or 2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    std::string inputText;
    std::string outputFilename;

    if (choice == 1)
    {
        std::cout << "\n📝 Enter text to encode: ";
        std::getline(std::cin, inputText);

        if (inputText.empty())
        {
            std::cout << "\n❌ Empty text cannot be encoded!\n";
            std::cout << "\nPress any key to continue...";
            _getch();
            return;
        }
    }
    else if (choice == 2)
    {
        std::cout << "\n📁 Enter file path: ";
        std::string filepath;
        std::getline(std::cin, filepath);

        inputText = coder.readFromFile(filepath);
        if (inputText.empty())
        {
            std::cout << "\n❌ Could not read file or file is empty!\n";
            std::cout << "\nPress any key to continue...";
            _getch();
            return;
        }

        // Prepare output filename
        std::string baseName = removeExtension(filepath);
        std::string extension = getFileExtension(filepath);
        outputFilename = baseName + "_encoded" + extension;

        std::cout << "\n✅ File read successfully! (" << inputText.length() << " characters)\n";
    }
    else
    {
        std::cout << "\n❌ Invalid choice!\n";
        std::cout << "\nPress any key to continue...";
        _getch();
        return;
    }

    // Encode the text
    std::cout << "\n🔄 Encoding in progress...\n";
    std::string encoded = coder.encode(inputText);

    // Display results
    std::cout << "\n✅ ENCODING COMPLETED!\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << "📝 Original text: \"" << inputText.substr(0, 50);
    if (inputText.length() > 50)
        std::cout << "...";
    std::cout << "\"\n";
    std::cout << "🔒 Encoded: " << encoded.substr(0, 60);
    if (encoded.length() > 60)
        std::cout << "...";
    std::cout << "\n";

    // Show compression stats
    int originalBits = inputText.length() * 8;
    int compressedBits = encoded.length();
    double ratio = (double)(originalBits - compressedBits) / originalBits * 100;

    std::cout << "\n📊 Compression Statistics:\n";
    std::cout << "   Original size: " << originalBits << " bits\n";
    std::cout << "   Compressed size: " << compressedBits << " bits\n";
    std::cout << "   Space saved: " << std::fixed << std::setprecision(2) << ratio << "%\n";

    // Save to file if from file input
    if (choice == 2 && !outputFilename.empty())
    {
        if (coder.saveToFile(encoded, outputFilename))
        {
            std::cout << "\n💾 Encoded text saved to: " << outputFilename << "\n";
        }
        else
        {
            std::cout << "\n❌ Failed to save encoded text to file!\n";
        }
    }

    std::cout << "\nPress any key to continue...";
    _getch();
}

void HuffmanUI::decodeOption()
{
    printSeparator();
    std::cout << "                    🔓 DECODE TEXT\n";
    printSeparator();

    std::cout << "\nChoose input method:\n";
    std::cout << "1️⃣  Enter encoded text manually\n";
    std::cout << "2️⃣  Read from file\n";
    std::cout << "👉 Enter choice (1 or 2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    std::string encodedText;
    std::string outputFilename;

    if (choice == 1)
    {
        std::cout << "\n🔒 Enter encoded text (binary): ";
        std::getline(std::cin, encodedText);

        if (encodedText.empty())
        {
            std::cout << "\n❌ Empty encoded text cannot be decoded!\n";
            std::cout << "\nPress any key to continue...";
            _getch();
            return;
        }
    }
    else if (choice == 2)
    {
        std::cout << "\n📁 Enter file path: ";
        std::string filepath;
        std::getline(std::cin, filepath);

        encodedText = coder.readFromFile(filepath);
        if (encodedText.empty())
        {
            std::cout << "\n❌ Could not read file or file is empty!\n";
            std::cout << "\nPress any key to continue...";
            _getch();
            return;
        }

        // Prepare output filename
        std::string baseName = removeExtension(filepath);
        std::string extension = getFileExtension(filepath);
        outputFilename = baseName + "_decoded" + extension;

        std::cout << "\n✅ File read successfully!\n";
    }
    else
    {
        std::cout << "\n❌ Invalid choice!\n";
        std::cout << "\nPress any key to continue...";
        _getch();
        return;
    }

    // Decode the text
    std::cout << "\n🔄 Decoding in progress...\n";
    std::string decoded = coder.decode(encodedText);

    if (decoded.empty())
    {
        std::cout << "\n❌ Decoding failed! Make sure you have encoded some text first.\n";
        std::cout << "\nPress any key to continue...";
        _getch();
        return;
    }

    // Display results
    std::cout << "\n✅ DECODING COMPLETED!\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << "🔒 Encoded text: " << encodedText.substr(0, 60);
    if (encodedText.length() > 60)
        std::cout << "...";
    std::cout << "\n";
    std::cout << "🔓 Decoded text: \"" << decoded << "\"\n";

    // Save to file if from file input
    if (choice == 2 && !outputFilename.empty())
    {
        if (coder.saveToFile(decoded, outputFilename))
        {
            std::cout << "\n💾 Decoded text saved to: " << outputFilename << "\n";
        }
        else
        {
            std::cout << "\n❌ Failed to save decoded text to file!\n";
        }
    }

    std::cout << "\nPress any key to continue...";
    _getch();
}

void HuffmanUI::showEncodingTable()
{
    printSeparator();
    std::cout << "                 📋 ENCODING TABLE\n";
    printSeparator();

    coder.displayEncodingTable();

    std::cout << "\nPress any key to continue...";
    _getch();
}

void HuffmanUI::showLastResult()
{
    printSeparator();
    std::cout << "                  📊 LAST RESULTS\n";
    printSeparator();

    coder.displayLastResult();

    std::cout << "\nPress any key to continue...";
    _getch();
}

void HuffmanUI::run()
{
    int choice;

    while (true)
    {
        printHeader();
        printMenu();

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            encodeOption();
            break;
        case 2:
            decodeOption();
            break;
        case 3:
            showEncodingTable();
            break;
        case 4:
            showLastResult();
            break;
        case 5:
            printSeparator();
            std::cout << "                   👋 GOODBYE!\n";
            std::cout << "      Thank you for using Huffman Coding System!\n";
            printSeparator();
            std::cout << "\nPress any key to exit...";
            _getch();
            return;
        default:
            printSeparator();
            std::cout << "❌ Invalid choice! Please enter a number between 1-5.\n";
            std::cout << "\nPress any key to continue...";
            _getch();
            break;
        }
    }
}
