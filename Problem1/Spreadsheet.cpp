#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    int n = 0, i_row = 0, i_col = 0;
    regex reg("R(\\d+)C(\\d+)");
    regex reg1("([A-Z]+)(\\d+)");
    smatch m;
    string strLine;
    cin >> n;
    int nCount = 0;
    while (nCount < n) {
        cin >> strLine;
        string strResult;
        i_row = i_col= 0;
        if ( regex_match(strLine, m, reg) ) {
            i_row = stoi(m.str(1));
            i_col = stoi(m.str(2));
            int i_col_tmp = i_col;
            while (i_col_tmp) {
                string strTmp;
                if ( i_col_tmp % 26 == 0 ) {
                    strTmp = string(1, 'Z');
                    i_col_tmp -= 26;
                }
                else {
                    strTmp = string(1, 'A' + i_col_tmp % 26 - 1);
                }
                strResult = strTmp + strResult;
                i_col_tmp /= 26;
            }
            strResult += to_string(i_row);
        }
        else if ( regex_match(strLine, m, reg1) ) {
            string str_col = m.str(1);
            i_row = stoi(m.str(2));
            for ( auto ch : str_col ) {
                i_col *= 26;
                i_col += (ch - 'A' + 1);
            }
            strResult = "R" + to_string(i_row) + "C";
            strResult += to_string(i_col);
        }
        cout << strResult << '\n';
        ++nCount;
    }
}