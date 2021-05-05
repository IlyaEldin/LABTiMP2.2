#include "CesarDop.h"

Cs::Cs(int k)
{
    this->k=k;
}
wstring Cs::Coder(Cs w, wstring& s)
{
    wstring code;
    s=getValidOpenText(s);
    w.k=getValidKey(w.k,s);
    int height;
    if (s.size()%w.k!=0) {
        height=s.size()/w.k+1;
    } else {
        height=s.size()/w.k;
    }
    wchar_t a[height][w.k];
    int k=0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<w.k; j++) {
            if (k<s.size()) {
                a[i][j]=s[k];
                k++;
            } else a[i][j]=' ';
        }
    }
    for (int i=0; i<w.k; i++) {
        for (int j=0; j<height; j++) {
            code+=a[j][i];
        }
    }
    return code;
}
wstring Cs::Decoder(int w, wstring& s)
{
    s=getValidOpenText(s);
    w=getValidKey(w,s);
    int height;
    if (s.size()%w!=0) {
        height=s.size()/w+1;
    } else {
        height=s.size()/w;
    }
    wchar_t a[height][w];
    int k=0;
    for (int i=0; i<w; i++) {
        for (int j=0; j<height; j++) {
            a[j][i]=s[k];
            k++;
        }
    }
    wstring decode;
    for (int i=0; i<height; i++) {
        for (int j=0; j<w; j++) {
            decode+=a[i][j];
        }
    }
    decode=getValidCipherText(decode);
    return decode;
}
//ключ не превышающее
//половины длины текста,
inline int Cs::getValidKey(const int k, const std::wstring & s)
{
    if (k<=0)        throw cipher_error("Ключ не допустим. Введите число больше 0");
    else if (k>(s.size()/2)) throw cipher_error("Ключ превышет половину длины текста и не может быть использован. Выбирите ключ меньшего размера");
    else
        return k;
}
inline std::wstring Cs::getValidOpenText(const std::wstring & s)
{
    int i=0;
    std::wstring tmp;
    for (auto c:s) {
        if (isalpha(c)) {
            if (islower(c))                {
                tmp.push_back(toupper(c));
                i++;
                if (i==1) wcout<<L"Часть входного текста была перенесена в верхний регистр: "<<endl;
            } else                tmp.push_back(c);
        }
    }
    if (tmp.empty())        throw cipher_error("Входной текст отстутвует");
    return tmp;
}

inline std::wstring Cs::getValidCipherText(const std::wstring & s)
{
    int i=0;
    std::wstring tmp;
    for (auto c:s) {
        if (isalpha(c)) {
            if (islower(c))                {
                tmp.push_back(toupper(c));
                i++;
                if (i==1) throw cipher_error("Неправильный тип выходного текста");
            } else                tmp.push_back(c);
        }
    }
    if (tmp.empty())        throw cipher_error("Выходной текст отстутвует");
    return tmp;
}
