#include <iostream>
#include <cstdlib>
#include <stdexcept>

void bubbleSorts(const char *sortParameter, std::istream &in, std::ostream &out);
void readFromFile(const char *fileName, std::ostream &out);
void convertVector(std::istream &in, std::ostream &out);
void bubbleSortRandomValues(const char *sortParameter, const int size, std::ostream &out);

int main(int argc, char *argv[])
{
  if ((argc < 2) || (argc > 4))
  {
    std::cerr << "Amount of arguments is incorrect." << std::endl;
    return 1;
  }
  if (argv[1][1] != '\0')
  {
    std::cerr << "Incorrect parameter";
    return 1;
  }
  const int task = std::atoi(argv[1]);
  switch (task)
  {
    case 1:
      if (argc != 3)
      {
        std::cerr << "Amount of arguments is incorrect for first task.\n";
        return 1;
      }
      try
      {
        bubbleSorts(argv[2], std::cin, std::cout);
      } catch (const std::exception &exception)
      {
        std::cerr << exception.what() << '\n';
        return 2;
      }
      break;

    case 2:
      if (argc != 3)
      {
        std::cerr << "Amount of arguments is incorrect for second task.\n";
        return 1;
      }
      try
      {
        readFromFile(argv[2], std::cout);
      } catch (const std::exception &error)
      {
        std::cerr << error.what() << '\n';
        return 2;
      }
      break;

    case 3:
      if (argc != 2)
      {
        std::cerr << "Amount of arguments is incorrect for third task.\n";
        return 1;
      }
      try
      {
        convertVector(std::cin, std::cout);
      } catch (const std::exception &error)
      {
        std::cerr << error.what() << '\n';
        return 2;
      }
      break;

    case 4:
      if (argc != 4)
      {
        std::cerr << "Amount of arguments is incorrect for fourth task.\n";
        return 1;
      }
      try
      {
        char *error = nullptr;
        long int vectorSize = strtol(argv[3], &error, 0);
        if (*error != '\0')
        {
          std::cerr << "Size of vector is incorrect.\n";
          return 1;
        }
        bubbleSortRandomValues(argv[2], vectorSize, std::cout);
      } catch (const std::exception &error)
      {
        std::cerr << error.what() << '\n';
        return 2;
      }
      break;

    default:
      std::cerr << "Number of task is incorrect\n";
      return 1;
  }
  return 0;
}
