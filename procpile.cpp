#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "procpile.h"

StreamProcessor::StreamProcessor() {
  tmp = 0;
  proclines();
}

int StreamProcessor::incr() {
  tmp += 3;
  return tmp; 
}

std::vector<int> StreamProcessor::makeItr(std::vector<std::string>& vec) {
  std::vector<int> seq( (vec.size()-3)/3 );
  std::generate(seq.begin(), seq.end(),
                std::bind(std::mem_fun(&StreamProcessor::incr), this));
  tmp = 0;
  return seq;
}

void StreamProcessor::proclines() {

  std::string element;

  while(std::getline(std::cin, line)) {
    std::istringstream istr(line);
    std::vector<std::string> lvec;
    while(std::getline(istr, element, '\t')) {
      lvec.push_back(element);
    }
    std::cout << lvec[0] << '\t' << lvec[1] << '\t' << lvec[2] << '\t';
    std::vector<int> itr = makeItr(lvec);
    for (int i=0; i < (int)itr.size()-1; i++) {
      std::cout << std::min(std::stoi(lvec[itr[i]]), 255) << '\t';
    }
    std::cout << std::min(std::stoi(lvec[itr.back()]), 255) << std::endl;
  }
}
