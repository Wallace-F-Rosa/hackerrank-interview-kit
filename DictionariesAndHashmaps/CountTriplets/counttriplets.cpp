#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
  long n = arr.size();

  unordered_map<long, long> left, right;
  long triplets = 0;
  
  //intead off loking for i,j and k so that arr[j] == arr[i]*r
  //and arr[k] == arr[j]*r
  //we look for j so that arr[i] == arr[j]/k and arr[k] == arr[j]*r
  //so for every position in the array we will look:
  //how many elements arr[j]*r exists with an index greater than j
  // - we will store the frequency of the values with index greater or equal to j in unordered_map right
  //how many elements arr[j]/k exists with an index less than j
  // - we will store the frequency off this values with index less than j in unordered_map left
  
  //all elements start on the right side
  //because if we iterate from left to right in the array arr
  //the first element doesn't have any counterpart with an index less then it's own index.
  for(int i = 0; i < n; i++)
    right[arr[i]]++;
  
  //iterating in the array from left to right
  for(int i = 0; i < n; i++){
    //decrease the frequency off arr[i] in right
    //because we will use right to know how many elements arr[j]*r with greater index than i there are in arr.
    right[arr[i]]--;

    //the amount of triplets is the combination off elements 
    if(arr[i]%r == 0)
      triplets += right[arr[i]*r]*left[arr[i]/r];
    
    left[arr[i]]++;
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

