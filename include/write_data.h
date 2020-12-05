#include <stdio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}