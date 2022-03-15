#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main(void)
{
    printf("#---Game of life---#\n");
    int size;

    //create world
    printf("grid size: ");
    scanf("%d", &size);
    int grid[size * size], next_grid[size * size], next, alive;

    //Kill all cells
    for(int i = 0; i < size * size; i++)
    {
        grid[i] = 0;
        next_grid[i] = 0;
    }

    printf("Grid of cells:\n");
    for(int i = 0; i < size * size; ++i)
    {
        if (i % size == 0)
        {
            printf("\n");
        }
        // printf(".");
        printf("%d\t", i);
    }

    printf("\nEnter living cell positions on grid: \n");
    while(scanf("%d", &alive) != EOF)
    {
        grid[alive] = 1;
        printf("Made alive: %d\n", alive);
    }

    printf("Colony lives.\nColony size: %d\nThe Colony: \n", size*size);
    for(int i = 0; i < size * size; ++i)
    {
        if (i % size == 0)
        {
            printf("\n");
        }
        // printf(".");
        printf("%d", grid[i]);
    }

    
    int generation = 0;

    while(1)
    {
        printf("\e[1;1H\e[2J");
        printf("Generation: %d, Size: %d\n", ++generation, size*size);
        for(int i = 0; i < size * size; i++)
        {
            if (i % size == 0 && i >= size)
            {
                printf("\n");
            }
            if(grid[i] == 0 )
            {
                printf(".");
            }
            else if(grid[i] == 1)
            {
                printf("#");
            }
            else
                printf("?");
        }

        usleep(330000);
        int living = 0;

        for(int i = 0; i < size * size; i++)
        {
            
        //right
            if((i + 1 % size != 0) && (grid[i + 1] == 1))
            {
                living++;
            }
            if(i + 1 % size == 0)
            {
                if(grid[i - size + 1] == 1])
                   living++;
            }
        //left
            if((i > 0) && (i % size != 0) && (grid[i - 1] == 1))
            {
                living++;
            }
            if(i % size == 0)
            {
                if(grid[i + size - 1] == 1)
                    living++;
            }
        //up
            if((i - size >= 0) && (i >= size) && (grid[i - size] == 1))
            {
                living++;
            }
            if(){  };
        //down
            if((i + size < size * size) && (grid[i + size] == 1))
            {
                living++;
            }
            if(i => size * (size - 1))
            {
                if(grid[i - (size * (size - 1))] == 1)
                    living++;
            }
        //rup
            if((i - size >= 0 ) && (i + 1 % size != 0) && (i >= size) && (grid[i + 1 - size] == 1))
            {
                living++;
            }
        //rdown
            if((i + 1 % size != 0) && (i + size < size * size) && (grid[i + 1 + size] == 1))
            {
                living++;
            }
        //lup
            if((i % size != 0) && (i >= size) && (grid[i - 1 - size] == 1))
            {
                living++;
            }
        //ldown
            if((i % size != 0) && (i < size * size) && (grid[i - 1 + size] == 1))
            {
                living++;
            }
            // printf("Checked alive. Iteration: %d, Living: %d\n", i, living);

            if(grid[i] == 1 && (living == 2 || living == 3))
            {
                next_grid[i] = 1;
            }
            else if(grid[i] == 0 && living == 3)
            {
                next_grid[i] = 1;
            }
            else 
            {
                next_grid[i] = 0;
            }
            // else if(grid[i] == 1 && (living == 3 || living == 2))
            // {
            // }
            
            living = 0;
        }

        for(int i = 0; i < size * size; i++)
        {
            grid[i] = (int)next_grid[i];
        }


        //clear screen
        // printf("\e[1;1H\e[2J");
    }
    

    printf("\nProgram end.\n");
    return 0;
}


/*

*/