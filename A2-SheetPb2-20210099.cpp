#include <iostream>
#include <fstream>

using namespace std;

class LabelGenerator{

    string label ;
     int number;

public:

    LabelGenerator(){} ;
    LabelGenerator(string label , int number){

        this -> label = label;

        this -> number = number;
    }


    string getLabel(){

        return label;
    }
    virtual string nextLabel(){

        string str;

        number++;

        str = label + " ";
        str += to_string(number);

        return str;
    }
};

class FileLabelGenerator:public LabelGenerator{

    string labelText;
    int Label_number ;
    fstream file ;

public:

    FileLabelGenerator(string label , int number , string labelText): LabelGenerator(label , number) {

        Label_number = number ;
        this->labelText = labelText;
        file.open(labelText);
    }

    string nextLabel() override{

        string line , str1;

        getline(file , line);

        Label_number++ ;

        str1 = getLabel() + " ";
        str1 += to_string(Label_number) + " ";
        str1 += line;

        return str1;
    }
};




int main() {

    LabelGenerator figureNumbers("Figure", 0);

    LabelGenerator pointNumbers("P", 0);

    cout << "Figure Numbers: " << " " ;

    for (int i = 0; i < 3; i++) {

        cout << figureNumbers.nextLabel() << " , ";
    }

    cout << '\n' << "Point Numbers: " << " ";

    for (int i = 0; i < 3; i++) {

        cout << pointNumbers.nextLabel() << " , ";
    }

    cout << '\n' << "More Figures: " << " ";

    for(int i = 0 ; i < 3 ; i++){

        cout << figureNumbers.nextLabel() << " , ";
    }

    cout << endl;

    FileLabelGenerator figuresLabels("figure", 0, "toqa.txt");

    cout << "\nFigure labels: \n";

    for (int i = 0; i < 3; i++) {

        cout << figuresLabels.nextLabel() << endl;

    }
    return 0;
}