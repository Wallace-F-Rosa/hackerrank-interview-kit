#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    bool visitado[n] = { false };
    int pos[n];

    for(int i = 0; i < n; i++){
        pos[arr[i]-1]=i;
    }

    int trocas = 0;
    for(int i = 0; i < n; i++)
        if(!visitado[i]){
            int first = i;
            visitado[i] = true;
            int ciclo = 0;
            int next = arr[i]-1;
            while(arr[first] != arr[next]){
                ciclo++;
                visitado[next] = true;
                next = arr[arr[next]]-1;
            }
            if(ciclo > 0)
              trocas += ciclo - 1;
        }

    return trocas;

}



int main()
{
    int n;
    cin >> n;  
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "OK\n";
    int trocas = minimumSwaps(arr);
    cout << trocas << "\n";
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

