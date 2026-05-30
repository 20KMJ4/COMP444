//LCD Library
#include <LiquidCrystal.h>

//Initalize Pins
//Buttons
int blueButton = 22;
int greenButton = 23;

//LCD
LiquidCrystal lcd(26, 27, 30, 31, 34, 35);

//Ultrasonic
const int trigPin = 40;
const int echoPin = 38;

//Motor
const int AIN1 = 11;
const int AIN2 = 12;
const int PWMA = 13;

// Intialize variables
float currentCoins = 0.0;
float neededCoins = 0.0;
//Prices
float chipsCost = 3.0;
//stock
int chipsStock = 5;
int selectedItem = -1;

float distance = 0.0;

int state = 1;

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

  //For Troubleshooting
  Serial.begin(9600);
}

void loop() {
  //Serial.print(chipsStock);
  switch (state) {
    case 1:  // start message
      lcd.setCursor(0, 0);
      lcd.print("Select an item");
      if (digitalRead(blueButton) == LOW) {
        lcd.clear();
        state = 2;
      }
      break;
    case 2:  // blue button was pressed
      if (chipsStock > 0) {
        selectedItem = 1;  // chips selected
        //Display selected: item name and the cost of the item
        lcd.setCursor(0, 0);
        lcd.print("Item selected $3");
        lcd.setCursor(0, 1);
        lcd.print("Confirm?");
        neededCoins = chipsCost;
      } else {
        //if item is out of stock
        //Display item is out of stock (top), select another item (bottom)
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Out of stock");
        lcd.setCursor(0, 1);
        lcd.print("select new item");
      }
      if (selectedItem > 0 && digitalRead(greenButton) == LOW) {
        lcd.clear();
        state = 3;
      }
      break;
    case 3:
      distance = getDistance();
      Serial.println(distance);
      delay(300);
      //if a coin has been insterted (ultrasonic reading)
      if (distance <= 2) {
        currentCoins += 1;
      }
      if (currentCoins < neededCoins) {
        lcd.setCursor(0, 0);
        lcd.print("Need to add:");
        lcd.setCursor(0, 1);
        lcd.print("$");
        lcd.setCursor(1, 1);
        lcd.print(neededCoins - currentCoins);
      } else {
        lcd.setCursor(0, 0);
        lcd.print("push green but-");
        lcd.setCursor(0, 1);
        lcd.print("ton to confirm");
        if (digitalRead(greenButton) == LOW) {
          lcd.clear();
          state = 4;
          break;
        }
      }
        break;
        case 4:
          dispense();
          if (selectedItem == 1) {
            chipsStock -= 1;
          }
          currentCoins = 0;
          lcd.setCursor(0, 0);
          lcd.print("Thank you for");
          lcd.setCursor(0, 1);
          lcd.print("your purchase!");
          delay(3000);
          selectedItem = -1;
          state = 1;
          lcd.clear();
          break;
      }
  }



  //Dispense function to run motor
  void dispense() {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    analogWrite(PWMA, 100);
    delay(1000);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }

  float getDistance() {
    float echoTime;
    float calculatedDistance;

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    echoTime = pulseIn(echoPin, HIGH);
    calculatedDistance = echoTime / 148.0;
    return calculatedDistance;
  }
