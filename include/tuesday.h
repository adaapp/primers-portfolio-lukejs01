bool isNumber(char value){ // checks whether the character matches with a digit
  char c = value;
  char number [10] = {'0','1','2','3','4','5','6','7','8','9'}; // array of digits

  for(int i = 0; i < 9; i++){ // loops through the array
    if(number[i] == c){ // checks the value against the character
      return true; // returns true if it matches
    }
  }
  return false; // else returns false
  
}

bool isSpecial(char value){ // checks whether the character matches with a special character
  char c = value;
  char special [22] = {'!','@','$','%','^','&','*','(',')','=','+','?','<','>',';',':','{','}','[',']','.',','}; // array of special characters
  for(int i = 0; i < 21; i++){ // loops through the special characters
    if(special[i] == c){ // checks the value against the character
      return true; // returns true if it matches
    }
  }
  return false; // else returns false
}

bool isAlphabetic(int plen,int dc, int sc){ // checks whether the password contains 4 or more alphabetic characters
  if((plen - dc - sc) >= 4){ // takes the digits and special character counts away from the length of the password to give the alphabetic count
    return true; // true if it is more than 4
  }
  return false; // else false
}

int passwordCheck(){
  std::string password = ""; // declares variables
  std::string strength = "";
  int level = 0;
  int digitCount = 0;
  int specialCount = 0;
   

  std::cout << "\nEnter a password to check: ";
  std::getline(std::cin, password); // user input assigned as password
  int plength = password.length(); // gets password length and assigns it to variable

  for(char c : password){// loops through the password
    if(isNumber(c)){ // see above
        digitCount++; // updates counter if the character is a int
    }
    if(isSpecial(c)){ // see above
      specialCount++; // updates counter if the character is a special character
    }
  }
  

  if(plength <= 4){ // added after requirements - was not considered if the password was empty or did not meet the requirements
    level = 0; // updated the level for return statement 
    strength = " Very weak"; // updated the strength for output
    }

  if(plength == digitCount || digitCount == 0 || specialCount == 0){ // checks whether the password is just one type regardless of password length
    
    level = 1;
    strength = " Weak";
  }
    
  if(plength >= 4 && digitCount >=1 && specialCount >= 1){ // checks whether password is at least 4 characters long
    
    level = 2;
    strength = " Moderate";
  }

  if(plength >=8 && isAlphabetic(plength,digitCount,specialCount)&&
    digitCount >=2 && specialCount <= 1){ // must be greater than 8 characters and have at least 2 digits with at least 4 alphabetic characters
      
    level = 3;
    strength = " Strong"; 
  }

  if(plength >= 8 && isAlphabetic(plength,digitCount,specialCount)&&
  digitCount >=2 && specialCount >= 1){ // must be greater than 8 characters and have at least 2 digits with at least 4 alphabetic characters and at least one special character
  
    level = 4;
    strength = " Very strong"; 
  }
  
  std::cout<< "The password '" << password << "' is"<< strength; // outputs the strength complexity of the password

  return level; // returns the level
}


void passwordComplexityChecker(void) {
	passwordCheck();
}





#include <list>
#include <boost/algorithm/string.hpp>

std::string lowString(std::string& name){ // converts user input to lower case
  transform(name.begin(), name.end(), name.begin(), ::tolower);
  return name;
}

std::list<std::string> toLower(std::list<std::string>& names){ // converts all names in list to lowercase
  std::list<std::string> lowList = {}; // declaring lower case list
  std::string lowName = ""; // place holder variable
  for(auto i : names){ // loops through elements in the list
    transform(i.begin(), i.end(), i.begin(), ::tolower); // converts each element to lower case
    lowName = i;
    lowList.push_back(lowName); // adds it to new list
  }
  return lowList; // returns new list
}

void displayNames(std::list<std::string>& names){ // displays all elements in the list
  for(auto i : names){ // loops through list
    std::cout << i << "\n"; // outputs element
  }
}

std::list<std::string> removeFromList(std::list<std::string> names, std::string name){
  for(auto i : names){ // removing name from list
    if(i == name){ // if user input matches an name in the list
      names.remove(name); // remove the name from the list
      return names; // return the adjusted list
    }
  }

  return names; // not matched then return the original list
}

void employeeListRemoval(void) {
	std::string userInput = ""; // declaring variables
  std::list<std::string> names = {"John Smith", "Jaelynn Stuart", "Kaley Barajas", "Walter Collier", "Cale Myers"};
  int nofemp = names.size();

  std::cout << "There are " << nofemp << " employees:\n";
  displayNames(names); // see above

  std::cout << "\nEnter an employee name to remove: ";
  std::getline(std::cin, userInput); // gets user input

  names = removeFromList(toLower(names), lowString(userInput)); // converts both list and user input to lower case, then removes from list if user input matches a name

  nofemp = names.size();
  std::cout << "\nThere are " << nofemp << " employees: \n";
  displayNames(names); // displays new adjusted list
}
