#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int LCS(vector<int> a,vector<int> b, int **print) {
            int lenA = a.size(); 
            int lenB = b.size();
            int i,j;
            vector<vector <int> > c(lenA+1, vector<int>(lenB+1, 0));
            for(i=0; i <= lenA; i++)  {
                for(j=0; j <= lenB; j++) {
                    if( i == 0 || j == 0) {
                        c[i][j] = 0;
                    }else if(a[i-1] == b[j-1]) {
                        c[i][j] = c[i-1][j-1] + 1;
                        print[i][j] = 0;
                    }else {
                        c[i][j] = max(c[i][j-1], c[i-1][j]);
                        if (c[i][j-1] < c[i-1][j]) {
                            c[i][j] = c[i-1][j];
                            print[i][j] = 1;
                        } else {
                            c[i][j] = c[i][j-1];
                            print[i][j] = -1;
                        }
                    }
                }
            }
            
            // dp数组
            for(int k = 0; k <= lenA; k++) {
                for(int l = 0; l <= lenB; l++) {
                    cout << c[k][l] << " " ;
                }
                cout << endl;
            }
            // print数组
            for(int k = 0; k <= lenA; k++) {
                for(int l = 0; l <= lenB; l++) {
                    cout << print[k][l] << " " ;
                }
                cout << endl;
            }
            return c[lenA][lenB];
        }   
};

void printLCS(int **b , vector<int>num, int i, int j) {
    if (i ==0 || j==0) 
        return;
    if (b[i][j] == 0) {
        printLCS(b,num,i-1,j-1);
        cout << num[i-1] << "  => ";
    }else if(b[i][j] == 1){
        printLCS(b,num, i - 1, j);
    } else {
        printLCS(b,num, i, j - 1);
    }
}

int main() {
    Solution *cls = new(Solution);
    int a[] = {1,3,4,2,9,7};
    int b[] = {1,8,4,9,7,2};
    vector<int> A(a,a+6);
    vector<int> B(b,b+6);
    int **print = new int*[7] ;
    for(int i = 0; i < 7 ; i++) {
        print[i] = new int[7];
    }
    
    cout << cls->LCS(A,B,print) << endl;
    printLCS(print, A, 6, 6);
    return 0;
}
