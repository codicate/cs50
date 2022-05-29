#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
  string text = get_string("Text: ");
  double wordCount = 1, letterCount = 0, sentenceCount = 0;

  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] == ' ')
      wordCount++;
    else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
      sentenceCount++;
    else if (isalpha(text[i]))
      letterCount++;
  }

  wordCount /= 100;
  letterCount /= wordCount;
  sentenceCount /= wordCount;
  double gradeLevel = 0.0588 * letterCount - 0.296 * sentenceCount - 15.8;

  if (gradeLevel < 1)
    printf("Before Grade 1\n");
  else if (gradeLevel >= 16)
    printf("Grade 16+\n");
  else
    printf("Grade %i\n", (int)round(gradeLevel));
}