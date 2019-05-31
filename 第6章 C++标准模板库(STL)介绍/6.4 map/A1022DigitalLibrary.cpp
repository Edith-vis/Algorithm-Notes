#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<string, set<int> > title, author, key_word, publisher, year;

void query(map<string, set<int> > &temp, string str) {
    if (temp.find(str) != temp.end()) {
        for (auto it = temp[str].begin(); it != temp[str].end(); it++) {
            printf("%07d\n", *it);
        }
    } else {
        printf("Not Found\n");
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    string t_title, t_author, t_key_word, t_publisher, t_year;
    for (int i = 0; i < n; i++) {
        int id;
        scanf("%d\n", &id);

        getline(cin, t_title);
        title[t_title].insert(id);

        getline(cin, t_author);
        author[t_author].insert(id); 

        while (cin >> t_key_word) {
            key_word[t_key_word].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }   

        getline(cin, t_publisher);
        publisher[t_publisher].insert(id); 

        getline(cin, t_year);
        year[t_year].insert(id); 
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int _key;
        string key;
        scanf("%d: ", &_key);
        getline(cin, key);
        cout << _key << ": " << key <<endl;
        if (_key == 1) query(title, key);
        else if (_key == 2) query(author, key);
        else if (_key == 3) query(key_word, key);
        else if (_key == 4) query(publisher, key);
        else if (_key == 5) query(year, key);
    }

    return 0;
}