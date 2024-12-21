// จงเขียนโปรแกรมคุกกี้เสี่ยงไทร์ทำนายเกรดที่จะได้ในวิชานี้ ลงในไฟล์ lab11_1.cpp 
// โดยเกรดที่เป็นได้จะมี A, B+, B, C+, C, D+, D, F และ W 
// โดยเริ่มต้นโปรแกรมจะแสดงว่า “Press Enter 3 times to reveal your future.” 
// แล้วรอจนกว่าผู้ใช้จะกด Enter 3 ครั้ง แล้วจึงแสดงคำทำนายดังแสดงในตัวอย่างด้านล่างนี้

// cout << "Press Enter 3 times to reveal your future.";
// cout << "You will get A in this 261102.";


// Version 1

// #include <iostream> // For input and output
// #include <cstdlib>  // For rand() and srand()
// #include <ctime>    // เอาเวลามาใช้
// using namespace std;

// int main(){
//     cout << "Press Enter 3 times to reveal your future.";
//     for ( int i = 0 ; i < 3 ; i++ ){ // ลูป 3 รอบจะได้รับ Enter 3 ครั้ง!!
//         cin.get();
//     }
//     srand(time(0));
//     const char* grades[] = {"A","B+","B","C+","C","D+","D","F","W"};
//     const int numgrades = sizeof(grades)/ sizeof(grades[0]);
//     int randomIndex = rand() % numgrades;
//     cout << "You will get " << grades[randomIndex] <<" in this 261102.";
// }

// Version 2 รันไม่ผ่านเพราะ rand เขาไม่ได้รับค่าเป็น array 5555555 จบละเขียนตั้งนาน

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main() {
//     cout << "Press Enter 3 times to reveal your future.";
//     cin.ignore();
//     cin.ignore();
//     cin.ignore(); // กดข้ามครั้งที่ 3
//     srand(time(0)); // time คือ ค่าวินาทีของตัวฟังชั่นที่มากจากที่อื่น srand กำหนดค่า seed เริ่มต้นสุ่มให้  rand ถ้าไม่ใส่ rand มันจะเป็นแบบเดิม
//     const char* grades[] = {"A", "B+", "B", "C+", "C", "D+", "D", "F", "W"}; // const char* มีไว้เก็บข้อความ ok?
//     cout << "You will get " << grades[rand() % 9] << " in this 261102."; // grades[rand() % 9] เพื่อสร้างตัวแปรแบบสุ่มจาก 0-8 สำหรับการเลือกค่า grade จาก array
// }

// Version 3

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main(){
//     cout << "Press Enter 3 times to reveal your future.";
//     cin.get();
//     cin.get();
//     cin.get(); // เปลี่ยนเป็น get เพื่อให้กดแค่ enter ไม่ใช่ไม่สนใจทุกอย่าง 5555
    
//     srand(time(0));
//     int x = rand()%9;
//     if(x == 0) cout << "You will get A in this 261102.";
//     else if (x == 1) cout << "You will get B+ in this 261102.";
//     else if (x == 2) cout << "You will get B in this 261102.";
//     else if (x == 3) cout << "You will get C+ in this 261102.";
//     else if (x == 4) cout << "You will get C in this 261102.";
//     else if (x == 5) cout << "You will get D+ in this 261102.";
//     else if (x == 6) cout << "You will get D in this 261102.";
//     else if (x == 7) cout << "You will get F in this 261102.";
//     else cout << "You will get W in this 261102.";
    
// }

// // Version 4 อันนี้ลองเปลี่ยนไปใช้ case ดูว่ามันจะติดมั้ยแล้วก็ย่อไอ่ตรงประโยค You will get ? in this 261102. ด้วย

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main() {
//     cout << "Press Enter 3 times to reveal your future.";
//     cin.get(); cin.get(); cin.get(); // ทำให้กระชับ

//     srand(time(0));
//     string grade; // เปลี่ยนค่า grade ที่ได้เป็น string
//     switch (rand() % 9) {
//         case 0: grade = "A"; break; 
//         case 1: grade = "B+"; break;
//         case 2: grade = "B"; break;
//         case 3: grade = "C+"; break;
//         case 4: grade = "C"; break;
//         case 5: grade = "D+"; break;
//         case 6: grade = "D"; break;
//         case 7: grade = "F"; break;
//         case 8: grade = "W"; break;
//     }
//     cout << "You will get " << grade << " in this 261102.";
// }


// Version 5 555555555555 ละมันได้ด้วย

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "Press Enter 3 times to reveal your future.";
    cin.get(); cin.get(); cin.get();

    srand(time(0));
    int random = rand() % 9; // เหมือนๆเมื่อกี้แหละแค่เปลี่ยนวิธีเฉยๆ
    string grade = (random == 0) ? "A" :
                   (random == 1) ? "B+" :
                   (random == 2) ? "B" :
                   (random == 3) ? "C+" :
                   (random == 4) ? "C" :
                   (random == 5) ? "D+" :
                   (random == 6) ? "D" :
                   (random == 7) ? "F" : "W"; // นอกนั้นทั้งหมดคือ W แต่ก็มีแค่ 8 ป้ะถ้ามันไม่มีตัวหลุดมานะ 555
    cout << "You will get " << grade << " in this 261102.";
}
