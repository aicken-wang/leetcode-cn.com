#include <iostream>
using namespace std;
// c 语言
void ReplaceBlank(char* str, int len) {
    if (str == nullptr || len <=0) 
        return;
    int oldLen = 0;
    int blankLen = 0;
    int index = 0;
    while ( str[index] != '\0') {
        oldLen++;
        if( str[index] == ' ') 
            blankLen++;
        
        index++;
    }
    // 计算新长度
    int newLen = oldLen + blankLen *2;
    // 预分配空间不足
    if( newLen > len ) return;
    // 使用双指针下标指向新旧字符串尾部
    int indexOfOld = oldLen;
    int indexOfNew = newLen;
    while (indexOfOld >= 0 && indexOfNew > indexOfOld) {
        // 将空格 转换为 “%20”
        if (str[indexOfOld] == ' ') {
            str[indexOfNew--] ='0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            str[indexOfNew--] = str[indexOfOld];
        }
        indexOfOld--;
    }

    return;
}
int main(int argc, char** argv) {
    char str[18] = "how are you!";
    ReplaceBlank(str,(int)sizeof(str));
    cout << str << endl;
    return 0;
}