#include <omp.h>
#include <array>
#include <iostream>
int main (int argc, char** argv) {
  std::array<size_t,2> arr = {0,0};
#pragma omp parallel num_threads(2)
  {
      size_t tid = omp_get_thread_num();
      arr.at(tid) = tid + 1;
  }
  if(arr.at(0) == 1 && arr.at(1) == 2)
    std::cout << "SUCCESS" << std::endl;
  else
    std::cout << "FAILED" << std::endl;
}
