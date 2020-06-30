#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
  long n = arr.size();
  unordered_map<long, long> dict;
  long triplets = 0;
  for(int i = 0; i < n; i++)
    if(dict.count(arr[i]) == 0)
      dict[arr[i]]=i;

  for(int i = 0; i < n-2; i++)
    if(dict[arr[i]*r]){
      for(int j = dict[arr[i]*r]; dict[arr[j]] && (j > i) && (arr[j] == arr[i]*r); j--)
        if(dict[arr[j]*r]){
          for(int k = dict[arr[j]*r]; dict[arr[k]] && (k > j) && (arr[k] == arr[j]*r); k--)
            triplets++;
        }
    }
  
  return triplets;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout;
    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);
    cout << ans << "\n";

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

