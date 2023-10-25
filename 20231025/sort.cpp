#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{  
    // 宣言・初期化
    int val[10] = {1,9,5,7,3,2,8,6,10,4};
    int sortval[10] = {0};
        
    // ソート前出力
    for(int i = 0; i < 10; i++)
    {
        cout << val[i];
        cout << ",";
    }
    cout << "\n";

    // ソート
    for(int i = 0; i < 10; i++)
     {
        for(int j = i; j >= 0; j--)
        {
            if(sortval[j] == 0)
            {
                sortval[j] = val[i];
            }
            // 二週目
            else if(sortval[j] > val[i])
            {
                // 前のインデックスから要素をコピー
                sortval[j+1] = sortval[j];
                // 空になった前のインデックスに次の要素を代入
                sortval[j] = val[i];
            }
        }
     }


    cout << "\n";

    // ソート後出力
    cout << "sortval = ";
    for(int i = 0; i < 10; i++)
    {
        cout << sortval[i];
        cout << ",";
    }
    cout << "\n";

}