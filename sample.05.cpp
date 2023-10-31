#include <iostream>
using namespace std;

const int MaxX = 10;
const int MaxY = 10;

void Up(void);
void Down(void);
void Left(void);
void Right(void);
void Position(void);
void Show(void);
void reset(void);

int Px;
int Py;
void reset(void);
int there[10][10], sharpX[5], sharpY[5];

int main(void) {

	char c;

	Px = 5;
	Py = 5;
	reset();
	Position();
	Show();

	while (1) {

		cin >> c;

		if (c == 'q') {
			break;
		}

		switch (c) {
			case 'w':
				Up();
				break;

            case 'a':
                Left();
                break;
            
            case 'd':
                Right();
                break;

            case 's':
                Down();
                break;
		}
		reset();
		Position();
		Show();
	}
	return 0;
}

void Up(void) {
	if (Py < 1) return;
	cout << "上に進む" << endl;
	Py = Py - 1;
}
void Down(void){
    if(Py > 8)return;
    cout << "下に進む"<< endl;
    Py += 1;
}
void Left(void){
    if(Px < 1) return;
    cout << "左に進む" << endl;
    Px -= 1;
}
void Right(void){
    if(Px > 8)return;
    cout << "右に進む" << endl;
    Px += 1;
}

void reset(void){
	for (int y = 0; y < MaxY; y ++) {
		for (int x = 0; x < MaxX; x ++) {
			there[y][x] = 0;
		}
	}
}

void Position(void) {

	cout << "X =" << Px << ",";
	cout << "Y =" << Py << endl;

	for (int y = 0; y < MaxY; y ++) {
		for (int x = 0; x < MaxX; x ++) {
			if ((x == Px) && (y == Py)) {

				for ( int a = 0 ; a < 4 ; a++){
					sharpX[a] = sharpX[a + 1];
					sharpY[a] = sharpY[a + 1];
				}
				there[y][x] = 2;
				sharpX[0] = x;
				sharpY[0] = y;
			} 
		}
	}
}

void Show(){

	for (int a = 1 ; a < 5 ; a++){
		there[sharpY[a]][sharpX[a]] = 1;
	}

	for ( int y = 0 ; y < MaxY ; y++){
		for ( int x = 0 ; x < MaxX ; x++){
			if ( there[y][x] == 2){ cout << "*"; }
			else if(there[y][x] == 1) { cout << "#"; }
			else { cout << "-"; }
		}
		cout << endl;
	}
}