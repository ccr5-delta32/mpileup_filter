#include <string>
#include <vector>

class StreamProcessor {

  public:
    StreamProcessor();

  private:
    std::string line;
    int tmp;
    int incr();
    void proclines();
    std::vector<int> makeItr(std::vector<std::string>& vec);
};
