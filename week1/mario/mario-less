#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);
int get_height(void);

int main(void)
{
    int height = get_height();
    for (int i = 0; i < height; i++)
    {
        print_row(height - (i + 1), i + 1);
    }
}

// get the desired height from the user
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while ((n < 1 || n > 8));

    return n;
}
// print the row
void print_row(int spaces, int bricks)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}