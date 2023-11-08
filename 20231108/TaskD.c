#include <stdio.h>

int main()
{
    // ループ開始
    for (int i = 1; i < 100; i++)
    {
        // iが3の倍数かつ5の倍数の時
        if (i % 3 == 0 && i % 5 == 0)
        {        
            // iを出力
            printf("%d ", i);
            printf("fizz buzz\n");
        }
        // iが3の倍数の時
        else if (i % 3 == 0)
        {
            // iを出力
            printf("%d ", i);
            printf("fizz\n");
        }
        // iが5の倍数
        else if (i % 5 == 0)
        {
            // iを出力
            printf("%d ", i);
            printf("buzz\n");
        }

        // ループエンド
    }

}