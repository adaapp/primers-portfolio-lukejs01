float ftoc(float f){
  return ((f - 32) * 5 / 9); //Fahrenheit to Centigrade.
}

float ctof(float c){
  return ((c * 9 / 5) + 32); //Centigrade to Fahrenheit.
}
void fahrenheitCentigradeConversion(void) {
  std::string temp; //temperature for input
  std::string label;  //
  float ot = 0.0; //original temperature before conversion - converted from temp variable
  float t = 0.0; //temperature after conversion
  bool check = false; // used to break loop for check

  do{ //only allows user to continue when a valid value is inputted
    std::cout << "\nPlease enter the starting temperature: ";
    std::getline(std::cin, temp); //gets input from the console and assigns it to temp
  
    try{
      ot = stof(temp);  //completes conversion from string to float
      check = true; //if completed then the loop is broken
    }catch(...){
      std::cout<<"Incorrect data type entered"; // if not the an error message is displayed
    
    }
  }while(check == false); 
  
  
  

  std::cout << "\nPress ‘C’ to convert from Fahrenheit to Centigrade";
  std::cout << "\nPress ‘F’ to convert from Centigrade to Fahrenheit.\n\n";

  std::cout << "\nYour choice: ";
  std::getline(std::cin, temp); // input for type of conversion

  if(temp == "C" || temp == "c") {  // condition for Centigrade - 
    t = ftoc(ot);  // completes conversion - see function above
    label = "Fahrenheit";
  }

  if(temp == "F" || temp == "f") {  // condition for Centigrade
    t = ctof(ot); // completes conversion - see function above
    label = "Centigrade";
  }

  else{ // if an incorrect choice was entered
    std::cout<<"You did not enter a valid choice\n";
    
  }

  std::cout << ot << " degrees " << label << " is = " << t << "\n";

}


void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

