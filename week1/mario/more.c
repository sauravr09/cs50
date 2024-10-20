#include <cs50.h>
#include <stdio.h>

int get_height();
void print_spaces(int spaces);
void print_row(int bricks);

int main(void)
{
    int height = get_height();
    for (int i = 0; i < height; i++)
    {
        print_spaces(height - (i + 1));
        // print_row( height - (i+1), i+1);
        print_row(i + 1);
        printf("  ");
        print_row(i + 1);
        printf("\n");
    }
}

// get the height of the bricks.
int get_height()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

// print desired amount of spaces
void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

// print a row of bricks
void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}