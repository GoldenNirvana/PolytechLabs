#include <iostream>
#include <stdexcept>

void fillDictionary(std::istream &in, std::ostream &out);
void fillAndSortShapes(std::istream &in, std::ostream &out);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect parameter.";
    return 1;
  }
  char *error = nullptr;
  long int number_task = strtol(argv[1], &error, 0);
  if (*error != '\0')
  {
    std::cerr << "Incorrect parameter.";
    return 1;
  }

  try
  {
    switch (number_task)
    {
      case 1:
        fillDictionary(std::cin, std::cout);
        break;
      case 2:
        fillAndSortShapes(std::cin, std::cout);
        break;
      default:
        std::cerr << "Incorrect task number";
        return 1;
    }
  }
  catch (const std::exception &exception)
  {
    std::cerr << exception.what() << '\n';
    return 1;
  }

  return 0;
}
