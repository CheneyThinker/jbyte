#include "../include/jbyte.h"

int main(int argc, char** argv)
{
  if (!strcasecmp(argv[1], "--analyzer")) {
    return jbyte_analyzer(argc, argv);
  } else if (!strcasecmp(argv[1], "--generator")) {
    return jbyte_generator(argc, argv);
  }
  return 0;
}
