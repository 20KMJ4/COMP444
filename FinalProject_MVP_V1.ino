//LCD Library
#include <LiquidCrystal.h>

//Initalize Pins
//Buttons
int blueButton = 22;
int greenButton = 23;

//LCD
LiquidCrystal lcd(26, 27, 30, 31, 34, 35);

//Ultrasonic
const int trigPin = 39;
const int echoPin = 38;

//Motor
const int AIN1 = 11;
const int AIN2 = 12;
const int PWMA = 13;

// Intialize variables
float currentCoins = 0.0;
float returnCoins = 0.0;
//Prices
float chipsCost = 2.5;
//stock
int chipsStock = 5;

bool bluePressed = false;


void setup() {
  //Inputs
  //Buttons
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);

  //Ultrasonic (input/output)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Outputs
  //LCD
  lcd.begin(16, 2);
  lcd.clear();

  //Motor
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop() {
  // Flip between two messages after X seconds when no selection has been made
  if (bluePressed == false && digitalRead(greenButton) == HIGH) {
    // Display a welcome message (top) and  loonies only (bottom)
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("1$ coins/bills");
    lcd.setCursor(2, 1);
    lcd.print("only please");

    //first message for 5 seconds
    delay(5000);
    lcd.clear();

    // Display message telling user to select an item, enter coins, then press green button to confirm and dispense item (scroll)
    lcd.setCursor(0, 0);
    lcd.print("Select item, insert coins, press green");
    lcd.setCursor(0, 1);
    lcd.print("button to confirm and dispense item.");

    delay(1000);

    //scroll to see full message
    for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(250);
    }

    delay(500);

    //go back to (0,0)
    lcd.home();

    delay(1000);

    //scroll to see full message again so bottom row can be read
    for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
      lcd.scrollDisplayLeft();
      delay(250);
    }
    delay(2000);
    lcd.clear();
  }

  //if green button is selected but no other button has been pressed
  if (bluePressed == false && digitalRead(greenButton) == LOW) {
    // Display must select an item
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("An item must be");
    lcd.setCursor(4, 1);
    lcd.print("Selected");
  }

  //if blue button is pressed and have item
  //Display selected: item name and the cost of the item

  //if blue button pressed and item is out of stock
  //Item is out of stock (top), select another item (bottom)

  //if a coin has been insterted (ultrasonic reading)
  //Display current amount

  //if enough money is entered and green button is pressed
  //internally track inventory
  //spin motor to dispense item
  //Display message saying item dispensing
  //Display amount of money returned (if applicable)
  //Display thank you have a nice day
}

//Dispense function to run motor
void dispense() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  analogWrite(PWMA, 50);
  //delay(); // stop motor after 1 cycle //Trial and error for getting proper time
  return;
}
