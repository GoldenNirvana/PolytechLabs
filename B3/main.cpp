#include <iostream>
#include <string>

void performBookmarks(std::istream &in, std::ostream &out);
void performFactorial(std::ostream &out);

int main(int argc, char *argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Incorrect parameter number.";
      return 1;
    }
    char *error = nullptr;
    long int number_task = strtol(argv[1], &error, 0);
    if (*error != '\0')
    {
      std::cerr << "Size of vector is incorrect.\n";
      return 1;
    }
    switch (number_task)
    {
      case 1:
      {
        performBookmarks(std::cin, std::cout);
        break;
      }
      case 2:
      {
        performFactorial(std::cout);
        break;
      }
      default:
        std::cerr << "Incorrect task number.";
        return 1;
    }
  }
  catch (const std::exception &exception)
  {
    std::cerr << exception.what() << '\n';
    return 2;
  }

  return 0;
}
