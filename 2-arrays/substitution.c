#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  if (argc != 2)
  {
    printf("Usage: ./substitution  key\n");
    return 1;
  }

  string key = argv[1];

  if (strlen(key) < 26)
  {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  for (int i = 0; i < 26; i++)
  {
    if (!isalpha(key[i]))
    {
      printf("Invalid character in key.\n");
      return 1;
    }

    alphabet[tolower(key[i]) - 'a'] = '!';
  }

  if (strcmp(alphabet, "!!!!!!!!!!!!!!!!!!!!!!!!!!") != 0)
  {
    printf("Duplicate character in key.\n");
    return 1;
  }

  string plaintext = get_string("plaintext: ");

  for (int i = 0; i < strlen(plaintext); i++)
  {
    char c = plaintext[i];
    if (!isalpha(c))
      continue;

    plaintext[i] = (c >= 'a') ? tolower(key[c - 'a']) : toupper(key[c - 'A']);
  }

  printf("ciphertext: %s\n", plaintext);
}