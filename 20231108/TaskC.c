#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    // 配列宣言
    int data[10] = { 0 };

    // データのサイズ取得
    int date_size = sizeof(data) / sizeof(data[0]);

    // 現在時刻の情報で乱数を初期化
    srand((unsigned int)time(NULL));

    // 乱数取得ループ
    for (int i = 0; i < date_size; i++)
    {
        // 1~10までの乱数取得
        data[i] = rand() % 10 + 1;
    }


    // ループ開始
    for (int i = 0; i < date_size; i++)
    {
        // iを出力
        printf("%d,", data[i]);
    }

    // ループエンド
}