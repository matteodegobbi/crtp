#include <stdlib.h>

#define THRESHOLD 120
/* Sobel matrixes */
static const int GX[3][3] = { 
        -1, 0, 1,
        -1, 0, 2,
        -1, 0, 1
    };
static const int GY[3][3] = { 
         1,  2,  1,
         0,  0,  0,
        -1, -2, -1
    };



#define abs(x) ((x>0)?x:-x)

/* Sobel Filter computation for Edge detection. */
void makeBorder(unsigned char *image, unsigned char *border, int cols, int rows)
/* Input image is passed in the byte array image (cols x rows pixels)
   Filtered image is returned in byte array border */
{
    int x,y, i, j, sumX, sumY, sum;

    for(y = 0; y < rows; ++y)
    {
        for(x = 0; x < cols; ++x)
        {
            sumX = 0;
            sumY = 0;
            /* handle image boundaries */
            if(y == 0 || y == rows-1) sum = 0;
            else if(x == 0 || x == cols-1) sum = 0;

            /* Convolution starts here */
            else
            {
                /* X Gradient */
                for(i = -1; i <= 1; i++)
                    for(j =- 1; j <= 1; j++)
                        sumX += (int)( image [ x + i + (y + j)*cols] * GX[i+1][j+1]);

                /* Y Gradient */
                for(i = -1; i <= 1; i++)
                    for(j =- 1; j <= 1; j++)
                        sumY += (int)( image [ x + i + (y + j)*cols] * GY[i+1][j+1]);
                
                /* Gradient Magnitude approximation to avoid square root operations */
                sum = (abs(sumX) + abs(sumY));
            }

            if(sum > 255) sum = 255;
            if(sum < THRESHOLD) sum = 0;
            border[x + y*cols] = (unsigned char)(sum);
        }
    }
}

#undef abs