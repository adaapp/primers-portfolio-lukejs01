#include <thread>

void SleeperTimer(int& seconds){
  if(seconds == 0){
    seconds = 10;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000));
}

void sleepTimer(void) {
  std::string seconds;
  std::cout << "Enter number of seconds to sleep: ";
  std::getline(std::cin, seconds);
  seconds = stoi(seconds);
	SleeperTimer(seconds)
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}