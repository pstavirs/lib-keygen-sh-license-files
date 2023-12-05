#if 0
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#else
#include "keygenlic.h"
#include <iostream>
#endif

std::string colorize(const std::string str, const int color_code);

// main runs the example program.
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << colorize("[ERROR]", 31) << " "
              << "No path given"
              << std::endl;

    return 1;
  }

  if (!getenv("KEYGEN_PUBLIC_KEY"))
  {
    std::cerr << colorize("[ERROR]", 31) << " "
              << "Environment variable KEYGEN_PUBLIC_KEY is missing"
              << std::endl;

    return 1;
  }

  if (!getenv("KEYGEN_LICENSE_KEY"))
  {
    std::cerr << colorize("[ERROR]", 31) << " "
              << "Environment variable KEYGEN_LICENSE_KEY is missing"
              << std::endl;

    return 1;
  }

  std::string pubkey = getenv("KEYGEN_PUBLIC_KEY");
  std::string secret = getenv("KEYGEN_LICENSE_KEY");
  std::string path = argv[1];

  std::cout << colorize("[INFO]", 34) << " "
              << "Importing..."
              << std::endl;

  std::string json;
  int ok = getenv("KEYGEN_MACHINE_FINGERPRINT") ?
      verify_machine(path, pubkey, secret, getenv("KEYGEN_MACHINE_FINGERPRINT"), &json) :
      verify_license(path, pubkey, secret, &json);

  if (ok == 0)
  {
    std::cout << "Lincense validated successfully!"
              << json
              << std::endl;
  }
  else
  {
    std::cout << "Lincense validated failed!"
              << std::endl;
  }
}
