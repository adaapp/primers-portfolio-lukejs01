#include <thread>

void SleeperTimer(int seconds){
  if(seconds == 0 ){
    seconds = 10; // sets default to 10 if a value wasnt entered
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000)); // calls the thread and sleeps for 10 seconds
}
void SleeperTimer(std::string value){ // for validation - if the argument is a stirng it calls the other function with a default of 10 seconds
  SleeperTimer(10);
  
}

void sleepTimer(void) {
  
  
	SleeperTimer(5);
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}