#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int N = 26;

int calculate_point(string word);
void determine_winner();

int main(void)
{
    determine_winner();
}

int calculate_point(string word)
{
    // the system used to calculate the points
    int system[N][2] = {{'A', 1}, {'B', 3}, {'C', 3},  {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2},
                        {'H', 4}, {'I', 1}, {'J', 8},  {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1},
                        {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1},
                        {'V', 4}, {'W', 4}, {'X', 8},  {'Y', 4}, {'Z', 10}};

    int points = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // convert the word into uppercase
        word[i] = toupper(word[i]);
        for (int j = 0; j < N; j++)
        {
            // check if letter exists in the system
            if (word[i] == system[j][0])
            {
                // designate points accordingly
                points += system[j][1];
            }
        }
    }
    return points;
}

void determine_winner()
{
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    // determine winner by comparing points
    if (calculate_point(player1) > calculate_point(player2))
    {
        printf("Player 1 wins\n");
    }
    else if (calculate_point(player1) < calculate_point(player2))
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
