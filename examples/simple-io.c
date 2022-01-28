#include <libpbl/io/pbl-io.h>

int main()
{
  PblString_T *string = PblGetStringT("Hello! Tell me your name: ");
  PblChar_T *end = PblGetCharT(' ');

  PblString_T *input = PblInput(string, end);
  PblPrint(PblGetStringT("Your name is:"), .end=PblGetCharT(' '));
  PblPrint(input);
}