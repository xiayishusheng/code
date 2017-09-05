/* 生命游戏规则如下：
1.如果一个细胞周围有3个细胞为生（一个细胞周围共有8个细胞），则该细胞为生，即该细胞若原先为死，则转为生，若原先为生，则保持不变；
2.如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变；
3.在其它情况下，该细胞为死，即该细胞若原先为生，则转为死，若原先为死，则保持不变设定图像中每个像素的初始状态后依据上述的游戏规则演绎生命的变化，由于初始状态和迭代次数不同，将会得到令人叹服的优美图案。 */

#include <stdio.h>
void main()
{
	int	orgData[100][100], resData[100][100];   /*分别记录每次迭代的初始和结果状态*/
	int	nCount, nRows, nCols, i, j, times;      /*times记录迭代次数*/

	for ( i = 0; i <= 100; i++ )                /*初始化数据，令每一个细胞为生*/
		for ( j = 0; j <= 100; j++ )
			orgData[i][j] = 1;

	for ( times = 1; times <= 200; times++ )
	{
		for ( nRows = 1; nRows <= 99; nRows++ )
		{
			for ( nCols = 1; nCols <= 99; nCols++ )         /*计算每一个细胞周围的活的细胞数*/
			{
				nCount = orgData[nRows 1][nCols 1] + orgData[nRows 1][nCols]
					 + orgData[nRows 1][nCols + 1] + orgData[nRows][nCols 1]
					 + orgData[nRows][nCols + 1] + orgData[nRows + 1][nCols 1]
					 + orgData[nRows + 1][nCols] + orgData[nRows + 1][nCols + 1];
				switch ( nCount )
				{
				case 3: putpixel( nCols + 210, 120 + nRows, BLACK );       /*周围有3个活细胞，该细胞为生，在屏幕上用黑色像素表示*/
					resData[nRows][nCols] = 1;
					break;
				case 2: resData[nRows][nCols] = orgData[nRows][nCols];   /*周围有2个活细胞，该细胞不变，在屏幕显示也不变*/
					break;
				default: resData[nRows][nCols] = 0;                        /*其它情况下，细胞为死，在屏幕上用白色像素表示*/
					putpixel( nCols + 210, 120 + nRows, WHITE );
				}
			}
		}

		for ( i = 1; i <= 99; i++ )
			for ( j = 1; j <= 99; j++ )
				orgData[i][j] = resData[i][j];

		getch();
	}
}
