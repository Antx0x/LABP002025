#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

struct Comparator {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second == b.second)
            return a.first > b.first;  
        return a.second > b.second;    
    }
};

int main() {
    ifstream fisier("text.txt");
    if (!fisier) {
        cerr << "Eroare la deschiderea fișierului.\n";
        return 1;
    }

    string text, linie;
    while (getline(fisier, linie)) {
        text += linie + " ";
    }
    fisier.close();

    map<string, int> aparitii;
    string cuvant;

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (isalpha(c)) {
            cuvant += tolower(c);
        }
        else if (!cuvant.empty()) {
            aparitii[cuvant]++;
            cuvant.clear();
        }
    }
    if (!cuvant.empty()) {
        aparitii[cuvant]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int> >, Comparator> pq;

    map<string, int>::iterator it;
    for (it = aparitii.begin(); it != aparitii.end(); ++it) {
        pq.push(pair<string, int>(it->first, it->second));
    }

    while (!pq.empty()) {
        pair<string, int> element = pq.top();
        cout << element.first << " => " << element.second << endl;
        pq.pop();
    }

    return 0;
}
