#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include "Headers/transform.h"
#include "Headers/AC.h"


using namespace std;


int main()
{
    string ret;
    char hex[100] = {'\0'};
    string buf = "冯岩我儿子";
    ret = string2hex(buf);
    int h[5] = {0};
    for (int i = 0, j = 0; i <= 10-1; j ++) {
        cout << (h[j] = hexchar2int(hex[i ++], hex[i ++])) << endl;
    }
    if (!(h[2]^h[2])) {
        cout << "the same!" << endl;
    }
    else {
        cout << "different!" << endl;
    }
    cout << hex << endl;
    cout << ret << endl;

    char s[65536] = {"51af5ca96211513f5b506162636465666773636164617363616461636164616164616461616211662f51af5ca972364eb26211662f673159296668\0"};
    int successnum[4] = {0};
    string ss = s;
    char originpattern[4][10] = {"scada", "冯岩", "朱天晨", "fg"};
    char transformedpattern[4][10] = {{'\0'}};
    transformpattern(originpattern, transformedpattern, 4);
    startmatch(s, ss.size(), successnum);




    return 0;
}
