#include <iostream>

using namespace std;

//STATE MACHINE. THE PROGRAM WANTS AS AN INPUT IN THE ARGUMENT THE LETTERS LOWERCASE
//WITH SPACES BETWEEN THEM

const int schema[][4] = {{2, 1, 3, -1},
												 {-1, 1, 3, -1},
												 {0, -1, -1, -1},
												 {-1, -1, -1, -1}};

int controllo_successivo(int statoattuale, int in){
	return schema[statoattuale][in];
	}

int main(int argc, char **argv)
{
	if (argc > 1){
		int stato = 0;
		int i = 0;
		while(true){
			int argcurr = (int) argv[i+1][0];
			int numero_lettera = argcurr - 'a';
			i++;
			stato = controllo_successivo(stato, numero_lettera);
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
	else{
		return -1;
	}
}
