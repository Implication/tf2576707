/* 
 * File:   main.cpp
 * Author: Trajon Fetlon
 * Created on July 24, 2014, 9:38 AM
 */

//System Defined Libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Defined Libraries
#include "Product.h"

//Global Constants


//Function Prototypes
short cntPerf(short x[]);
void getData( double array[12]);
double ttlRf(double array[12]);
double avgRf(double array[12]);
short dM(double array[12]);
short wM(double array[12]);
void report(double array[12]);

//Execution Begins Here
int main(int argc, char** argv) {
    char x; //Condition to do the problem again
    unsigned short prob; //Problem to do in the book
    do{
        cout << "Enter the problem you wish to see: " << endl;
        cin >> prob;
        switch(prob){
            case 1:{
                
                short scores[20]; //Array of scores
                short perf; //Takes in the number of perfect scores
                //Get the scores into the array.
                cout << "Enter twenty scores, and I will tell you how many are perfect scores: " << endl;
                for(short i = 0; i <= 19; i++){
                    cin >> scores[i];
                }
                //Get the number of perfect scores through function cntPerf
                perf = cntPerf(scores);
                //Enter the results
                cout << "The number of perfect scores enter is " << perf << "." << endl;
                //Exit case 1
                break;
            }
            case 2:{
                string roman[20] = { "I", "II", "III", "IV", "V",
                                     "VI", "VII", "VIII", "IX", "X",
                                     "XI", "XII", "XIII", "XIV", "XV",
                                     "XVI", "XVII", "XVIII", "XIX", "XX" };
                float num;
                cout << "Enter the number you wish to convert. **Note all number will be rounded down**" << endl;
                cin >> num;
                for(short b = 0; b <= 19; b++){
                    if(b + 1 <= num && num < b + 2){
                        cout << roman[b] << endl;
                    } 
                }
                break;
            }
            case 3:{
                string salsa[5] = {"mild", "medium", "sweet", "hot", "zesty" };
                short jars[5];
                short total;
                short high = 0;
                string name1, name2;
               
                for(short x = 0; x <= 4; x++){
                    cout << "Enter the number of jars sold that were " << salsa[x] << endl;
                    cin >> jars[x];
                } 
                short low = jars[0];
                for(short x = 0; x <= 4; x++){
                    cout << "Number of jars sold that were " << salsa[x] << ": "  << jars[x] << endl;
                    total += jars[x];
                    if (high < jars[x]){
                        high = jars[x];
                        name1 = salsa[x];
                    }
                    if (low > jars[x]){
                        low = jars[x];
                        name2 = salsa[x];
                    }
                }
                cout << endl;
                cout << "The total number of sales made in terms of jars is " << total << endl;
                cout << "The highest number  of sales was made by " << name1 << " salsa which sold " << high << " jars." << endl;
                cout << "The lowest number of sales was made by " << name2 << " salsa  which sold " << low << " jars." << endl;
                break;
            }
            case 4:{
                string monkey[3] = { "Sal", "Eric", "June"};
                string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
                short pound[3][7];
                short high = 0;
                short total = 0;
                string m1, d1, m2, d2;
                for(short x = 0; x <= 2; x++){
                    for(short y = 0; y <= 6; y++){
                        cout << "How many pounds did " << monkey[x] << " eat on " << day[y] << "? ";
                        cin >> pound[x][y];
                    }
                }
                short low = pound[0][0];
                for(short x = 0; x <= 2; x++){
                    for(short y = 0; y <= 6; y++){
                      total +=  pound[x][y];
                      if(high < pound[x][y]){
                          high = pound[x][y];
                          m1 = monkey[x];
                          d1 = day[y];
                      }
                      if(low > pound[x][y]){
                          low = pound[x][y];
                          m2 = monkey[x];
                          d2 = day[y];
                      }
                    }
                }
                    total /= 21;
                    cout << "Average amount of food eaten by every monkey was " << total << " pounds." << endl;
                    cout << "Highest amount of food eaten by " << m1 << " on a " << d1 << " with a total of " << high << " pounds." << endl;
                    cout << "Lowest amount of food eaten by " << m2 << " on a " << d2 << " with a total of " << low << " pounds." << endl;
                    break;
            }
            case 5:{
                char data[3][30];
                ifstream file;
                short totalR = 0;
                short totalC = 0;
                short totalS = 0;
                short July=0;
                short June=0;
                short Aug=0;
                file.open ("RainorShine.dat");
                
                for(short x = 0; x <= 2; x++){
                    for(short y = 0; y <= 29; y++){
                        file >> data[x][y];
                        if(data[x][y] == 'R'){
                            totalR++;
                        }
                        else if(data[x][y] == 'S'){
                            totalS++;
                        }
                        else{
                            totalC++;
                        }
                    }
                }
                for(short x = 0; x <=2; x++){
                    for(short y = 0; y <= 29; y++){
                        switch(x){
                            case 0:{
                                if(data[x][y] == 'R') June++;
                            }
                            case 1:{
                                if(data[x][y] == 'R') July++;
                            }
                            case 2:{
                                if(data[x][y] == 'R') Aug++;
                            }
                        }
                    }
                }
                cout << "Total number of sunny days: " << totalS << endl;
                cout << "Total number of cloudy days: " << totalC << endl;
                cout << "Total number of rainy days: " << totalR << endl;
                if(June > July && June > Aug){
                    cout << "June has the most amount of rainy days" << endl;
                }
                else if(July > June && July > Aug){
                    cout << "July has the most amount of rainy days" << endl;
                }
                else{
                    cout << "August has the most amount of rainy days" << endl;
                }
                break;
            }
            case 6:{
                unsigned short seed;
                seed = time(0);
                srand(seed);
                short dig[5] = {rand() % 10 + 0,rand() % 10 + 0,rand() % 10 + 0,rand() % 10 + 0, rand() % 10 + 0};
                short player[5];
                short count = 0;
                cout << "Enter 5 single digit numbers: " << endl;
                for(short x = 0; x <= 4; x++){
                    cin >> player[x];
                    while(player[x] < 0 || player[x] > 9){
                        cout << "Enter a signle digit number" << endl;
                        cin >> player[x];
                    }
                    if(player[x] == dig[x]){
                        count++;
                    }                  
                }
                cout << "The winning numbers was ";
                for(short x = 0; x <= 4; x++){
                    cout << dig[x];
                }
                cout << endl;
                cout << "You matched " << count << " digits." << endl;
                break;
            }
            case 7:{
                double a[12];
                report(a);
                break;
            }
            case 8:{
                Product j[5];
                
                cout << "Enter the names of the 5 Products followed by the amount it sold" << endl;
                for(short x = 0; x <=4; x++){
                    
                }
            }
            default:{
                cout << "There are only 10 problems! Please restart the loop" << endl;
                break;
            }
        }
        cout << "Do another problem? Y/N" << endl;
        cin >> x;
    }while(x == 'Y' || x == 'y');
    
    
    
    return 0;
}

