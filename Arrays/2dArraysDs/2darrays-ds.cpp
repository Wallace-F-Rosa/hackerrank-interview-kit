#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int i = 0, j = 0;
    int max_hourglass_sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
    max_hourglass_sum+= arr[i+1][j+1];
    max_hourglass_sum+= arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
        
    for(int i = 1; i < 5; i++)
        for(int j = 0; j < 5; j++){
            int h_sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            h_sum+= arr[i+1][j+1];
            h_sum+= arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if(h_sum > max_hourglass_sum)
                max_hourglass_sum = h_sum;
        }
    //cout << max_hourglass_sum << "\n";
    return max_hourglass_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
