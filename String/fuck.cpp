#include <iostream>
#include <vector>
#include <string>

#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')
using namespace std;

// 空格 => %s
char* blockTransfer(char str[]) {
    // 计算新数组空间的长度
    int len = strlen(str);
    int bCnt = 0;
    char *start = str;
    while (*str != '\0') {
        if (*str == ' ') {
            bCnt++;
        }
        str++;
    }
    str = start;
    int newLen = len + 2 * bCnt;
    char *newStr = (char*)malloc(sizeof(char)*newLen+1);
    
    //从后往前填充
    while(len >= 0) {
        if (str[len] == ' ') {
            newStr[newLen--] = '0';
            newStr[newLen--] = '2';
            newStr[newLen--] = '%';
            len--;
        } else {
            newStr[newLen--] = str[len];
            len--;
        }
    }
    return newStr;
}

// reverse recursively
char *reverse(char str[], int len) {
    if (str == '\0' || len == 0) {
        return NULL;
    }
    reverse(str, len-1);
    char tmp = str[len-1];
    str[len-1] = str[len];
    str[len] = tmp;
    
    return str;
}

// reverse word
void reverse_(char str[], int i, int j) {
    if (str == NULL) {
        return;
    }
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return;
}

char* reverseWord(char str[]) {
    // 反转字符串
    int len = strlen(str);
    reverse_(str, 0, len - 1);
    
    // 反转单词
    int start = 0;
    int end = 0;
    int i = 0;
    int flag = 0;
    while (i < len) {
        if (str[i] != ' ' && flag == 0) {
            start = i;
            flag = 1;
        }
        if (str[i] == ' ') {
            end = i - 1;
            flag = 0;
        }
        if (end > start) {
            reverse_(str, start, end);
            start = 0;
            end = 0;
        }
        i++;
    }

    return str;
}

// 字符串模拟加法
string addStrings(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int i, j;
    string res;
    string num = "0123456789";
    int sum, flag = 0;
    for (i=len1-1, j=len2-1; i >= 0 && j >= 0; i--, j--) {
        sum = (num1[i]-'0') + (num2[j]-'0') + flag;
        flag = sum / 10;
        sum = sum % 10;
        res += num[sum];
    }
    // 剩余的
    for (; i >=0; i--) {
        sum = (num1[i] - '0') + flag;
        flag = sum / 10;
        sum = sum % 10;
        res += num[sum];
    }
     for (; j >=0; j--) {
        sum = (num2[j] - '0') + flag;
        flag = sum / 10;
        sum = sum % 10;
        res += num[sum];
    }
    if (flag == 1) {
        res += "1";
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return res;
}





int main() {
    //char str[] = "I am a big boy ";
    // cout << blockTransfer(str) << endl;
    //char str[] = "abcd";
    //cout << reverse(str, strlen(str)-1) << endl;
    //char str[] = "I fuck the world";
    //cout << reverseWord(str) << endl;
    string str1 = "8888888";
    string str2 = "7777777";
    addStrings(str1,str2);
    
        
    
    
    return 0;
}


