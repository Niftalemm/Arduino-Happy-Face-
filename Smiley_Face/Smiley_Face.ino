#include <LedControl.h>
 
// Define the number of MAX7219 modules (usually just 1)

#define NUM_DEVICES 1
 
// Create a LedControl object

LedControl lc = LedControl(12, 11, 10, NUM_DEVICES);
 
// Define the smiley face symbol

const byte smiley[8] PROGMEM = {

  B00111100,

  B01000010,

  B10100101,

  B10000001,

  B10100101,

  B10011001,

  B01000010,

  B00111100

};
 
void setup() {

  // Initialize the MAX7219

  lc.shutdown(0, false); // Wake up MAX7219

  lc.setIntensity(0, 8); // Set the brightness (0-15)

  lc.clearDisplay(0);    // Clear the display

}
 
void loop() {

  displaySymbol(smiley, 1000); // Display the smiley face for 1 second

  lc.clearDisplay(0);         // Clear the display

  delay(1000);                // Pause for 1 second

}
 
// Function to display a custom symbol

void displaySymbol(const byte symbol[], int duration) {

  for (int i = 0; i < 8; i++) {

    lc.setRow(0, i, pgm_read_byte(&symbol[i]));

  }

  delay(duration);

}
