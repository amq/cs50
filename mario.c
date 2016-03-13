/*
height: 8
       ##
      ###
     ####
    #####
   ######
  #######
 ########
#########
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int line;
    int row;

    do
    {
        printf("height: ");
        height = GetInt();  
    }
    while (height > 23 || height < 0);

    for (line = 0; line < height; line++)
    {
        // print spaces to align the pyramid to the right
        // you can move the pyramid horizontally by changing "+ 1"
        for (row = height; row > line + 1; row--)
        {
            printf(" ");
        }  

        // print hashes
        // you can set the number of hashes in the first row by changing "+ 2"
        for (row = 0; row < line + 2; row++)
        {
            printf("#");
        }

        printf("\n"); 
    }
}
