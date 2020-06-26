#include <bits/stdc++.h>

using namespace std;

bool isAnagram(int s1, int s2, int tam, string s){

  vector<int> freq(256,0);

  for(int i = 0; i < tam; i++){
    freq[(unsigned int)(s[s1+i])]++;
    freq[(unsigned int)(s[s2+i])]--;
  }

  for(int i = 0; i < 256; i++)
    if(freq[i] != 0)
      return false;

  return true;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
  unordered_map<char, unsigned int> freq;
  unsigned long long total = 0;
  int n = s.size();
  for(int tam = 1; tam < n; tam++){
    for(int i = 0; i < n - tam; i++){
      for(int j = i+1; j <= n - tam; j++){
        if(isAnagram(i,j,tam,s))
          total++;
      }
    }
  }

  return total; 
}

int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

     //   fout << result << "\n";
    }

   // fout.close();

    return 0;
}

