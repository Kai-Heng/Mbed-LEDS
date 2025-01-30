#include "mbed.h"
#include <iostream>

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11

using namespace std;

// Define the Input pins
	//Write your code here
DigitalIn input1(BUTTON_1);
DigitalIn input2(BUTTON_2);
DigitalIn input3(BUTTON_3);
DigitalIn input4(BUTTON_4);



//Define the Output pins
	//Write your code here
DigitalOut red(RED_LED);
DigitalOut yellow(YELLOW_LED);
DigitalOut blue(BLUE_LED);


//Define Input/Output buses
	//Write your code here
BusIn bin(BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4);
BusOut bout(RED_LED,YELLOW_LED,BLUE_LED);


void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        // ControlLED_DigitalIO ();
        ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
        //Write your code here
        
        if(input1 == 1){
            if(input2 == 1){
                if(input3 == 1){
                    if(input4 == 1){
                        red = 1;
                        yellow = 1;
                        blue = 1;
                        cout << "All LEDs" << endl;
                    }
                    else{
                        blue = 1;
                        red = 0;
                        yellow = 0;
                        cout << "BLUE" << endl;
                    }
                }
                else{
                    blue = 1;
                    red = 0;
                    yellow = 0;
                    cout << "BLUE" << endl;

                }
            }
            else{
                red = 1;
                yellow = 1;
                blue = 0;
                cout << "RED & YELLOW" << endl;

            }
        }
        else{
            if(input2 == 1){
                if(input3 == 1){
                    red = 1;
                    yellow = 1;
                    blue = 0;
                    cout << "RED & YELLOW" << endl;
                }
                else{
                    yellow = 1;
                    blue = 0;
                    red = 0;
                    cout << "YELLOW" << endl;
                }
            }
            else{
                red = 1;
                blue = 0;
                yellow = 0;
                cout << "RED" << endl;
            }
        }
}

void ControlLED_BusIO (){
    //Write your code here
    
    if(bin[0] == 1){
        if(bin[1] == 1){
            if(bin[2] == 1){
                if(bin[3] == 1){
                    bout[0] = 1;
                    bout[1] = 1;
                    bout[2] = 1;
                    cout << "All LEDs" << endl;
                }
                else{
                    bout[2] = 1;
                    bout[0] = 0;
                    bout[1] = 0;
                    cout << "BLUE" << endl;
                }
            }
            else{
                bout[2] = 1;
                bout[0] = 0;
                bout[1] = 0;
                cout << "BLUE" << endl;

            }
        }
        else{
            bout[0] = 1;
            bout[1] = 1;
            bout[2] = 0;
            cout << "RED & YELLOW" << endl;

        }
    }
    else{
        if(bin[1] == 1){
            if(bin[2] == 1){
                bout[0] = 1;
                bout[1] = 1;
                bout[2] = 0;
                cout << "RED & YELLOW" << endl;
            }
            else{
                bout[1] = 1;
                bout[2] = 0;
                bout[0] = 0;
                cout << "YELLOW" << endl;
            }
        }
        else{
            bout[0] = 1;
            bout[2] = 0;
            bout[1] = 0;
            cout << "RED" << endl;
        }
    }
}
