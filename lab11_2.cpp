#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"}; // ต้องมี "" เพราะค่า array เริ่มจาก 0 เวลาแทนตำแหน่งจะได้ไม่สัน
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10}; // เพิ่มตัวเก็บค่าของ score int

int drawCard(void){
    return rand()%13+1; // คืนค่าตัวเลขที่แทนตำแหน่งไพ่ในสำรับแบบ 1 = "A", 11 = "J", 13 = "K"
} 

int calScore(int x,int y,int z){
    return (cardScores[x]+cardScores[y]+cardScores[z])%10; // ใช้หาเศษ 10 ไม่ได้มีอะไรซับซ้อนเลย
} // code เดิมจากข้อที่แล้วเอามาใช้ต่อ

int findYugiAction(int s){    
    if(s == 9) return 2; 
    else if(s < 6) return 1; 
    else{
        if(rand()%100+1 <= 69) return 1;
        else return 2;
    }
}

void checkWinner(int p, int y){
    cout << "\n---------------------------------\n";
    if(p > y )       cout <<   "|         Player wins!!!        |";
    else if( p == y) cout <<   "|             Draw!!!           |"; 
    else             cout <<   "|          Yugi wins!!!         |"; 
    cout << "\n---------------------------------\n";
}

int main(){	
    srand(time(0)); //This line of code is completed!

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; //This line of code is completed!
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2); //This line of code is completed!
	if(playerAction == 1){
		//The following lines of code are completed!
		
		playerCards[2] = drawCard();
        playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]); // คำนวนคะแนนผู้เล่น
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]]<<"\n"; // เพิ่มชื่อการ์ดให้ผู้เล่นเห็น
		cout << "Your new score: " << playerScore <<"\n"; // เพิ่มการสแดงคะแนนผู้เล่น
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are completed!
	
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n"; // เพิ่มการ์ดให้ยูกิจั่ว
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]); // คำนวนคะแนนการ์ดของยูกิ
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
	    
	    yugiCards[2] = drawCard(); //ให้โอกาสยูกิได้จั่วการ์ดใบที่ 2
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]); //เพิ่มคำนวนคะแนนยูกิ
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]]<<"\n"; // เพิ่มชื่อการ์ดให้ผู้เล่นเห็น
		cout << "Yugi's new score: " << yugiScore << "\n"; // เพิ่มการสแดงคะแนนยูกิ
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore); // แสดงผลผู้ชนะเปรียบเทียบคะแนนของ Player กับ Yugi
}