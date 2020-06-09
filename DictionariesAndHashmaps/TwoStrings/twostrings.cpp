#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    unordered_map<char, char> dict;
    for(int i = 0; s1[i] != '\0'; i++)
      dict[s1[i]] = s1[i];

    for(int i = 0; s2[i] != '\0'; i++){
        if(dict[s2[i]]==s2[i])
            return "YES";
    }
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

