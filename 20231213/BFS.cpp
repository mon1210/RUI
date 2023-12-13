#include <iostream>
#include <vector>
#include <queue>
/*
* queue
* enqueue  追加
* dequeue  削除
* front	   取り出し
*/
using namespace std;

const int ROWS = 8;			// 行
const int COLS = 8;			// 列
const int DIRECTIONS = 4;	// 方向　上下左右

//　通路:0,壁:1
int BFSval[ROWS][COLS] = {
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
* @brief   幅優先探索メソッド
* @note    キューを使用
* @return  true:ゴール(終了) / false:まだゴールしていない(継続)
*/
bool bfs(int startRow_, int startCol_, int goalRow_, int goalCol_)
{
	// 座標の構造体持つキューを用意
	queue<Point> queue_;

	// 訪れたかどうかを示すvisitedベクトルを作る ------------------------------------------------------
	// vector<bool>(COLS, false) でCOLSサイズの一次元ベクトルを作成して、falseで初期化する
	// ROWSサイズの一次元ベクトルを作成し、↑のベクトルで初期化する
	// vector<要素の型>(サイズ, 初期化値)　を二重で書き、二つの一次元ベクトルから二次元ベクトルを作る
	vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

	// どのセルから遷移してきたかを保存するprevベクトルを作る  -1で初期化
	vector<vector<int>> prev(ROWS, vector<int>(COLS, -1));


	// queueにstart地点のrawとcolを追加
	queue_.push({ startRow_ ,startCol_ });	// enqueue 末尾に要素追加
	// start地点を訪問済みにする
	visited[startRow_][startCol_] = true;

	// queueの中身が空でないとき
	while (!queue_.empty()) {
		// Point構造体型の変数を作り、
		// queueの一番上の要素(代入された要素の中で一番新しいもの)で初期化
		Point current = queue_.front();	// front 先頭の要素取り出し
		queue_.pop();	// queueの先頭の要素を削除(dequeue) => currentに入れたので用済み

		// 現在の位置を保存
		int row = current.row;
		int col = current.col;

		// ゴールチェック -----------------------------------------------------
		if (row == goalRow_ && col == goalCol_) {
			// 先にスタートとゴールを表示
			// 一度だけ表示したい 且つ startとgoalの情報が欲しいのでここで記述
			cout << "Start(" << startCol_ << ", " << startRow_ << 
				") Goal(" << goalCol_ << ", " << goalRow_ << ")" << endl << endl;

			// 経路表示 -----------	
			// 最終的な経路表示用printベクトルを作る 
			vector<Point> path;
			// 現在のセル(ゴール)から最終セル(スタート)までを逆順にpathに格納
			while (!(row == startRow_ && col == startCol_)) {
				path.push_back({ row, col });	// 現在のセル情報を保存
				// 次のセル座標を取得
				Point next = { prev[row][col] / COLS ,		// 直前のセルの行番号
							   prev[row][col] % COLS };		// 直前のセルの列番号
				row = next.row;
				col = next.col;
			}

			// while文の条件が!startなので、startが表示されないので記述 => DFSとの比較がしやすいように
			cout << "Start(" << startCol_ << ", " << startRow_ << ") => ";
			// 表示ループ　逆順に表示
			for (int i = path.size() - 1; i >= 0; i--) {
				cout << "(" << path[i].col << ", " << path[i].row << ") => ";
			}

			cout << "GOAL!";
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
				BFSval[new_row][new_col] == 0 &&	// 通行できる場所である(!= 1)　且つ
				!visited[new_row][new_col]) {		// 未訪問である
				
				queue_.push({ new_row, new_col });	// queueに新しい座標追加(enqueue)
				visited[new_row][new_col] = true;	// 訪問済みにする

				// どのセルから遷移してきたかを保存
				prev[new_row][new_col] = row * COLS + col;	// 今のセル  直前のセルの行番号 * COLS + 直前のセルの列番号
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
	if (!bfs(startRow, startCol, goalRow, goalCol)) {
		cout << "Not path to the Goal" << endl;
	}

	return 0;

}