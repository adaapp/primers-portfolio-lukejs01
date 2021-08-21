bool isNumberCar(const std::string& value){ //checks whether string contains only numbers
  size_t f; //max size for string 
  f = value.find_first_not_of("0123456789"); // characters other than these will be checked
  if(f == std::string::npos){
    return true; // if max size is reached no characters outside the digits were found
  }
   
  return false; // otherwise isnt a number
}

class car { // creating car class
  private: // creating rpivate variables and functuions

    const std::string DEFAULT_COLOUR = "Red";
    const std::string DEFAULT_MAKE = "Honda";

    std::string car_colour; 
    std::string car_make; 
    bool engine_turned_on;
    bool car_locked;


    void init_car(std::string colour, std::string make, bool running, bool is_locked) { // intialising car
      car_colour = colour;
      car_make = make;
      engine_turned_on = running;
      car_locked = is_locked;
    }

  public: // creating public variables and functions 
    car() { // default car constructor 
      std::cout << "\ncreated no params";
      init_car(DEFAULT_COLOUR, DEFAULT_MAKE, false, true);
    }

    car(std::string colour, std::string make) { // constructor for make and colour
      std::cout << "\ncreated with params";
      init_car(colour, make, false, true);
    }

    car(std::string colour) { // constructor for colour
      std::cout << "\ncreated with params";
      init_car(colour, DEFAULT_MAKE, false, true);
    }

    ~car() { // destroys the instance
      std::cout << "\ndestroyed\n";
    }

    // getters and setters for properties
    void set_colour(std::string colour) { 
      car_colour = colour;
    }

    std::string get_colour(void) { 
      return car_colour;
    }

    void set_make(std::string make) { 
      car_make = make;
    }
    std::string get_make(void) { 
      return car_make;
    }
    
    void engine_on(void) {  // turns car engine on
      if(!engine_turned_on){ // if engine is set to off
        engine_turned_on = true;
        std::cout << "Turning engine on\n";
      } else{
        std::cout << "Sorry engine is already on\n"; // if already true
      }
      
    } 
 
    void engine_off(void);

    void locked(bool is_locked) {  // locks or unlocks car
      if(is_locked) { // if the car is locked
        car_locked = true;
        std::cout << "Car is locked\n";
      } else { // if the car is unlocked
        car_locked = false;
        std::cout << "Car is unlocked\n";
      }
    } 

    void status(void) { // shows the status of the car
      std::string engine_label = "Off"; // defualt value
      std::string locked_label;

      if (engine_turned_on) { // if the car is on
        engine_label = "Running";
      }

      car_locked ? locked_label = "Locked" : "Unlocked"; 

      std::cout << "\n Car Status: colour: " << car_colour << ", make: " << car_make << ", engine: " << engine_label << ", " << locked_label; // displays stauts
    } 
};

void car::engine_off(void) { // turns engine off
  if(engine_turned_on) { // if engine is on
    engine_turned_on = false; // turns the engine off
    std::cout << "Turning engine off\n";
  } else {
    std::cout << "\nSorry, the engine is already off"; // if already off
  }
} 


void primer9() {
  std::string strChoice = ""; // declaring variables
  int choice = 0;
  car my_car; // creates instace of car


  do{ // loops until choice is 0
    strChoice = "";
    choice = 0;
    my_car.status(); // displays status of car
    std::cout << "\n1. Turn Engine on\n";
    std::cout << "2. Turn Engine off\n";
    std::cout << "3. Lock car\n";
    std::cout << "4. Unlock car\n";
    
    
    do{ // loops until choice is a number
      std::cout << "Please select an option(or 0 to finish): \n";
      std::getline(std::cin, strChoice);
      
      if(isNumberCar(strChoice)){ // checks whether variable is a number
      choice = stoi(strChoice); // converts getline to a number 
      }
      else{
        std::cout << "You did not enter a number \n";
      }
    }while(!isNumberCar(strChoice));

    switch(choice){ // switch statement for choices -  calls functions depending on choice
      case 1:
      my_car.engine_on();
      break;

      case 2:
      my_car.engine_off();
      break;

      case 3:
      my_car.locked(true);
      break;

      case 4:
      my_car.locked(false);
      break;

      default: 
      if(choice != 0){
        std::cout << "Incorrect choice";
      }
      
    }

  }while(choice != 0);
}

void carClass(void) {
  primer9();
}


class area{
  private: // private variables accessed only in the class
    float h = 0;
    float w = 0;
    float b = 0;
    
    void init_area(float height, float width, float base){
      h = height;
      w = width;
      b = base;
    }

  public:
    area(float h){ // constructor for square
      init_area(h, 0, 0); // initialises class
      std::cout << "Area of square(h= " << h << "): " << calculateArea() << "\n"; // calls the calculate function and displays answer
    }
    
    area(float h, float w){ // constructor for rectangle
        init_area(h, w, 0);
        std::cout << "Area of rectangle(h= " << h << ", w= " << w << "): " << calculateArea() << "\n";
    }

    area(float h, float w, float b){ // constructor for trapezoid
      init_area(h, w, b);
      std::cout << "Area of trapezoid(h= " << h << ", w= " << w << ", b= " << b <<"): " << calculateArea() << "\n";
    }

    

    // getters and setters for properties
    void setHeight(float height){
      h = height;
    }

    float getHeight(void){
      return h;
    }

    void setWidth(float width){
      w = width;
    }

    float getWidth(void){
      return w;
    }

    void setBase(float base){
      b = base;
    }

    float getBase(void){
      return b;
    }

    float calculateArea(){
      float area = 0.0;
      
      if(h != 0 && w != 0 && b != 0){ // checks which values are present
        area = ((b+w) * h)/2; // calculates area using formula
      }
      if(h != 0 && w != 0 & b == 0){ // checks which values are present
        area = h * w; // calculates area using formula
      }
      if(h != 0 && w == 0 && b == 0){ // checks which values are present
        area = h * h; // calculates area using formula
      }
      return area; // returns the area
    }

};



void findingArea(){
  area(6.1); // creates instance of the area class according to arguments 
  area(4,5.9);
  area(7.5,6,14);
}

void areaOf(void) {
	findingArea();
}