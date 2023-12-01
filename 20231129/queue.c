#include <stdio.h>

/*
    リングバッファを、”配列の添字を扱う変数” への計算時に
    「配列のサイズでの剰余算」を行うようにすることで実現する
    「% val_size」
*/

// 配列
char val[5] = { 0 };

// 配列のサイズ
int val_size = sizeof(val) / sizeof(val[0]) + 1; // +1 がないとキューに保存できるデータが一つ少なくなる

// 配列の先頭
int head = 0;

// 配列の最高尾
int tail = -1;

// データの追加
void Enqueue(char str)
{
    // キューが満杯の時はなにもしない
    // + 2 => tailとheadの間が一つしかないときを判定
    if ((tail + 2) % val_size == head)
    {
        printf("キューが満杯です。エンキュ―できません\n");
        return;
    }

    // データを配列の最後尾の一つ後ろに代入
    val[(tail + 1) % val_size] = str;

    // データを最後尾の一つ後ろにずらす
    tail = ++tail % val_size;
}


// データの取り出し
char Dequeue()
{
    char ch = 0;

    // キューが空なら何もしない
    // tailとheadが隣り合うとき
    if ((tail + 1) % val_size == head)
    {
        printf("キューが空です。デキューできません\n");
        return -1;
    }

    // 配列の先頭からデータ取得
    ch = val[head];

    // 配列の先頭を一つ後ろにずらす
    head = ++head % val_size;

    return ch;
}


// 配列表示関数
void ForPrintVal()
{
    int num;
    // キューの中のデータの個数を計算
    // tailがheadよりも前にあるとき
    if (tail < head)
    {
        // + val_size => 配列一周分足す
        num = tail + val_size - head + 1;
    }
    else
    {
        num = tail - head + 1;
    }

    // 表示ループ
    // 左側がキューの出口側を表す
    for (int i = 0; i < num; i++)
    {
        printf("%c", val[(head + i) % val_size]);
    }

    printf("\n");
}


int main()
{
    // データ追加 ==================================
    Enqueue('A');   // 1
    ForPrintVal();
    Enqueue('B');   // 2
    ForPrintVal();
    Enqueue('C');   // 3
    ForPrintVal();
    Enqueue('D');   // 4
    ForPrintVal();
    Enqueue('E');   // 5
    ForPrintVal();
    Enqueue('F');   // エラーデバッグ用

    printf("\n");

    char dequeueStr = 0;
    // データ取り出し ==============================
    dequeueStr = Dequeue(); // 1
    printf("Dequeue => %c\n", dequeueStr);
    ForPrintVal();
    dequeueStr = Dequeue(); // 2
    printf("Dequeue => %c\n", dequeueStr);
    ForPrintVal();
    dequeueStr = Dequeue(); // 3
    printf("Dequeue => %c\n", dequeueStr);
    ForPrintVal();
    dequeueStr = Dequeue(); // 4
    printf("Dequeue => %c\n", dequeueStr);
    ForPrintVal();
    dequeueStr = Dequeue(); // 5
    printf("Dequeue => %c\n", dequeueStr);
    dequeueStr = Dequeue(); // エラーデバッグ用

}