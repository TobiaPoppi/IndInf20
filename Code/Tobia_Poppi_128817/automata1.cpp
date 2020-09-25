#include <iostream>

using namespace std;

const int inputs_size = 2;
const char inputs[] = {'b', 'c'};
//const int inputs_size = 4;
//const char inputs[] = {'a', 'a', 'b', 'c'};

char next()
{
	static int i = 0;
	cout << i << endl;
	cout << inputs[i] << endl;
	return inputs[i++];
}

int controllo_successivo(int statoattuale, char in){
	switch(statoattuale){
			case 0:
				if (in == 'a'){
					return 2;
					}
				else if (in == 'b'){
					return 1;
					}
				else if (in == 'c'){
					return 3;
					}
				else {
					return -2;
					}
			case 1:
				if (in == 'b'){
					return 1;
					}
				else if (in == 'c'){
					return 3;
					}
				else {
					return -2;
					}
			case 2:
				if (in == 'a'){
					return 0;
					}
				else {
					return -2;
					}
			case 3:
				return -2;
		}
	return 0;	
	}

int main()
{
	int stato = 0;
	while(true){
		char a = next();
		cout << a << endl;
		stato = controllo_successivo(stato, a);
		if (stato < 0){
			goto error;
			break;
			}
		else if (stato == 3){
			cout << "Input is legal :)" << endl;
			return 0;
			}
		
	}
	return 0;
	error:	
		cout << "Error!!" << endl;
		cout << "Input not legal!" << endl;
		return -1; 
}
