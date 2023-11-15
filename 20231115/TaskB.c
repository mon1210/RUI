#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// @brief 隣り合わせの数字と比べて大きい物を後ろに
/// @return 

int main()
{
    // 配列宣言
    int data[100] = {0};
    // データのサイズ取得
    int data_size = sizeof(data) / sizeof(data[0]);
    // 現在の時刻の情報で乱数を初期化
    srand((unsigned int)time(NULL));

    // 乱数取得ループ
    for(int i = 0; i < data_size; i++)
    {
        data[i] = rand() % 100 + 1;
    }

    int valueA = 0;
    int valueB = 0;
    int max = 0;
    int min = 0;
    // ループ1
    for(int i = 0; i < data_size; i++)
    {
        // ループ2
        for(int j = data_size - 1; j >= i + 1; j--)
        {
            valueA = data[i];
            valueB = data[j];
            if(valueA > valueB)
            {
                // 入れ替え処理
                max = valueA;
                min = valueB;
                   
                data[i] = min;
                data[j] = max;
            }
        }
    }

    // 出力ループ
    for(int i = 0; i < data_size; i++)
    {
        printf("%d\n", data[i]);
    }

    return 0;

}