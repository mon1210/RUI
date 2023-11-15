#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 配列シャッフル用関数宣言
void Shuffle(int array[],int array_size)
{
    // 現在時刻の情報で乱数を初期化
    srand((unsigned int)time(NULL));

    // 配列をシャッフル
    for(int i = array_size - 1; i > 0; i--)
    {
        // ランダムなインデックス取得
        int j = rand() % (i + 1);

        // 入れ替え処理
        int temp = array[i];    // 仮変数に今の要素を代入
        array[i] = array[j];    // 今の要素にランダムなインデックスの要素を代入
        array[j] = temp;        // ランダムなインデックスに仮変数の値を代入

    }
}

int main()
{
    // 配列宣言
    int data[] = {0,1,2,3,4,5,6,7,8,9,10};
    // 配列のサイズ取得
    int data_size = sizeof(data) / sizeof(data[0]);

    // 配列シャッフル用関数呼び出し
    Shuffle(data, data_size);
    
    int result = -1;
    int target = 5;
    // ループ開始
    for(int i = 0; i < data_size; i++)
    {
        if(data[i] == target)
        {
            // インデックスを代入
            result = i;

            // targetのインデックスを出力
            printf("targetのindexは%dです。",result);
        }
        
    }

    return 0;

}

