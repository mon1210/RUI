#include <iostream>
#include <vector>

/*
    可変長配列「vector」を使用したstackの作成
*/

using namespace std;

// 配列
vector<char> stack_;


// データ追加関数
void Push(char str)
{
    // データを配列の先頭に代入
    stack_.insert(stack_.begin(), str);
}


// データ取り出し関数
char Pop()
{
    char ch = 0;
    // スタックが空の時はなにもしない
    if (stack_.empty())
    {
        cout << "スタックが空です。Popできません" << endl;
        return NULL;
    }
    else
    {
        // 最後尾からデータ取り出し
        ch = stack_.back();
        stack_.pop_back();  // 末尾の要素削除
    }

    return ch;
}


// 配列表示ループ関数
void ForPrintVal()
{
    cout << "stack = ";
    // 左側がスタックの上を表す
    for (int i = 0; i < stack_.size(); i++)
    {
        cout << stack_[i];
    }
    cout << endl;
}


int main()
{
    // データ追加 ===========================
    cout << "Push => A" << endl;
    Push('A');  // 1
    ForPrintVal();
    cout << "Push => B" << endl;
    Push('B');  // 2
    ForPrintVal();
    cout << "Push => C" << endl;
    Push('C');  // 3
    ForPrintVal();
    cout << "Push => D" << endl;
    Push('D');  // 4
    ForPrintVal();
    cout << "Push => E" << endl;
    Push('E');  // 5
    ForPrintVal();

    cout << endl;

    char popStr;
    // データ取り出し =======================
    popStr = Pop();  // 1
    cout << "Pop => " << popStr << endl;
    ForPrintVal();
    popStr = Pop();  // 2
    cout << "Pop => " << popStr << endl;
    ForPrintVal();
    popStr = Pop();  // 3
    cout << "Pop => " << popStr << endl;
    ForPrintVal();
    popStr = Pop();  // 4
    cout << "Pop => " << popStr << endl;
    ForPrintVal();
    popStr = Pop();  // 5
    cout << "Pop => " << popStr << endl;
    ForPrintVal();

    return 0;
}