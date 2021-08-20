
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <algorithm>  

bool isNumbercheck(std::string value){ // checks whether the character matches with a digit
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

  if(!isNumbercheck(input)){ // checks whether input is number - determines the list searched through
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
  
  if(isNumbercheck(input)){ // checks if number
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

#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>


void FileParser() {

  // declare file and name
  const int MARGIN_BUFFER = 5;
	const int INITIAL = 0;
	const int LASTNAME = 1;
	const int SALARY = 2;

	const std::string FILE_NAME = "employees.csv";
  std::ifstream file(FILE_NAME);

  std::string line;
  std::vector<std::vector<std::string>> records; // 2d vector to hold all rows
	int widths[3] = {0, 0, 0}; // array to hold widths of columns

  while(getline(file, line)) {
    // setup variables to split each record into
    std::stringstream stream(line);
    std::string field;  
    std::vector<std::string> rowList;

    int index = 0;
    while(getline(stream, field, ',')) { // split the row into a fields where there are commas
      if (field.length() > widths[index]) { // keep a running tally of the length of the longest word for spacing
        widths[index] = field.length();
      }
      index++; // keep track of which column
      rowList.push_back(field); // push this new word to the row list
    }
    records.push_back(rowList); // push this record onto the list of all rows
  }

  file.close();

  // first two lines printed based off of the spacing we calculated earlier
  std::cout << std::right << std::setw(widths[INITIAL] - 4) << "Initial" << std::setw(widths[LASTNAME] + MARGIN_BUFFER - 11) << "Last" << std::setw(widths[SALARY] + MARGIN_BUFFER + 4)  << "Salary"<< std::endl;  
  std::cout << std::setw(widths[INITIAL]- 4) << "--------" << std::setw(widths[LASTNAME] + MARGIN_BUFFER - 6) << "----------" << std::setw(widths[SALARY] + MARGIN_BUFFER ) << "--------" << std::endl;
  
  for (int i = 0; i < records.size(); i++) { // for each record in the 2d vector
    for (int j = 0; j < records[i].size(); j++) { // for each field in each record
      if (j == INITIAL) { // if the field is an initial
        std::string initial = std::string(1, records[i][j].at(0)) + ".";
        std::cout << std::setw(widths[j]- 10) << initial; // space using the widths we calculated earlier
      }
      if (j == LASTNAME) { // if the field is a lastname
        std::cout << std::setw(widths[j] + MARGIN_BUFFER + 2) << records[i][j];
      }
      if (j == SALARY) { // if the field is a salary
        std::cout << std::left << "£" << records[i][j];
      }
    }
    std::cout << std::endl;
  }
}

void dataFileParser(void) {
	FileParser();
}