#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> A, vector<vector<int>> B, int m)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

vector<vector<int>> encrypt(vector<int> plaintext, vector<vector<int>> key, int m)
{
    int n = key.size();
    int len = plaintext.size();
    vector<vector<int>> ciphertext(len / n, vector<int>(n, 0));
    for (int i = 0; i < len; i += n)
    {
        vector<vector<int>> block(1, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            block[0][j] = plaintext[i + j];
        }
        vector<vector<int>> C = matrix_multiply(block, key, m);
        for (int j = 0; j < n; j++)
        {
            ciphertext[i / n][j] = C[0][j];
        }
    }
    return ciphertext;
}

int main()
{
    vector<int> plaintext = {0, 1, 2, 3};       // Plaintext message
    vector<vector<int>> key = {{1, 2}, {3, 4}}; // Key matrix
    int m = 26;                                 // Size of the alphabet (in this case, English alphabet)
    vector<vector<int>> ciphertext = encrypt(plaintext, key, m);
    cout << "Ciphertext: ";
    for (int i = 0; i < ciphertext.size(); i++)
    {
        for (int j = 0; j < ciphertext[i].size(); j++)
        {
            cout << char(ciphertext[i][j] + 'A');
        }
    }
    cout << endl;
    return 0;
}
