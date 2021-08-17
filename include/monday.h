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







bool isNumber(const std::string& value){ //checks whether string contains only numbers
  size_t f; //max size for string 
  f = value.find_first_not_of("0123456789"); // characters other than these will be checked
  if(f == std::string::npos){
    return true; // if max size is reached no characters outside the digits were found
  }
  std::cout<<"\nNot a number"; 
  return false; // otherwise isnt a number
}

float strTofloat(std::string str){ // converts string to float
  float val = 1; // default value
  if(isNumber(str)){ // calls isNumber function to check if it only contains numbers
    val = stof(str); // if true then converts to float
  }
  return val; // else returns default number
}
float strToint(std::string str){ //converts string to int 
  float val = 1; // default value
  if(isNumber(str)){ // calls isNumber function to check if it only contains numbers
    val = stoi(str); // converts string to int
  }
  return val; // otherwise returns default number
}

float addItem(float t,int quant, float price){
  return t + (quant * price); // adds value of quant * price to current subtotal
}

float calcTotal(float tax, float subt){ // takes subtotal and works out tax
  std::cout<<"Sales tax: £"<< tax << "\n";
  return subt * (1 +(tax / 100)); // converts tax to a percentage multiplier and times it with the subtotal
}

void selfServiceCheckout(void) {
int count = 1;  // declaring all variables
  int quant = 1;
  float salesTax = 5.5;
  float price = 0.0; 
  float subtotal = 0.0;
  float total = 0.0;
  std::string inputQuant; 
  std::string inputPrice;

  while(quant > 0){ // loop until 0 for exit 
    std::cout<<"\nPlease enter a quantity for item "<< count << "(or 0 to finish): ";
    std::cin>> inputQuant; // user input for quantity of item
    
    quant = strToint(inputQuant); // see above 
    
    
    if(quant > 0 && isNumber(inputQuant)){ // executes when program isnt exitted and quant input is valid
      std::cout<<"\nPlease enter item's cost: ";
      std::cin>> inputPrice;  // user input for price
      price = strTofloat(inputPrice); // see above
      count++; // updates counter for loop, used for user to check item count
      
      if(price > 0.0 && isNumber(inputPrice)){ // executes when program isnt exitted and price input is valid
        subtotal = addItem(subtotal,quant,price); // calculates subtotal - see above
        }
      
    }

  }
  std::cout<<"Thank you!\n";

  if(subtotal > 0.0){
    std::cout<<"Subtotal: £"<< subtotal << "\n\n";
    total = calcTotal(5.5,subtotal); // calculates total after tax - see above
    std::cout<<"Total: £"<< total<< "\n";
  }
}

