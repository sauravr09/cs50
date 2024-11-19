#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calculate_grade(string text);

int main(void)
{
    string text = get_string("Text: ");

    int grade = calculate_grade(text);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int calculate_grade(string text)
{
    float grade;
    int letter_count = 0;
    int word_count = 0;
    int sentence_count = 0;
    int len = strlen(text);

    // if the grade # is below 1, return Before Grade 1
    // if the grade # is above 16, return Grade 16+

    for (int i = 0; i < len; i++)
    {
        // if letters or digits, increase letter count
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 48 && text[i] <= 57) ||
            (text[i] >= 97 && text[i] <= 122))
        {
            letter_count++;
        }
        // determine if space or end of text for word count
        if (text[i] == ' ' || text[i + 1] == '\0')
        {
            word_count++;
        }
        // determine if a sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    float avg_letter = (((float) letter_count / word_count) * 100);
    float avg_sentence = (((float) sentence_count / word_count) * 100);

    // printf("avg letter count: %f\n", avg_letter);
    // printf("avg sens count: %f\n", avg_sentence);

    grade = 0.0588 * avg_letter - 0.296 * avg_sentence - 15.8;

    // printf("Grade: %d\n", (int) round(grade));

    return (int) round(grade);
}
