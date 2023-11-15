#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ソート関数宣言
void SortArray(int array[], int array_size)
{
    int valueA = 0;
    int valueB = 0;
    // ループ1
    for(int i = 0; i < array_size; i++)
    {
        // ループ2
        for(int j = array_size - 1; j >= i + 1; j--)
        {
            valueA = array[i];
            valueB = array[j];
            if(valueA > valueB)
            {
                // 入れ替え処理
                array[i] = valueB;
                array[j] = valueA;
            }
        }
    }
}

int main()
{
    // 配列宣言
    int data[100] = {0};
    // 配列のサイズ取得
    int data_size = sizeof(data) / sizeof(data[0]);
    // 現在時刻の情報で乱数を初期化
    srand((unsigned int)time(NULL));
    // 乱数取得ループ
    for(int i = 0; i < data_size; i++)
    {
        data[i] = rand() % 100 + 1;
    }

    // ソート関数呼び出し
    SortArray(data, data_size);

    int target = 50;
    int result = -1;
    int left = 1;
    int right = data_size - 1;
    int mid = 0;

    // ループ開始
    while(left < right)
    {
        // データの真ん中を求める
        mid = (left + right) / 2;
        // 発見時
        if(data[mid] == target)
        {
            result = mid;
            break;
        }
        else if(data[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            // -1しないと無限ループ
            right = mid - 1;
        }
    }

    // result Nullチェック
    if(result >= 0)
    {
        printf("targetのインデックスは%dです", result);
    }
    else
    {
        printf("targetは見つかりませんでした");
    }

    return 0;

}