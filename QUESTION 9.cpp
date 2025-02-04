#include <bits/stdc++.h>
using namespace std;

class DirectAddressTable {
private:
    vector<int> table;
    vector<bool> exists;

public:
    DirectAddressTable(int n) {
        table.resize(n, -1);
        exists.resize(n, false);
    }

    void insert(int key, int value) {
        table[key] = value;
        exists[key] = true;
    }

    void remove(int key) {
        exists[key] = false;
    }

    void search(int key) {
        if (exists[key])
            cout << table[key] << endl;
        else
            cout << "NOT FOUND" << endl;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DirectAddressTable dat(n);

    while (q--) {
        string command;
        cin >> command;

        if (command == "INSERT") {
            int key, value;
            cin >> key >> value;
            dat.insert(key, value);
        } else if (command == "DELETE") {
            int key;
            cin >> key;
            dat.remove(key);
        } else if (command == "SEARCH") {
            int key;
            cin >> key;
            dat.search(key);
        }
    }

    return 0;
}
