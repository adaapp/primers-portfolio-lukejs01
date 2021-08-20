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




void thread_function(){ // hard coded thread for 5 seconds
  std::cout << "Thread1: " << std::this_thread::get_id() << " started\n"; //displays start of thread
  SleeperTimer(5); // thread sleeps for 5 seconds
  std::cout << "Thread1 " << std::this_thread::get_id() << " ended\n"; // thread ends
}

void thread_function2(){ // hard coded thread for 10 seconds
  std::cout << "Thread2: " << std::this_thread::get_id() << " started\n"; //displays start of thread
  SleeperTimer(10); // thread sleeps for 10 seconds
  std::cout << "Thread2 " << std::this_thread::get_id() << " ended\n"; // thread ends
}

void threadMaker(){
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n"; // displays main thread start
  std::thread t(&thread_function); // starts thread 1
  std::thread y(&thread_function2); // starts thread 2
  t.join(); // blocks the calling thread’s execution until the specified thread terminates
  y.join();
  
std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";
} // displays end of main thread

void joinDetachThreads(void) {
	threadMaker();
}