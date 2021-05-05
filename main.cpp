#include "CesarDop.h"
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <locale>
using namespace std;
void check(const wstring& Text, const int & key)
{
    wstring s=Text;
    try {
        Cs skey(key);
        wcout<<skey.Coder(key, s)<<endl;
        wstring g=skey.Coder(key, s);
        wcout<<skey.Decoder(key,g)<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"HElloWoelD",5);
    check(L"HElloWoelD",7);
    check(L"HEHHJKHWD",4);
    return 0;
}
