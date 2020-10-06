#include <wiringPi.h>
#include <iostream>

using namespace std;

const int blue_led = 0; //GPIO 0
const int red_led = 1; //GPIO 1
const int yellow_led = 2; //GPIO 2
const int green_led = 3; //GPIO 3

void init(){
  wiringPiSetup();
  //INIZIALIZZARE pinMode
}

int main(){
  init();
  
  int letter;
  cout << "Insert the symbol: " << endl;
  cin >> letter;
  letter = letter - 'a';

}
