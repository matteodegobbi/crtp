#define THRESHOLD 100
/* Sobel matrixes */
static int GX[3][3];
static int GY[3][3];
/* Initialization of the Sobel matrixes, to be called before
Sobel filter computation */
static void initG()
{
/* 3x3 GX Sobel mask. */
    GX[0][0] = -1; GX[0][1] = 0; GX[0][2] = 1;
    GX[1][0] = -2; GX[1][1] = 0; GX[1][2] = 2;
    GX[2][0] = -1; GX[2][1] = 0; GX[2][2] = 1;

/* 3x3 GY Sobel mask. */
    GY[0][0] =  1; GY[0][1] =  2; GY[0][2] =  1;
    GY[1][0] =  0; GY[1][1] =  0; GY[1][2] =  0;
    GY[2][0] = -1; GY[2][1] = -2; GY[2][2] = -1;
}

/* Sobel Filter computation for Edge detection. */
static void makeBorder(char *image, char *border, int cols, int rows)
/* Input image is passed in the byte array image (cols x rows pixels)
   Filtered image is returned in byte array border */
{
    int x,y, i, j, sumX, sumY, sum;

    for(y = 0; y <= (rows-1); y++)
    {
        for(x = 0; x <= (cols-1); x++)
        {
            sumX = 0;
            sumY = 0;
/* handle image boundaries */
            if(y == 0 || y == rows-1)
                sum = 0;
            else if(x == 0 || x == cols-1)
                sum = 0;

/* Convolution starts here */
            else
            {
/* X Gradient */
                for(i = -1; i <= 1; i++)
                {
                    for(j =- 1; j <= 1; j++)
                    {
                        sumX = sumX + (int)( (*(image + x + i +
                          (y + j)*cols)) * GX[i+1][j+1]);
                    }
                }
/* Y Gradient */
                for(i = -1; i <= 1; i++)
                {
                    for(j = -1; j <= 1; j++)
                    {
                        sumY = sumY + (int)( (*(image + x + i +
                            (y + j)*cols)) * GY[i+1][j+1]);
                    }
                }
/* Gradient Magnitude approximation to avoid square root operations */
                sum = abs(sumX) + abs(sumY);
            }

             if(sum > 255) sum = 255;
             if(sum < THRESHOLD) sum = 0;
            *(border + x + y*cols) = 255 - (unsigned char)(sum);
        }
    }
}
