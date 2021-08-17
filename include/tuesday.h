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


void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}