short cntPerf(short x[]){
    short count = 0;
    for(short i = 0; i <= 19; i++){
        if(x[i] == 100){
            count++;
        }
    }
    return count;
}
void getData(double array[12]){
    cout << "Enter the total rainfall for all 12 months. When done entering 1 month, press enter." << endl;
    for(short x = 0; x <= 11; x++){
        cin >> array[x];
    }
}

double ttlRf(double array[12]){
    double total = 0;
    for(short x = 0; x <= 11; x++){
        total += array[x];
    }
    return total;
}
double avgRf(double array[12]){
    double avg = 0;
      for(short x = 0; x <= 11; x++){
          avg += array[x];
      }
    avg /= 12;
    return avg;
}

short dM(double array[12]){
    short num = 0;
      for(short x = 0; x <= 10; x++){
          if(array[x] < array[x+1]){
              num = x;
          }
          else{
              num = x + 1;
          }
      }
    return num;
}
short wM(double array[12]){
      short num = 0;
      for(short x = 0; x <= 10; x++){
          if(array[x] > array[x+1]){
              num = x;
          }
          else{
              num = x + 1;
          }
      }
      return num;
}

void report(double array[12]){
    string month[12] = {"January" , "February", "March", "April", "May", "June" 
                        "July", "August", "September", "October", "November", "December" };
    getData(array);
    double total = ttlRf(array);
    double avg = avgRf(array);
    short d = dM(array);
    short w = wM(array);
    
    cout << "2010 Rain Report for Neversnows County" << endl << endl;
    cout << setprecision(2) << showpoint << fixed << "Total rainfall: " << total << " inches." << endl;
    cout << "Average monthly rainfall " << avg << " inches" << endl;
    cout << "The least rain fell in " << month[d] << " with " << array[d] << " inches" << endl;
    cout << "The most rain fell in " << month[w] << " with " << array[w] << " inches" <<  endl;
}