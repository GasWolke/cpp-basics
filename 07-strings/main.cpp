#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("text.txt");
    if (!fin) {
        cout << "File \"text.txt\" not found.";
        return 1;
    }

    string word;
    cout << "Write a word: ";
    cin >> word;
    cout << endl;

    string line;
    while (getline(fin, line)) {
        string sentence = "";
        for (size_t i = 0; i < line.length(); i++) {
            if (sentence != "" || line[i] != ' ')
                sentence += line[i];

            if (line[i] == '.' || line[i] == '?' || line[i] == '!') {
                if (sentence.find(word) != string::npos)
                    cout << sentence << endl;
                sentence = "";
            }
        }
    }

    fin.close();
    return 0;
}