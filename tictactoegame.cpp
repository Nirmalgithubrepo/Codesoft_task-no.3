#include<iostream>
using namespace std;

char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col,i,j;
int num;
char turn='x';
bool tie=false;
string n1=" ";
string n2=" ";
char again;

void board(){
    cout<<"player 1[x]\n player 2[o]\n";
    cout<<"\t      |      |     \n";
    cout<<"\t  "<<a[0][0]<<"   | "<<a[0][1]<<"    | "<<a[0][2]<<"\n";
    cout<<"\t  ____|______|____ \n";
    cout<<"\t      |      |     \n";
    cout<<"\t  "<<a[1][0]<<"   | "<<a[1][1]<<"    | "<<a[1][2]<<"\n";
    cout<<"\t  ____|______|____ \n";
    cout<<"\t      |      |     \n";
    cout<<"\t  "<<a[2][0]<<"   | "<<a[2][1]<<"    | "<<a[2][2]<<"\n";
    cout<<"\t      |      |     \n";
    cout<<endl;
}
void playerTurn(){

    if(turn=='x'){
        cout<<n1<<" :-player 1.. please Enter: ";
        cin>>num;
        cout<<endl;
    }
    else if(turn=='o'){
         cout<<n2<<" :-player 2.. please Enter: ";
        cin>>num;
        cout<<endl;
    }
    switch(num){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
        cout<<"sorry!.. you Entered wrong number.";
    }
    if(turn=='x' && a[row][col]!='x' && a[row][col]!='o'){
        a[row][col]='x';
        turn='o';
    }
    else if(turn=='o' && a[row][col]!='x' && a[row][col]!='o'){
         a[row][col]='o';
        turn='x';
    }
    else{
        cout<<"There is no empty space!!\n";
        playerTurn();
    }
}

bool checkwin(){
    for(int i=0;i<3;i++){
        if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][0] && a[0][i]==a[2][i]){
            return true;
        }
         if(a[0][0]==a[1][1] && a[1][1]==a[2][2] || a[0][2]==a[1][1] && a[1][1]==a[2][0]){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]!='x' && a[i][j]!='o'){
                return false;
            }
        }
    }
    tie=false;
    return true;
}

int main(){
    while(again!='N'){
        cout<<"\n\t\t\t   *WELCOME TO THE TIC TAC TOE GAME!*   "<<endl;

        cout<<"Enter the name of the first player: ";
        cin>>n1;
        cout<<"Enter the name of second player: ";
        cin>>n2;
        cout<<n1<<" is the first player so he/she will play first."<<endl;
        cout<<n2<<" is the second player so he/she will play second."<<endl;


        while(!checkwin() && again!='N'){
            board();
            playerTurn();
            checkwin();
        }
        if(turn=='x' && tie==false){
            cout<<"\n CONGRATS! player 2 wins the game."<<endl;
            cout<<"want to play again? (enter Y for yes and N for no.)";
            cin>>again;
        }
        else if(turn=='o' && tie==false){
            cout<<"\n CONGRATS! player 1 wins the game."<<endl;
            cout<<"want to play again? (enter Y for yes and N for no.)";
            cin>>again;
        }
        else{
            cout<<"game draw"<<endl;
            cout<<"want to play again? (enter Y for yes and N for no.)";
            cin>>again; 
        }

    }
    return 0;
}