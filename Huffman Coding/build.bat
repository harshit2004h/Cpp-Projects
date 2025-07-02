@echo off
echo Building Huffman Coding System...
echo.

g++ -std=c++11 -o huffman.exe main.cpp huffman.cpp ui.cpp

if %ERRORLEVEL% EQU 0 (
    echo ✅ Build successful!
    echo.
    echo To run the program, type: huffman.exe
    echo.
) else (
    echo ❌ Build failed!
    echo Make sure you have g++ compiler installed and in your PATH.
    echo.
)

pause
