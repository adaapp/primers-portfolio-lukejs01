
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <algorithm>  

bool isNumber1(std::string value){ // checks whether the character matches with a digit
  std::string c = value;
  char number [10] = {'0','1','2','3','4','5','6','7','8','9'}; // array of digits
  for(char& count : c){
    for(int i = 0; i < 9; i++){ // loops through the array
      if(number[i] == count){ // checks the value against the character
      return true; // returns true if it matches
      }
    }
  }
  return false; // else returns false
}

std::vector<std::string> findInList(std::vector<std::string> data, std::string input){ // finds all the elements in file that match with input + the associated data
  bool check = false;  // declaring variables
  
  std::vector<std::string> dataList = data;
  std::vector<std::string> reverse = data;
  std::vector<std::string> inputList = {};
  std::string word;

  if(!isNumber(input)){ // checks whether input is number - determines the list searched through
    for(auto c : dataList){ // loops through list
      word = c; // assigns count to a string variable for comparison 
      if(check == true){ // used to check whether the iteration before was a match so the associated data can be added to the list
        inputList.push_back(word); // adds to list
        check = false; // resets the counter
      }
      if(word == input){ // checks if element matches input
        inputList.push_back(word); // adds to list
        check = true; // sets check to true for next iteration
      }
    }
  }
  
  if(isNumber(input)){ // checks if number
      std::reverse(reverse.begin(),reverse.end()); // if number then list is reversed so numbers are read first
      for(auto i : reverse){ 
        word = i; 
        if(check == true){
          inputList.push_back(word);
          check = false;
        }
        if(i == input){
          inputList.push_back(word);
          check = true;
        }
      }
  }
  return inputList; // returns the list
}

bool fileExists(std::string filename){ // checks if file exists
  struct stat buf;
  if(stat(filename.c_str(), &buf) == 0){
    std::cout << "\nsize: " << &buf.st_size;
    std::cout << "\nmodified: " << ctime(&buf.st_mtime);
    std::cout<< "File ok";
    return true;
  }
  return false;
}


std::vector<std::string> readToList(std::string file){ // converts file to list for data handling
  std::string line; // declaring variables
  std::ifstream fileObject;
  std::vector<std::string> data = {};

  fileObject.open(file); // opens file object
  while(!fileObject.eof()){ // loops until the end of the file
    getline(fileObject, line); // gets the line of the file 
    data.push_back(line); // adds it to a list
  }
  fileObject.close(); // closes file object
  return data; // returns the list
}
void formattedOutputList(std::vector<std::string> list){ // formats the list for output 
  std::string out1 = ""; //declaring variables
  std::string out2 = "";
  int count = 1; // used to pull items on their index

  for(int i = 0; i < list.size();i++){ // loops through list
    if(count == 3){ // resets the count for first item
      count = 1;
    }
    if(count == 2){ // if count two then pulls the associated second item
      out2 = list[i];
      count++;
      std::cout << out1 << ", T: " << out2 << "\n"; // outputs the data
    }
    if(count == 1){ // pulls first item
      out1 = list[i];
      count++; //updates count
    }
  }
}



void DataFileParser(){
  std::vector<std::string> data = {}; // declaring variables
  std::vector<std::string> searchedData = {};
  std::string userInput = "";

  if(fileExists("phone.csv")){ // checks if file exists
    data = readToList("phone.csv"); // assigns converted file to the variable data 
    std::cout << "\nPlease enter a name or number to search: ";
    std::getline(std::cin, userInput);

    searchedData = findInList(data,userInput); // searches list using input
    std::cout<<"\nSearching "<< data.size()/2 << " records\n"; 
    std::cout << "Contact details: \n";
    if(searchedData.size() > 0){
      formattedOutputList(searchedData); // formats list for output
    }
    if(searchedData.size() == 0){ // no data in list, no item was in list
      std::cout << "\nSorry, no contact details found";
    }
  }

}
void phoneDirectory(void) {
  DataFileParser();
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}