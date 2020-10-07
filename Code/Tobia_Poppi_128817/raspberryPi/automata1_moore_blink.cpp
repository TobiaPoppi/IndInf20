#include <wiringPi.h>
#include <iostream>

using namespace std;

const int blue_led = 0; //GPIO 0
const int red_led = 1; //GPIO 1
const int yellow_led = 2; //GPIO 2
const int green_led = 3; //GPIO 3

const int sfn[][4] = {{2, 1, 3, -1},{-1, 1, 3, -1},{0, -1, -1, -1},{-1, -1, -1, -1}};
const int mfn[4] = {0, 2, 2, 3};

void init(){
  wiringPiSetup();
  //INIZIALIZZARE pinMode
  pinMode(blue_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void setOneLed(int ledNumber, bool value, int ledPrec){
    cout << "Setting led " << ledNumber << " to " << (value ? "ON" : "OFF") << endl;
    digitalWrite(ledPrec, !value);
    digitalWrite(ledNumber, value);
}

int main(){
  init();
  int state = 0;
  int state_prec = 0;
  char letter;
  while (stato < 3){
    setOneLed(mfn[state], true, mfn[state_prec]);
    cout << "Insert the symbol: " << endl;
    cin >> letter;
    int in = letter - 'a';
    state_prec = state;
    state = sfn[state][in];
    if (state < 0){
      goto error;
    }
    else if (state == 3){
      char k;
      digitalWrite(mfn[state_prec], false);
      digitalWrite(3, true);
      cout << "Input is legal :)\nWrite X to exit" << endl;
      cin >> k;
      while (k != "x"){
        cout << "that's not an option... :/" << endl;
        cin >> k;
      }
      return 0;
    }
  }
  error:
    digitalWrite(mfn[state_prec], false);
    digitalWrite(1, true);
    cout << "Error!!" << endl;
    cout << "Input not legal!\nWrite X to exit" << endl;
    cin >> k;
    while (k != "x"){
      cout << "that's not an option... :/" << endl;
      cin >> k;
    }
    return -1;
}
