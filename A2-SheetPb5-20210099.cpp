#include <iostream>
#include <fstream>
#define SIZE 20

using namespace std;


class Universe{

    char arr[SIZE+2][SIZE+2];

public:

    void reset(){

        for(int i = 0 ; i <= SIZE+2 ; i++){

            for(int j = 0 ; j <= SIZE+2 ; j++){

                arr[i][j] = '0';
            }
        }
    }


//---------------------------------------------------------------
    void initialize(){

        reset();

        fstream File("GameOfLife.txt");

        string line;

        int j = 1;

        while (File >> line){

            for(int i = 1 ; i <= SIZE ; ++i ){

                arr[j][i] = line[i - 1];
            }

            j++;
        }
    }

//------------------------------------------------------
    int count_neighbors(int x , int y){

        int result = 0;

        if(arr[x][y] == '1'){

            result = -1;
        }

        for(int i = x-1 ; i <= x+1 ; i++){

            for(int j = y-1 ; j <= y+1 ; j++){

                if( arr[i][j] == '1'){

                    result++;
                }
            }

        }

        return result;

    }

//------------------------------------------------------
    void nextGeneration(){

        char arr2[SIZE+2][SIZE+2] = {{'0'}};

        for(int i = 1 ; i <= SIZE ; i++){

            for(int j = 1 ; j <= SIZE ; j++){

                int neighbors = count_neighbors(i ,j);

                if(arr[i][j] == '1' && (neighbors == 2 || neighbors == 3) ){

                    arr2[i][j] = '1';
                }

                else if(arr[i][j] == '0' && neighbors == 3){

                    arr2[i][j] = '1';
                }

                else{

                    arr2[i][j] = '0';
                }


            }
        }

        for(int i = 1 ; i <= SIZE ; i++){

            for(int j = 1 ; j <= SIZE ; j++ ){

                arr[i][j] = arr2[i][j];
            }
        }

    }

//-------------------------------------------------------------------
    void disPlay(){

        for(int i = 1 ; i <= SIZE ; i++) {

            for (int j = 1; j <= SIZE; j++) {

                cout << arr[i][j];
            }

            cout << endl;

        }

    }

//------------------------------------------------------------
    void run(int num){

        reset();
        initialize();

        for(int i = 0 ; i < num ; i++){

            cout << "\n-------------------------- ( " << i+1
                 << " \\ " << num << " ) --------------------------\n" ;


            nextGeneration();

            disPlay();

            system("pause");


        }

    }


};


int main() {

    Universe u ;



    u.initialize();

    u.run(3);

    return 0;
}
