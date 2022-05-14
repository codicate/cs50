#include <cs50.h>
#include <stdio.h>

int getLen(long n)
{
  int l = 0;
  while (n > 0)
  {
    n /= 10;
    l++;
  }

  return l;
}

int getFirstTwoDigits(long n)
{
  while (getLen(n) > 2)
    n /= 10;

  return n;
}

bool checkCard(long n)
{
  int sum = 0;

  int i = 0;
  while (n > 0)
  {
    if (i % 2 == 1)
    {
      int lastDigit = (n % 10) * 2;

      if (lastDigit >= 10)
        sum += lastDigit % 10 + 1;
      else
        sum += lastDigit;
    }
    else
    {
      sum += n % 10;
    }

    n /= 10;
    i++;
  }

  return (sum % 10 == 0);
}

string getResult(long n)
{
  if (checkCard(n))
  {
    if (getLen(n) == 15 && (getFirstTwoDigits(n) == 34 || getFirstTwoDigits(n) == 37))
      return "AMEX\n";
    else if (getLen(n) == 16 && getFirstTwoDigits(n) >= 51 && getFirstTwoDigits(n) <= 55)
      return "MASTERCARD\n";
    else if ((getLen(n) >= 13 || getLen(n <= 16)) && (getFirstTwoDigits(n) / 10) == 4)
      return "VISA\n";
  }
  return "INVALID\n";
}

int main(void)
{
  long cardNum = get_long("Number: ");
  printf("%s", getResult(cardNum));
}
