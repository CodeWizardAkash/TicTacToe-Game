#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> table = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char take='x';
bool draw = false;
string p1 = "";
string p2 = "";

void function1(){
    cout<<"    |     |   \n";
    cout<<"  "<<table[0][0]<<" |  "<<table[0][1]<<"  | "<<table[0][2]<<" \n";
    cout<<"____|_____|____\n";
    cout<<"    |     |   \n";
    cout<<"  "<<table[1][0]<<" |  "<<table[1][1]<<"  | "<<table[1][2]<<" \n";
    cout<<"____|_____|____\n";
    cout<<"    |     |   \n";
    cout<<"  "<<table[2][0]<<" |  "<<table[2][1]<<"  | "<<table[2][2]<<" \n";
    cout<<"    |     |   \n";
}
void function2(){
    int digit;
    if(take=='x'){
        cout<<p1<<" Please Enter : ";
        cin>>digit;
    }
    if(take=='O'){
        cout<<p2<<" Please Enter : ";
        cin>>digit;
    }

    if(digit==1){
        row = 0;
        column = 0;
    }
    if(digit==2){
        row = 0;
        column = 1;
    }
    if(digit==3){
        row = 0;
        column = 2;
    }
    if(digit==4){
        row = 1;
        column = 0;
    }
    if(digit==5){
        row = 1;
        column = 1;
    }
    if(digit==6){
        row = 1;
        column = 2;
    }
    if(digit==7){
        row = 2;
        column = 0;
    }
    if(digit==8){
        row = 2;
        column = 1;
    }
    if(digit==9){
        row = 2;
        column = 2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid !!!"<<endl;
    }
    
    if(take=='x' && table[row][column]!='x' && table[row][column]!='O'){
        table[row][column] = 'x';
        take = 'O';
    }
    else if(take=='O' && table[row][column]!='x' && table[row][column]!='O'){
        table[row][column] = 'O';
        take = 'x';
    }
    else{
        cout<<"There is no empty space! \n";
        function2();
    }

}

bool function3(){
    for(int i=0;i<3;i++){
        if((table[i][0]==table[i][1] && table[i][0]==table[i][2]) || (table[0][i]==table[1][i] && table[0][i]==table[2][i])){
            return true;
        }
    }
    if((table[0][0]==table[1][1] && table[0][0]==table[2][2]) || (table[0][2]==table[1][1] && table[1][1]==table[2][0])){
        return true;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(table[i][j]!='x' && table[i][j]!='O'){
                return false;
            }
        }
    }
    draw = true;
    return draw;
}

int main(){
    cout<<"Enter the name of the first player : \n";
    cin>>p1;
    cout<<"Enter the name of the second player : \n";
    cin>>p2;
    cout<<p1<<" is palyer1 so he/she will play first \n";
    cout<<p2<<" is palyer2 so he/she will play second \n";
    while(!function3()){
        system("cls");
        function1();
        function2();
        function3();
    }
    system("cls");
    function1();
    if(take =='x' && draw == false){
        cout<<p2<<" wins!! \n";

    }
    if(take =='O' && draw == false){
        cout<<p1<<" wins!! \n";

    }
    else{
        cout<<"The match is draw! \n";
    }
    return 0;
}