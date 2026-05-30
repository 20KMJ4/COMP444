//LCD Library
#include <LiquidCrystal.h>

//Initalize Pins
//Buttons
int blueButton = 22;
int greenButton = 23;
int redButton = 42;
int yellowButton = 44;

//LCD
LiquidCrystal lcd(26, 27, 30, 31, 34, 35);

//Ultrasonic
const int trigPin = 40;
const int echoPin = 38;

long lastTime = 0;

//Motor
const int AIN1 = 11;
const int AIN2 = 12;
const int PWMA = 13;

// Intialize variables
float currentCoins = 0.0;
float neededCoins = 0.0;
//Prices
int cost[3] = { 3, 2, 5 };
//stock
int stock[3] = { 6, 12, 1 };
int selectedItem = -1;

const char* itemName[3] = { "Cola", "Lays", "Twix" };

float distance = 0.0;

int state = 1;

void setup() {
  //Inputs
  //Buttons
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);

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


  Serial.begin(9600);
}

void loop() {
  switch (state) {
    case 1:  // start message
      lcd.setCursor(0, 0);
      lcd.print("Select an item");
      if (digitalRead(redButton) == LOW || digitalRead(blueButton) == LOW || digitalRead(yellowButton) == LOW) {
        lcd.clear();
        state = 2;
      }
      break;

    case 2:  // Selection
      //if red button pressed
      if (digitalRead(redButton) == LOW) {
        selectedItem = 0;  // Cola selected
        lcd.clear();
      }
      //if blue button pressed
      if (digitalRead(blueButton) == LOW) {
        selectedItem = 1;  // Lays selected
        lcd.clear();
      }
      //if yellow button pressed
      if (digitalRead(yellowButton) == LOW) {
        selectedItem = 2;  // Twix selected
        lcd.clear();
      }

      if (stock[selectedItem] > 0) {
        //Display selected: item name and the cost of the item
        lcd.setCursor(0, 0);
        lcd.print(itemName[selectedItem]);
        lcd.setCursor(4, 0);
        lcd.print(" selected $");
        lcd.setCursor(15, 0);
        lcd.print(cost[selectedItem]);
        lcd.setCursor(0, 1);
        lcd.print("Confirm?");
        neededCoins = cost[selectedItem];
      } else {
        //if item is out of stock
        //Display item is out of stock (top), select another item (bottom)
        lcd.setCursor(0, 0);
        lcd.print("Out of stock    ");
        lcd.setCursor(0, 1);
        lcd.print("select new item");
      }
      if (selectedItem >= 0 && digitalRead(greenButton) == LOW) {
        lcd.clear();
        state = 3;
      }
      break;
    case 3:  // reading coins (ultrasonic)
      distance = getDistance();
      delay(300);

      //if a coin has been insterted (ultrasonic reading)
      if (distance <= 2) {
        currentCoins += 1;
      }
      if (currentCoins < neededCoins) {
        lcd.setCursor(0, 0);
        lcd.print("Balance: $");
        lcd.setCursor(11, 0);
        lcd.print(currentCoins);
        lcd.setCursor(0, 1);
        lcd.print("Add: $");
        lcd.setCursor(7, 1);
        lcd.print(neededCoins - currentCoins);
      } else {
        lcd.setCursor(0, 0);
        lcd.print("push green but-");
        lcd.setCursor(0, 1);
        lcd.print("ton to confirm  ");
        if (digitalRead(greenButton) == LOW) {
          lcd.clear();
          state = 4;
          break;
        }
      }
      break;
    case 4:
      dispense();
      stock[selectedItem] -= 1;
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

  analogWrite(PWMA, 35);  //35 at 165
  delay(165);             // stop motor after 1 cycle //Trial and error for getting proper time
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
