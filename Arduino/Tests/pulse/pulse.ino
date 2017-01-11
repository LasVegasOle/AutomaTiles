/*
 * This test file, tests setColorRGB function.
 * Sweeping colors components from 0 to 255
 */
int i = 0;                      
void setup() {  
   setButtonCallback(button); 
   setStepCallback(step);
   setColorRGB(170, 255, 0);
   fadeTo(0, 255, 255, 4000);
}

void loop() {
}

void button() {
    if (i == 0){
    // positive increment
      //from = {170, 255, 0}; 
      //to = {0, 255, 255};  // Hue 80 to 180
      setColorRGB(170, 255, 0);
      fadeTo(0, 255, 255, 2000);
    } else if (i == 1) {
      //from = {255, 0, 255}; 
      //to = {255, 85, 0};  // Hue 300 to 20
      setColorRGB(255, 0, 255);
      fadeTo(255, 85, 0, 2000);
    } else if (i == 2) {
    // Negative increments
      //from = {0, 255, 255}; 
      //to = {170, 255, 0};  // Hue 180 to 80
      setColorRGB(0, 255, 255);
      fadeTo(170, 255, 0, 2000);
    } else if (i == 3) {
      // from = {255, 85, 0}; 
      // to = {255, 0, 255};  // Hue 20 to 300
      setColorRGB(255, 85, 0);
      fadeTo(255, 0, 255, 2000);
    }
    i++;
    if(i > 3)
      i = 0;
}

void step() {
    // discrete time logic here
}


