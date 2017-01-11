/*
 * This test file, tests setColorRGB function.
 * Sweeping colors components from 0 to 255
 */
                           
void setup() {  
   setButtonCallback(button); 
   setStepCallback(step);
   setColorRGB(255, 0, 0);
   //blink(1000);
   //pulse(1000);
   fadeTo(0, 0, 255, 4000);
}

void loop() {
}

void button() {
     setColorRGB(170, 255, 0);
     fadeTo(0, 255, 255, 4000);
}

void step() {
    // discrete time logic here
}


