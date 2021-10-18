#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int generate_random_card();
void game();
int get_cards(int, string);
//int win(int, int);
int get_cards_house(int, string);
int generate_random_card_house();
//void lose_or_win(int);
int main() {
	//password
	cout << "Hello! Enter your user name and password!" << endl;

	string user_name{};
	cout << "Enter the user name: ";
	cin >> user_name;

	cout << "Enter your password: ";
	string password_1{};
	cin >> password_1;

	cout << "Repeat your password: ";
	string password_2{};
	cin >> password_2;

	int check_password{};
	int tries{ 2 };

	if (password_1 == password_2) {
		cout << "You are logged in." << endl;
	}
	else if (password_1 != password_2) {
	for (int check_password = 0; check_password < 3; check_password++) {

	cout << "You entered a wrong password. You have 2 chances to try again." << endl;
	cin >> password_2;

	check_password++;
	}
	}
     
	//BlackJack Game
	cout << "Hello! Welcome to the BlackJack!" << endl;
	char exit{};
    
	do {
		game();
		cout << " Do you want to continue? (Y/N)" << endl;
		cin >> exit;
		

		if (exit == 'N'||exit=='n') {
			cout << "The program will be terminated";
			break;
		}
	} while (exit == 'Y'||exit=='y');
}



      int generate_random_card_house() {
	srand(unsigned(time(0)));
	int a{ rand() % 12+1 };   //here I wrote 12+1 because if write like on line 13 the house will get the same point as person_1
	return a;
      }



      int generate_random_card() {  
	  srand(unsigned (time(0)));
	  int a{ rand() % 13 };
	 return a;
	  }

	  // //input and output of cards and points and shows who win
     void game() {
		 int money_person_1{ 100 }, fee_1{ 0 };
		 int money_house{ 100 }, fee_house{ 0 };
		 int win{ 0 }; //sum of the money from house and person_1, the winner will win the money
	  int person_1{0};//players points
	  int house{ 0 };//house points
	  
	  cout << "You and the house need to pay fee (minimum 10$).  Enter your sum $: ";
	  cin >> fee_1;

	  if (fee_1 <10) {
		  cout << "Hey! You need to pay for play! Enter the sum: ";
		  cin >> fee_1;
		  if (fee_1 < 10) {
			  cout << "I am not kidding, you need to pay: ";
			  cin >> fee_1;
		  }
		  if (fee_1 < 10) {
			  cout << "No, you are really kidding,  pay already!: ";
			  cin >> fee_1;
			  if (fee_1 >= 10) {
				  cout << "Oh, finally..." << endl;
			  }
		  }
	  }
      
	  fee_house = fee_1;
	  win = fee_1 + fee_house;

	  cout << "You paid " << fee_1 << " $. The hose paid " << fee_house << " $"<<endl;
      
	  person_1 = get_cards(1, " "); //first card 

	  cout << "You got " << person_1<<endl;
	  cout << "House's turn"<<endl;

	  house = get_cards_house(1, " ");

	  cout << "House got " << house << endl;

	  if (person_1 > 21) {
		  cout << "You lose!";
	  }
	  else if (person_1 == 21) {
		  cout << "You won!"<<"You got "<<win<<" $";
	  }

	  if(house>21){
		  cout << "House lose!" << house<<endl;
	  }
	  else if (house == 21) {
		  cout << "House won! You lose! House got "<<win<<" $";
	  }
	  else if (house > 21 && person_1 > 21) {
		  cout << "Hah, you both lose!";
	  }
	  }

	 //creates  random total points to the selected card
  int get_cards_house(int, string) {

	  int total_points_house{ 0 }; //total point that a person get
	  int loop{ 0 }; 
	  int take_a_card=rand()%10;  //the house can take card from 1 to 10
	 
	  cout << "House took  " << take_a_card << "  card."; //output of choose card

	  for (int loop = 0; loop <= 13; loop++) {       
		  generate_random_card_house();

		  total_points_house =loop + generate_random_card_house(); 

		  loop++;
	  }

	  return total_points_house;

  }

  //creates random total  point to the selected card
  int get_cards(int, string) {

	  int total_points{ 0 }; 
	  int loop_point{ 0 };   //integer that is used to create a loop and as an integer that used to create a total number by adding random card
	  int take_a_card{ 0 };

	  cout << "Take your card! ";
	  cin >> take_a_card;  //Player take a card from 1 to 10
	  cout << "You took " << take_a_card << " card."; //output of choose card

	  for (int loop_point = 0; loop_point <=13; loop_point++) {       //loop  where card are points from 1 to 13
		  generate_random_card();
		  if (generate_random_card() == 1 || generate_random_card() == 11) {
			  cout << "You have an ace! Do you want to keep the card as 1 or 11 points? (enter 1 or 11)" << endl;
			  int ace{ 0 };
			  cin >> ace;
			  if (int ace = 1) {
				  total_points = loop_point + 1;
			  }
			  else if (int ace = 11) {
				  total_points = loop_point + 11;
			  }
		  }
		  else 
		  { total_points = loop_point + generate_random_card(); }
		  loop_point++;
	  }
	       return total_points;
      }

