#include <stdio.h>

/*
    配列に対するデータの格納やデータの取得だけでなく、
    データの最後尾の更新も行う必要がある
*/

// 配列
char val[5] = { 0 };

// 配列のサイズ
int val_size = sizeof(val) / sizeof(val[0]);

// 配列の最後尾
int tail = -1;

// データ追加関数
void Push(char str)
{
    // スタックが満杯の時はなにもしない
    if (tail >= val_size - 1)
    {
        printf("スタックが満杯です。Pushできません\n");
        return;
    }

    // データを配列の最後尾の一つ後ろに代入
    val[tail + 1] = str;

    // 最後尾を一つ後ろにずらす
    tail++;
}


// データ取り出し関数
char Pop()
{
    char ch = 0;
    // スタックが空の時はなにもしない
    if (tail == -1)
    {
        printf("スタックが空です。Popできません\n");
        return -1;
    }

    // 最後尾からデータ取り出し
    ch = val[tail];

    // 最後尾を一つ前にずらす
    tail--;

    return ch;
}


// 配列表示ループ関数
void ForPrintVal()
{
    // 左側がスタックの上を表す
    for (int i = 0; i <= tail; i++)
    {
        printf("%c", val[tail - i]);
    }
    printf("\n");
}


int main()
{
    // データ追加 ===========================
    printf("Push => A\n");
    Push('A');  // 1
    ForPrintVal();
    printf("Push => B\n");
    Push('B');  // 2
    ForPrintVal();
    printf("Push => C\n");
    Push('C');  // 3
    ForPrintVal();
    printf("Push => D\n");
    Push('D');  // 4
    ForPrintVal();
    printf("Push => E\n");
    Push('E');  // 5
    ForPrintVal();
    printf("Push => F\n");
    Push('F');  // エラーデバッグ用

    printf("\n");

    char popStr;
    // データ取り出し =======================
    popStr = Pop();  // 1
    printf("Pop => %c\n", popStr);
    ForPrintVal();
    popStr = Pop();  // 2
    printf("Pop => %c\n", popStr);
    ForPrintVal();
    popStr = Pop();  // 3
    printf("Pop => %c\n", popStr);
    ForPrintVal();
    popStr = Pop();  // 4
    printf("Pop => %c\n", popStr);
    ForPrintVal();
    popStr = Pop();  // 5
    printf("Pop => %c\n", popStr);
    ForPrintVal();
    popStr = Pop();  // エラーデバッグ用

    return 0;

}