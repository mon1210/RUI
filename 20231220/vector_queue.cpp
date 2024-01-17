#include <iostream>
#include <vector>

/*
    vectorでは、動的なメモリ管理を行っているため、要素の追加や削除が発生するたびにメモリの再確保が行われる。
    このため、静的なリングバッファと比べてオーバーヘッド(余分な作業)が発生し、パフォーマンスが低下する可能性がある。
    柔軟性や簡便性が求められる場面では使用されることもあり、動的なサイズの変更が必要であったり、
    メモリ使用量に余裕がある場合は、vectorを使用することで実装が簡略化されることがある。
*/
/*
    可変長配列「vector」を使用したqueueの作成
*/

using namespace std;

// 配列
vector<char> queue_;


// データの追加
void Enqueue(char str)
{
    // データを配列の最後尾に要素を構築し、代入
    queue_.emplace_back(str);
}


// データの取り出し
char Dequeue()
{
    char ch = 0;

    // 配列の先頭からデータ取得
    ch = queue_.front();
    queue_.erase(queue_.begin());   // 先頭の要素削除

    return ch;
}


// 配列表示関数
void ForPrintVal()
{
    cout << "queue = ";

    // 表示ループ
    // 左側がキューの出口側を表す
    for (int i = 0; i < queue_.size(); i++)
    {
        cout << queue_[i];
    }

    cout << endl;
}


int main()
{
    // データ追加 ==================================
    cout << "Enqueue => A" << endl;
    Enqueue('A');   // 1
    ForPrintVal();
    cout << "Enqueue => B" << endl;
    Enqueue('B');   // 2
    ForPrintVal();
    cout << "Enqueue => C" << endl;
    Enqueue('C');   // 3
    ForPrintVal();
    cout << "Enqueue => D" << endl;
    Enqueue('D');   // 4
    ForPrintVal();
    cout << "Enqueue => E" << endl;
    Enqueue('E');   // 5
    ForPrintVal();

    cout << endl;

    char dequeueStr = 0;
    // データ取り出し ==============================
    dequeueStr = Dequeue(); // 1
    cout << "Dequeue => " << dequeueStr << endl;
    ForPrintVal();
    dequeueStr = Dequeue(); // 2
    cout << "Dequeue => " << dequeueStr << endl;
    ForPrintVal();
    dequeueStr = Dequeue(); // 3
    cout << "Dequeue => " << dequeueStr << endl;
    ForPrintVal();
    dequeueStr = Dequeue(); // 4
    cout << "Dequeue => " << dequeueStr << endl;
    ForPrintVal();
    dequeueStr = Dequeue(); // 5
    cout << "Dequeue => " << dequeueStr << endl;

}
