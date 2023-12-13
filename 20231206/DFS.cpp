#include <iostream>
#include <vector>
#include <stack>
/*
* stack
* push 追加
* pop  削除
* top  取り出し
*/
using namespace std;

const int ROWS = 8;			// 行
const int COLS = 8;			// 列
const int DIRECTIONS = 4;	// 方向　上下左右

//　通路:0,壁:1
int DFSval[ROWS][COLS] = {
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 0, 1, 0}, 
	{0, 1, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 1, 1, 0, 0},
	{0, 1, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 1, 1, 1, 0, 1},
	{0, 1, 0, 0, 0, 1, 0, 1}
};

// 座標を表す構造体
struct Point {
	int row, col;
};

/*
* @brief   深さ優先探索メソッド
* @note    スタックを使用
* @return  true:ゴール(終了) / false:まだゴールしていない(継続)
*/
bool dfs(int startRow_, int startCol_, int goalRow_, int goalCol_)
{
	// 座標の構造体持つスタックを用意
	stack<Point> stack_;

	// 訪れたかどうかを示すvisitedベクトルを作る ------------------------------------------------------
	// vector<bool>(COLS, false) でCOLSサイズの一次元ベクトルを作成して、falseで初期化する
	// ROWSサイズの一次元ベクトルを作成し、↑のベクトルで初期化する
	// vector<要素の型>(サイズ, 初期化値)　を二重で書き、二つの一次元ベクトルから二次元ベクトルを作る
	vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

	// 最終的な経路表示用printベクトルを作る 
	// 各ポイントのひとつ前のポイントの座標を保存
	vector<vector<Point>> print(ROWS, vector<Point>(COLS, { -1, -1 }));

	// stackにstart地点のrawとcolを追加
	stack_.push({ startRow_ ,startCol_ });
	// start地点を訪問済みにする
	visited[startRow_][startCol_] = true;

	// stackの中身が空でないとき
	while (!stack_.empty()) {
		// Point構造体型の変数を作り、
		// stackの一番上の要素(代入された要素の中で一番新しいもの)で初期化
		Point current = stack_.top();
		stack_.pop();	// stackの一番上の要素を削除 => currentに入れたので用済み

		// 現在の位置を保存
		int row = current.row;
		int col = current.col;

		// ゴールチェック -----------------------------------------------------
		if (row == goalRow_ && col == goalCol_) {
			// 先にスタートとゴールを表示
			// 一度だけ表示したい 且つ startとgoalの情報が欲しいのでここで記述
			cout << "Start(" << startCol_ << ", " << startRow_ << 
				") Goal(" << goalCol_ << ", " << goalRow_ << ")" << endl << endl;

			// stackは最新要素が一番上なので、先にゴールを書く
			cout << "GOAL! ";

			// 経路表示 -----------
			Point currentCell = { goalRow_, goalCol_ };
			while (currentCell.row != -1 && currentCell.col != -1) {
				cout << "( " << currentCell.col << "," << currentCell.row << " ) <= ";
				currentCell = print[currentCell.row][currentCell.col]; // printに入れることで要素数をデクリメント

			}
			
			cout << "Start!";

			return true;	// 終了
		}

		// 上下左右に隣接するマスを探索 ---------------------------------------
		/*---------------------------*
		 * drが -1 dcが  0 => 上方向 *
		 * drが  1 dcが  0 => 下方向 *
		 * drが  0 dcが -1 => 左方向 *
		 * drが  0 dcが  1 => 右方向 *
		 *---------------------------*/
		int dr[] = { -1, 1,  0, 0 };	// DeltaRow		delta => 変化
		int dc[] = {  0, 0, -1, 1 };	// DeltaCol

		// 上下左右分(4回)新しい座標取得
		for (int i = 0; i < DIRECTIONS; i++) {
			int new_row = row + dr[i];
			int new_col = col + dc[i];

			// 新しい座標がマップの範囲内(インデックスが0以上でROWS(COLS)以下)　且つ
			if (0 <= new_row && new_row < ROWS && 0 <= new_col && new_col < COLS &&
				DFSval[new_row][new_col] == 0 &&	// 通行できる場所である(!= 1)　且つ
				!visited[new_row][new_col]) {		// 未訪問である
				
				stack_.push({ new_row, new_col });	// stackに新しい座標追加
				visited[new_row][new_col] = true;	// 訪問済みにする

				// 表示時に使用するベクトルに情報保存
				print[new_row][new_col] = { row ,col };	// 今のセルが新しいセルの前のセル(row == new_row - 1)
			}
		}
	}

	// ゴール未到達
	cout << "Goal not reached" << endl;
	return false;

}

int main()
{
	int startCol = 2, startRow = 3;
	int goalCol = 6, goalRow = 6;

	// ゴールにたどり着けなかったとき => 経路がないとき
	if (!dfs(startRow, startCol, goalRow, goalCol)) {
		cout << "Not path to the Goal" << endl;
	}

	return 0;

}