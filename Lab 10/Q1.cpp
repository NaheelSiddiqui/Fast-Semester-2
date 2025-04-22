#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class EncryptDecrypt {
private:
    string inputText; // Original text entered by the user
    string encryptedText; // Encrypted text
    string decryptedText; // Decrypted text

public:
    // Constructor to initialize inputText
    EncryptDecrypt(const string& text) : inputText(text) {}

    // Method to encrypt the input text
    void encrypt() {
        encryptedText = "";
        for (int i = 0; i < inputText.length(); ++i) {
            char encryptedChar = inputText[i] + (i + 1); // Add index position to ASCII value
            encryptedText += encryptedChar;
        }
        
        // Write encrypted text to file
        ofstream outFile("encrypted.txt");
        if (outFile.is_open()) {
            outFile << encryptedText;
            outFile.close();
            cout << "Encrypted text inserted in file\n";
        } else {
            cerr << "Error opening file for writing.\n";
        }
    }

    // Method to decrypt the text from the file
    void decrypt() {
        // Read the encrypted text from file
        ifstream inFile("encrypted.txt");
        if (inFile.is_open()) {
            getline(inFile, encryptedText); // Read the encrypted text from file
            inFile.close();

            decryptedText = "";
            for (int i = 0; i < encryptedText.length(); ++i) {
                char decryptedChar = encryptedText[i] - (i + 1); // Subtract index position to get the original ASCII value
                decryptedText += decryptedChar;
            }

            cout << "Decrypted text Read then decoded from file\n";
            cout << "Normal Text: " << decryptedText << "\n";
        } else {
            cerr << "Error opening file for reading.\n";
        }
    }

    // Method to print the normal text (input text)
    void printNormalText() {
        cout << "Normal Text: " << inputText << "\n";
    }
};

int main() {
    // Get the string input from the user
    string userInput;
    cout << "Enter String: ";
    getline(cin, userInput);

    // Create an EncryptDecrypt object with the user input
    EncryptDecrypt ed(userInput);

    // Print normal text
    ed.printNormalText();

    // Encrypt and write the encrypted text to the file
    ed.encrypt();

    // Decrypt the text from the file and display it
    ed.decrypt();

    return 0;
}
