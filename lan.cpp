/*


			 ____ _____  ____ _ __  __  ___
			|  _ \___ / / ___/ |  \/  |( _ )
			| | | ||_ \| |   | | |\/| |/ _ \
			| |_| |__) | |___| | |  | | (_) |
			|____/____/ \____|_|_|  |_|\___/
						DECIMATE
				a language of numbers
				
				
Woah! you are reading the source code!
that is a bad idea, no comments spaghetti code
good luck, if you find any bugs, i dont really care
it is probably riddled with them, i wrote this in a day
:sunglasses:

*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char** args){
//cout << args[1] << '\n';
int nums[] = {0,1,2,3,4,5,6,7,8,9};
short numbuffer=0;
short bufferlen = 0;
char currentc;
char before;
short mode = 0;	
short operat;
int repns = 0;
bool reppn = false;
char repbuf[256];  
short repbufpt = 0;
ifstream scrip (args[1]);
if(scrip.is_open()){

	while((reppn && mode != 2)|| scrip.get(currentc)){
		if((reppn && mode != 2)){
				currentc = repbuf[repbufpt];
				repbufpt++;
					
			}
	switch(mode){
		case 0:
			mode = 1;
			numbuffer=0;
			switch(currentc){
				case '=':
					operat = 0;
				break;
				case '+':
					operat = 1;
				break;
				case '-':
					operat = 2;
				break;
				case 'n':
					operat=10;
				break;
				case 'a':
					operat=11;
				break;
				case 'b':
					operat=12;
				break;
				case 'i':
					operat=13;
				break;
				case '/':
					mode = -1;
				break;
				case ':':
					if(!reppn){
						mode=2;
						repns=before;
						reppn = true;
					}
					else{
						mode = 0;
						nums[repns]--;
						if(nums[repns] <=0){
							reppn = false;
						}
					}
					repbufpt = 0;
					
				break;
				default:
					if(currentc >=48 && currentc <=57){
						before = currentc-48;
					}
					mode = 0;
			}
			
		break;
		case 1:
			
			if(currentc >=48 && currentc <=57){
				numbuffer*=10;
				numbuffer+=nums[currentc-48];
			}
			else if(currentc == '|'){
					mode = 0;


				switch(operat){
					case 0:
						nums[before]=numbuffer;
						
					break;
					case 1:
						nums[before]+=numbuffer;
						
					break;
					case 2:
						nums[before]-=numbuffer;
						
					break;
					case 10:
						cout << numbuffer;
						
					break;
					case 11:
						cout << (char)numbuffer;
						
					break;
					case 12:
						for(int i=0;i<10;i++){
							cout << nums[i] << '\t';
						}
					break;
					case 13:
						int a;
						int b=0;
						cin >> a;
						for(int i=0;i<(int)log10((float)a)+1;i++){
							b+=nums[(((int)(a/pow(10,i))) % (int)pow(10,i+1))]*pow(10,i);
						}
						nums[before]=b;
					break;

				}
			}

		break;
		case 2:
			if(currentc != ':'){
				repbuf[repbufpt] = currentc;
				repbufpt++;
			}else{
				repbuf[repbufpt] = currentc;
				repbufpt=0;
				mode = 0;
				
			}
		break;
		case -1:
			if(currentc == '/')
				mode=0;
		break;
	}
	}
	scrip.close();
}
else{cout << "file not found \n";}
return 0;
}
