#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    //solution:
    //for this problem we need to be able to execute the query's 1 and 2
    //and be able to know how many objects with a specific query in all
    //inputs already read.
    //we will use two dictionarys :
    // - freq : stores the frequency of the numbers read
    // - ele_freq : if numbers x is in freq, then ele_freq[freq[x]]++.
    //basicaly ele_freq will store how many numbers have the same frequency

    unordered_map<long long, long long> freq;
    unordered_map<long long, long long> ele_freq;
    vector<int> out;
    int n = queries.size();
    for(int i = 0; i < n; i++){
        if(queries[i][0] == 1){
            //query option == 1
            //update the frequency of the number
            //update wich ele_freq the number needs to be:
            //  as we are increasing the frequency of the number we
            //need to move it to a ele_freq with higher frequency
            if(ele_freq[freq[queries[i][1]]] > 0)
                ele_freq[freq[queries[i][1]]]--;
            freq[queries[i][1]]++;
            ele_freq[freq[queries[i][1]]]++;
        }
        else if(queries[i][0] == 2){
            //query option == 2
            //if we alredy saw this number(it's frequency its not 0)
            //do the reverse of query option 1
            if(freq[queries[i][1]] > 0){
                ele_freq[freq[queries[i][1]]]--;
                freq[queries[i][1]]--;
                if(freq[queries[i][1]]>0)
                    ele_freq[freq[queries[i][1]]]++;
            }
        }
        else{
            //query option 3
            //push_back to output how many numbers there are
            //with frequency z(query[i][1]) == push_back ele_freq[z]
            out.push_back((ele_freq[queries[i][1]] > 0));
        }
    }

    return out;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    //for (int i = 0; i < ans.size(); i++) {
    //    cout << ans[i] << "\n";
    //}
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
