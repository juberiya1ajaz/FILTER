#include "helpers.h"
#include <math.h>
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avearage;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // averages the color intensity and then applies the same value to all the colors to get grey
            avearage = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);

            image[i][j].rgbtBlue =avearage ;
            image[i][j].rgbtGreen = avearage;
            image[i][j].rgbtRed = avearage;
        }
    }
}   
//GET SEPIA FILTER
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i=0; i<height; i++)
     {
        for (int j = 0; j < width; j++)
        {   // HERE O MEANS ORIGINAL COLOUR
            int ORed = image[i][j].rgbtRed; 
            int OBlue = image[i][j].rgbtBlue;
            int OGreen = image[i][j].rgbtGreen;
            //CALCULATING VALUE OF DIFFERENT SEPIASHADE
            int sepiaRed = round(.393 * ORed + .769 * OGreen + .189 *OBlue);
            
             if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            } 
                
            int sepiaGreen = round(.349 * ORed + .686 * OGreen + .168 * OBlue);
            
            if ( sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen ;
            }
            
            int sepiaBlue = round(.272 * ORed + .534 * OGreen + .131 * OBlue);
            
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
         }
         
     }    

    return;
}
//REFLECTING THE IMAGE
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {   
        for (int j = 0; j < width/2; j++)
        {   
            //use of a temporary array to swap pixels
             RGBTRIPLE swap = image[i][j];
            //swapping from left to right
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = swap;
        }
    }
            
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   //USE OF TEMPORARY ARRAY TO COPY IMAGE
    RGBTRIPLE cp[height][width];
    //ITERATE THROUGH EACH PIXEL
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            float counter = 0.00;
            //ITERATE THROUGH EACH NEIGHBOURING PIXEL
            for (int h = -1; h < 2; h++)
            {
                
                for (int w = -1; w < 2; w++)
                {
                    //CHECK VALIDITY OF PIXEL-i.e if pixel is inside the image 
                    if ( i + h >=0 && i + h < height && j + w >= 0 && j + w < width  )
                    {
                     sumBlue += image[i+h][j+w].rgbtBlue;
                     sumGreen += image[i+h][j+w].rgbtGreen;
                     sumRed += image[i+h][j+w].rgbtRed;
                     counter++;  
                    }
                    
                }
            }

            // averages the sum to create blurr effect
            cp[i][j].rgbtBlue = round(sumBlue / counter);
            cp[i][j].rgbtGreen = round(sumGreen / counter);
            cp[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = cp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = cp[i][j].rgbtGreen;
            image[i][j].rgbtRed = cp[i][j].rgbtRed;
        }
    }

    return;
}
