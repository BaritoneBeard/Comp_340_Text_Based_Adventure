#include "Games.h"
Games::Games()
{
	this->win = false;
}
/*This method plays 'Rock, paper, scissors.'  The enemy has a vector of the three options that are shuffled each turn.  The enemy's choice is the top 
index of the vector.  Several if/else statements are used to determine the winner. 
*/
void Games::rockPaperScissors() {
	enemyRockChoice.push_back("ROCK");
	enemyRockChoice.push_back("PAPER");
	enemyRockChoice.push_back("SCISSORS");
	
	std::string choice;
	std::string endGame;
	std::string randChoice;

	std::cout << "\nHere's how ya play:  Paper covers rock, rock crushes scissors, and scissors cuts paper.  Got it?" << std::endl;
	std::getline(std::cin, endGame);

	while (endGame == "YES") {
		std::cout << "\nOkay.  Let's play!! Rock, Paper, Scissors, Shoot!\n(Enter 'ROCK', 'PAPER' or 'SCISSORS')" << std::endl;
		std::getline(std::cin, choice);

		srand(time(NULL));
		int randomNum = rand() % 100;
		for (int i = 0; i <= randomNum; i++); {
			std::random_shuffle(enemyRockChoice.begin(), enemyRockChoice.end());
		}

		if (choice == "ROCK" && enemyRockChoice[0] == "SCISSORS") {
			std::cout << "\nGosh darn it! I chose " + enemyRockChoice[0] + ". Rock crushes scissors, you beat me!" << std::endl;
			win = true;
			break;
		}
		else if (choice == "ROCK" && enemyRockChoice[0] == "PAPER") {
			std::cout << "\nHAHA!! I chose " + enemyRockChoice[0] + ". Paper covers rock! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (choice == "PAPER" && enemyRockChoice[0] == "ROCK") {
			std::cout << "\nGosh darn it! I chose " + enemyRockChoice[0] + ". Paper covers rock, you beat me!" << std::endl;
			win = true;
			break;
		}
		else if (choice == "PAPER" && enemyRockChoice[0] == "SCISSORS") {
			std::cout << "\nHAHA!! I chose " + enemyRockChoice[0] + ". Scissors cuts paper! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (choice == "SCISSORS" && enemyRockChoice[0] == "PAPER") {
			std::cout << "\nGosh darn it! I chose " + enemyRockChoice[0] + ". Scissors cuts paper, you beat me!" << std::endl;
			win = true;
			break;
		}
		else if (choice == "SCISSORS" && enemyRockChoice[0] == "ROCK") {
			std::cout << "\nHAHA!! I chose " + enemyRockChoice[0] + ". Rock crushes scissors! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (choice == enemyRockChoice[0]) {
			std::cout << "\nAw man!  We both picked " + enemyRockChoice[0] + "!  Let's try this again.  Sound good?" << std::endl;
			std::getline(std::cin, endGame);
		}
		else {
			std::cout << "\nDoncha listen?  I said 'ROCK', 'PAPER' or 'SCISSORS'! Wanna try that again? " << std::endl;
			std::getline(std::cin, endGame);
		}
	}
	playerWins();
}
/*This method is the rigged "rock, paper, scissors." It takes the users input and generates the appropriate response to beat the game using if/else
statements.  The user must play this game 5 times in order for the normal method to be called.*/
void Games::riggedRockPaperScissors() {

	std::string choice;
	std::string enemyChoice;
	std::string endGame;

	std::cout << "\nHere's how ya play:  Paper covers rock, rock crushes scissors, and scissors cuts paper.  Got it?" << std::endl;
	std::getline(std::cin, endGame);

	while (endGame == "YES") {
		std::cout << "\nOkay.  Let's play!! Rock, Paper, Scissors, Shoot!\n(Enter 'ROCK', 'PAPER' or 'SCISSORS')" << std::endl;
		std::getline(std::cin, choice);

		if (choice == "ROCK") {
			riggedCounterOne();
			if (getCountOne() == 5) {
				break;
			}
			std::cout << "\nHAHA!! I chose paper. Paper covers rock! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			break;
		}
		else if (choice == "PAPER") {
			riggedCounterOne();
			if (getCountOne() == 5) {
				break;
			}
			std::cout << "\nHAHA!! I chose scissors. Scissors cuts paper! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			break;
		}
		else if (choice == "SCISSORS") {
			riggedCounterOne();
			if (getCountOne() == 5) {
				break;
			}
			std::cout << "\nHAHA!! I chose rock. Rock crushes scissors! I WIN!!! Told ya you couldn't beat me!  \n Care to try again? " << std::endl;
			break;
		}
		else {
			std::cout << "\nDoncha listen?  I said 'ROCK', 'PAPER' or 'SCISSORS'! Wanna try that again? " << std::endl;
			std::getline(std::cin, endGame);
		}
	}
}
/*This method plays 'How many fingers am I holding up?'  The enemy has a vector of numbers 1-5 that are shuffled each turn.  The enemy's choice is the top
index of the vector.  If/else statements are used to determine the winner.
*/
void Games::fingers() {
	std::string option;
	int choice;
	std::cout << "\nHey there!  Wanna beat me?  You'll have to win first!  My hand is behind my back holding up fingers.  Guess the right amount and you win.  If you don't, you might just get a knuckle sandwich!  Got it?" << std::endl;
	std::getline(std::cin, option);

	while (option =="YES") {
		srand(time(NULL));
		int randomNum = rand() % 5 + 1;
		std::cout << "\nGo ahead.  Make your guess!  How many fingers am I holding up?" << std::endl;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == randomNum) {
			std::cout << "\nYou won this time!  Next time it's a sandwich for you!" << std::endl;
			win = true;
			break;
		}
		else {
			std::cout << "\nHEHEHE I have " << randomNum << " fingers!  You chose wrong and I win!!! \n Wanna give it another try?" << std::endl;
			std::getline(std::cin, option);
		}
	}
	playerWins();
}

/*This method is the rigged "How many fingers am I holding up?" It takes the users input and generates the appropriate response to beat the game using if/else
statements.  The user must play this game 5 times in order for the normal method to be called.*/
void Games::riggedFingers() {
	std::string option;
	int choice;
	std::cout << "\nHey there!  Wanna beat me?  You'll have to win first!  My hand is behind my back holding up fingers.  Guess the right amount and you win.  If you don't, you might just get a knuckle sandwich!  Got it?" << std::endl;
	std::getline(std::cin, option);

	while (option =="YES") {
		srand(time(NULL));
		int randomNum = rand() % 5 + 1;
		std::cout << "\nGo ahead.  Make your guess!  How many fingers am I holding up?" << std::endl;
		std::cin >> choice;
		std::cin.ignore();

		if (choice == randomNum && randomNum <5) {
			randomNum = randomNum + 1;
			riggedCounterTwo();
			if (getCountTwo() == 5) {
				break;
			}
			std::cout << "\nHEHEHE I have " << randomNum << " fingers!  You chose wrong and I win!!! \n Wanna give it another try?" << std::endl;
			std::getline(std::cin, option);
		}
		else if (choice == randomNum && randomNum == 5) {
			randomNum = randomNum - 2;
			riggedCounterTwo();
			if (getCountTwo() == 5) {
				break;
			}
			std::cout << "\nHEHEHE I have " << randomNum << " fingers!  You chose wrong and I win!!! \n Wanna give it another try?" << std::endl;
			std::getline(std::cin, option);
		}
		else {
			std::cout << "\nHEHEHE I have " << randomNum << " fingers!  You chose wrong and I win!!! \n Wanna give it another try?" << std::endl;
			riggedCounterTwo();
			if (getCountTwo() == 5) {
				break;
			}
			std::getline(std::cin, option);
		}
	}
}

//This method simulates rolling dice by pushing numbers 1-6 to a vector, shuffling the vector, then choosing the top index.
void Games::diceRoll() {
	diceChoice.push_back(1);
	diceChoice.push_back(2);
	diceChoice.push_back(3);
	diceChoice.push_back(4);
	diceChoice.push_back(5);
	diceChoice.push_back(6);

	srand(time(NULL));
	int randomNum = rand() % 10; //NOTE: Wouldn't this need to be %6 to ensure that an 8 isn't called for a 6-sided die? (Array out of bounds)
	for (int i = 0; i <= randomNum; i++); {
		std::random_shuffle(diceChoice.begin(), diceChoice.end());
	}
}
//This method allows a player to continue rolling the die until they reach a sum of 10 or higher.  If they choose to pass, the enemy has the opportunity to roll.
//The method uses several if/else statements to determine the winner. 
bool Games::diceGame() {
	std::string choice;
	int playerSum = 0;
	int bullySum = 0;

	std::cout << "\nLet's play my dice game!  Here are the rules: \n1. Roll the dice as many times you want. \n2. Aim for the number 10. \n3. If you go over you lose. \n4. You get 10 exactly you win. \n5. You get less than 10 but are higher than me, you win!\n" << std::endl;
	std::cout << "\nGot it?  Let's begin! \n'ROLL' or 'PASS'?" << std::endl;
	std::getline(std::cin, choice);

	while (choice != "PASS") {
		diceRoll();
		playerSum = playerSum + diceChoice[0];
		std::cout << "\nYou rolled " << diceChoice[0] << std::endl;

		if (playerSum > 10) {
			std::cout << "\nYou have " << playerSum << " You bust! You lose!" << std::endl;
			break;
		}
		else if (playerSum < 10) {
			std::cout << "\nYou have " << playerSum << ". 'ROLL' or 'PASS'" << std::endl;
			std::getline(std::cin, choice);
		}
		else if (playerSum == 10) {
			std::cout << "\nYou got 10! You win!!" << std::endl;
			this-> win = true;
			break;
		}
		else {
			std::cout << "\n'ROLL' or 'PASS'?" << std::endl;
			std::getline(std::cin, choice);
		}
	}
	if (playerSum < 10) {
		while (bullySum < 7) {
			diceRoll();
			bullySum = bullySum + diceChoice[0];
			std::cout << "\nI rolled " << diceChoice[0] << std::endl;
		}
		std::cout << "\nYour score: " << playerSum << "\nMy score: " << bullySum << std::endl;
		if (bullySum > 10) {
			std::cout << "\nUgh I bust. You won this time." << std::endl;
			this->win = true;
		}
		else if (bullySum == 10) {
			std::cout << "\nHAHA I WIN!!!" << std::endl;
		}
		else if (playerSum > bullySum) {
			std::cout << "\nUgh. You won this time." << std::endl;
			this-> win = true;
		}
		else if (playerSum < bullySum) {
			std::cout << "\nHAHA I WIN!!!" << std::endl;
		}
		else {
			std::cout << "\nWe tied...no one wins this time." << std::endl;
		}
	}
	return playerWins();
}

//This method is the rigged version of the dice game.  The player will win if they roll a 10, however the enemy will always roll a 10.
void Games::riggedDice() {
	std::string choice;
	int playerSum = 0;
	int bullySum = 0;

	std::cout << "\nLet's play my dice game!  Here are the rules: \n1. Roll the dice as many times you want. \n2. Aim for the number 10. \n3. If you go over you lose. \n4. You get 10 exactly you win. \n5. You get less than 10 but are higher than me, you win!\n" << std::endl;
	std::cout << "\nGot it?  Let's begin! \n'ROLL' or 'PASS'" << std::endl;
	std::getline(std::cin, choice);

	while (choice != "PASS") {
		diceRoll();
		playerSum = playerSum + diceChoice[0];
		std::cout << "\nYou rolled " << diceChoice[0] << std::endl;

		if (playerSum > 10) {
			riggedCounterThree();
			if (getCountThree() == 5) {
				break;
			}
			std::cout << "\nYou have " << playerSum << " You bust! You lose!" << std::endl;
			break;
		}
		else if (playerSum < 10) {
			std::cout << "\nYou have " << playerSum << ". 'ROLL' or 'PASS'?" << std::endl;
			std::getline(std::cin, choice);
		}
		else if (playerSum == 10) {
			std::cout << "\nYou got 10! You win!!" << std::endl;
			break;
		}
		else {
			std::cout << "\n'ROLL' or 'PASS'?" << std::endl;
			std::getline(std::cin, choice);
		}
	}
	if (playerSum < 10) {
		riggedCounterThree();
		bullySum == 10;
		std::cout << "\nHAHA I WIN!!!" << std::endl;
	}
	playerWins();
}

//The following six methods track how many rigged games have been played. 
void Games::riggedCounterOne() {
	counterOne = counterOne + 1;
}
int Games::getCountOne() {
	return counterOne;
}

void Games::riggedCounterTwo() {
	counterTwo = counterTwo + 1;
}
int Games::getCountTwo() {
	return counterTwo;
}

void Games::riggedCounterThree() {
	counterThree = counterThree + 1;
}
int Games::getCountThree() {
	return counterThree;
}
//This method tracks the winner of the game. 
bool Games::playerWins() {
	if (win) {
		return true;
	}
	else {
		return false;
	}
}

//This method is the final fight of the game. The enemy has a vector with three items that are shuffled.  The enemy then uses the top index as it's choice.
//Several if/else statements of performed to determine a winner. 
void Games::shotgun() {
	enemyShotgunChoice.push_back("RELOAD");
	enemyShotgunChoice.push_back("SHOOT");
	enemyShotgunChoice.push_back("BLOCK");

	std::cout << "\nBoss fight!!" << std::endl;
	std::string choice;
	std::string endGame;
	std::string randChoice;
	bool correctBossChoice = true;
	int bossPower = 1;
	int playerPower = 1;

	std::cout << "\nHere's how ya play:\nYour options are 'RELOAD', 'SHOOT', and 'BLOCK'.\nIf you're out of ammo, you must reload before you can shoot.\nYou may reload up to 3 times before shooting for higher power.\nWhen you shoot, you shoot all ammo.\nIf we both shoot, the person with the highest power wins.\nIf one is reloading while the other shoots, the person shooting wins.\nIf someone shoots while the other is blocking, the person shooting loses their ammo.\nGot it?" << std::endl;
	std::cout << "\nOkay.  Let's play!  We both start at reload giving us each 1 ammo. Make your choice." << std::endl;
	std::getline(std::cin, endGame);
	while (true) {
		
		while (true)
		{
			srand(time(NULL));
			int randomNum = rand() % 100;
			for (int i = 0; i <= randomNum; i++); {
				std::random_shuffle(enemyShotgunChoice.begin(), enemyShotgunChoice.end());
			}
			if (enemyShotgunChoice[0] == "SHOOT" && bossPower < 1)
			{
				correctBossChoice = false;
			}
			else if (enemyShotgunChoice[0] == "RELOAD" && bossPower > 2)
			{
				correctBossChoice = false;
			}
			else
			{
				correctBossChoice = true;
			}
			if (correctBossChoice == true)
			{
				break;
			}
		}
		if (endGame == "RELOAD" && playerPower == 3) {
			std::cout << "\nYou can't reload more than 3!  Try again!  Make your choice: " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (endGame == "RELOAD" && playerPower < 3) {
			if (enemyShotgunChoice[0] == "RELOAD" && bossPower == 3) {
				std::cout << "\nI chose " +  enemyShotgunChoice[1] + "." << std::endl;
				if (enemyShotgunChoice[1] == "SHOOT") {
					std::cout << "\nHAHAHAHAHA I WIN!!" << std::endl;
					break;
				}
				else {
					playerPower = playerPower + 1;
				}
			}
			else if (enemyShotgunChoice[0] == "RELOAD" && bossPower < 3) {
				bossPower = bossPower + 1;
				playerPower = playerPower + 1;
				std::cout << "\nI chose " + enemyShotgunChoice[0] + "." << std::endl;
			}
			else if (enemyShotgunChoice[0] == "SHOOT") {
				std::cout << "\nI chose " + enemyShotgunChoice[0] + "." << std::endl;
				std::cout << "\nHAHAHAHAHA I WIN!!" << std::endl;
				break;
			}
			else {
				std::cout << "\nI chose " + enemyShotgunChoice[0] + "." << std::endl;
				playerPower = playerPower + 1;
			}

			std::cout << "\nI have " << bossPower << " ammo. \nYou have " << playerPower << " ammo. \nMake your choice: " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (endGame == "BLOCK") {
			std::cout << "\nI chose " + enemyShotgunChoice[0] + "." << std::endl;
			if (enemyShotgunChoice[0] == "SHOOT") {
				bossPower = 0;
			}
			else if (enemyShotgunChoice[0] == "RELOAD") {
				bossPower = bossPower + 1;
			}
			std::cout << "\nI have " << bossPower << " ammo. \nYou have " << playerPower << " ammo. \nMake your choice: " << std::endl;
			std::getline(std::cin, endGame);
		}
		else if (endGame == "SHOOT" && playerPower == 0) {
			std::cout << "\nYou can't shoot with no ammo."<< std::endl;
			std::getline(std::cin, endGame);
		}
		else if (endGame == "SHOOT" && playerPower > 0) {
			std::cout << "\nI chose " + enemyShotgunChoice[0] + "." << std::endl;
			if (enemyShotgunChoice[0] == "SHOOT") {
				if (bossPower == playerPower) {
					playerPower = 0;
					bossPower = 0;
					std::cout << "\nI have " << bossPower << " ammo. \nYou have " << playerPower << " ammo. \nMake your choice: " << std::endl;
					std::getline(std::cin, endGame);
				}
				else if (bossPower > playerPower) {
					std::cout << "\nHAHAHAHAHA I WIN!!" << std::endl;
					break;
				}
				else {
					std::cout << "\nUGHHHHHH You bested me!" << std::endl;
					win = true;
					break;
				}
			}
			else if (enemyShotgunChoice[0] == "BLOCK") {
				playerPower = 0;
				std::cout << "\nI have " << bossPower << " ammo. \nYou have " << playerPower << " ammo. \nMake your choice: " << std::endl;
				std::getline(std::cin, endGame);
			}
			else {
				std::cout << "\nUGHHHHHH You bested me!" << std::endl;
				win = true;
				break;
			}
		}
		else {
			std::cout << "\nDoncha listen?  I said 'RELOAD', 'SHOOT', and 'BLOCK'! Wanna try that again? " << std::endl;
			std::getline(std::cin, endGame);
		}
	}
	playerWins();
}


//Revisions for final project

//sticks: Each player chooses to take 1,2, or 3 sticks out of the pile they have. Person whom draws final stick loses.
void Games::sticksGame(bool rigged)
{ 
	//if true, human, if false, CPU
	bool humanPlayer = !rigged;

	//create list of 3 options per amount of sticks left. take 1 stick, 2, or 3.
	int sticks = 10;

	//If rigged, the number of sticks taken will be optimal. CPU goes first
	//If not rigged, the number of sticks taken will be random. Player goes first.

	//rigged

	if (rigged)
	{
		std::cout << "\n I'll go first to show ya how it works!\n";
		int p = sticksToOne(sticks);
		sticks -= p;
		std::cout << "\n Now you go.";
		humanPlayer = true;

		do
		{
			int q = playerTurnSticks(sticks);
			sticks -= q;

			if (sticks < 1) std::cout << "\n\n There is only one stick remaining, you must pick up that stick.";
			else humanPlayer = false;

			int w = (rand() % 3) + 1;

			if (w == 1)std::cout << "\n The opponenet has taken 1 stick from the pile.";
			else std::cout << "\n The opponenet has taken " << w << " sticks from the pile.";

			sticks -= w;

			if (sticks < 1) std::cout << " \n\n The opponent picked up the last stick.";
			else humanPlayer = true;

		} while (sticks > 1);

		if (sticks <= 1 && humanPlayer == true)
		{
			std::cout << "\n You lose!";
		}
		else
		{
			std::cout << "\n [This shouldn't be here because the games rigged, you must be something special]";
		}
	}

	//not rigged: 

	else 
	{
		srand(time(NULL));
		do
		{
			int q = playerTurnSticks(sticks);
			sticks -= q;
			if (sticks < 1); else humanPlayer = false; //If the game is lost because somebody picked 2/2 remaining sticks, 
															//the currentplayer doesn't turn over, and instead will lose.
			int w = (rand() % 3) + 1;						
			sticks -= w;
			if (sticks < 1); else humanPlayer = true;

		} while (sticks > 1);

		if (sticks <= 1 && humanPlayer == true)
		{
			std::cout << "\n You lose!";
		}
		else if (sticks <= 1 && humanPlayer == false)
		{
			std::cout << "\n Aghh you beat me!";
		}
	}
}

//optimal moves to always win the game, provided you go first:

int Games::sticksToOne(int i)
{
	if (i == 10|| i == 9) //i==9 shouldn't happen if the game is rigged but it's there just in case.
	{
		std::cout << "\n Opponent removed 1 stick";
		return 1;
	}
	else if (i == 8 || i == 7 || i == 6)
	{
		if (i % 5 == 1)
		{
			std::cout << "\n Opponent removed 1 stick";
		}
		else
		{
			std::cout << "\n Opponent removed " << i % 5 << " sticks";
		}
		return (i%5);
	}
	else if (i == 4 || i == 3 || i == 2)
	{
		if (i == 2)
		{
			std::cout << "\n Opponenet removed 1 stick";
		}
		else
		{
			std::cout << "\n Opponent removed " << (-1)*(1-i) << " sticks";
		}
		std::cout << "\n\n There is only one stick remaining, you must pick up that stick.";
		return (-1)*(1 - i);
	}
	else
	{
		std::cout<<("Something has gone terribly wrong. \n Adjusting stick count.");
		if (i > 10)
		{
			return sticksToOne(i - 1);
		}
		else
		{
			return sticksToOne(i + 1);
		}
	}
}

//Players turn

int Games::playerTurnSticks(int i)
{
	std::cout << "\n[Current amount of sticks: " << i << " ]";
	int playerChoice = 0;
	while (playerChoice > 3 || playerChoice < 1 || playerChoice > i)
	{
		std::cout << "\n[Take 1,2, or 3 sticks from the pile]";
		std::cin >> playerChoice;
	}
	if(playerChoice == 1 ) std::cout << "\n You have taken 1 stick from the pile.";
	else std::cout << "\n You have taken " << playerChoice << "sticks from the pile.";
	return playerChoice;
}

void Games::tictactoe(bool rigged)
{
	//if true, human, if false, CPU
	bool humanPlayer = true;
	//board
	 // 1,1 1,2 1,3; 2,1 2,2 2,3; 3,1 3,2 3,3
	char board[9] = {};
	//loop init
	bool winner = false;
	int turn = 0;
	if (rigged)
	{
		board[4] == 'O';
		turn += 1;
	}

	while (turn != 9 || winner == false) // after 9 turns with no winner the game ties- which is basically a loss because
										//the player needs to win in order to defeat the opponenet and move on with the game.
	{
		std::cout << "\n\n\tTic Tac Toe\n\n";
		std::cout << "Player 1 (X)  -  Player 2 (O)\n";
		std::cout << std::endl;
		std::cout << std::endl;

		//using std::endl instead of \n to see the printed statements line up while debugging

		std::cout << "     |     |     " << std::endl;
		std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << std::endl;

		std::cout << "_____|_____|_____" << std::endl;
		std::cout << "     |     |     " << std::endl;

		std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << std::endl;

		std::cout << "_____|_____|_____" << std::endl;
		std::cout << "     |     |     " << std::endl;

		std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << std::endl;

		std::cout << "     |     |     " << std::endl;
		std::cout << std::endl;

		if (!rigged)
		{
			//TODO: rigged AI turn, winner decisions, scour matrix for combinations.
			srand(time(NULL));
			int x=10;
			do
			{
				std::cout << "\n[select a position for your X. Top left is 1, Top right is 3, Bottom left is 7, bottome right 9, etc]\n";
				std::cin >> x;
				x -= 1;

			} while ((x > 9 || board[x] == 'X') || (x > 9  || board[x] == 'O'));

			board[x] = 'X';
			//checks if that last move was a winning one
			int win = checkBoard(board, 'X', 'O');

			if (win > 99)
			{
				winner = true;
				if (humanPlayer)
				{
					std::cout << "You win";
					//end the game
				}
				else
				{
					std::cout << "You lose";
					//end the game
				}
			}
			else
			{
				humanPlayer = false;
				int a;
				do
				{
					a = rand() % 9;
				} while (board[a] == 'X' || board[a] == 'O');
				board[a] = 'O';
				win = checkBoard(board, 'O', 'X');
				
				if (win > 99)
				{
					winner = true;
					if (humanPlayer)
					{
						std::cout << "You win";
						//end the game
					}
					else
					{
						std::cout << "You lose";
						//end the game
					}
				}
				
			}
			//Tested and works
			humanPlayer = true;
			turn += 1;
		}

		if (rigged)
		{
			//TODO: rigged AI turn, winner decisions, scour matrix for combinations.
			int x = 10;
			do
			{
				std::cout << "\n[select a position for your X. Top left is 1, Top right is 3, Bottom left is 7, bottome right 9, etc]\n";
				std::cin >> x;
				x -= 1;

			} while ((x > 9 || board[x] == 'X') || (x > 9 || board[x] == 'O'));

			board[x] = 'X';
			//checks if that last move was a winning one
			int win = checkBoard(board, 'X', 'O');

			if (win > 99)
			{
				winner = true;
				if (humanPlayer)
				{
					std::cout << "You win";
					//end the game
				}
				else
				{
					std::cout << "You lose";
					//end the game
				}
			}
			else
			{
				humanPlayer = false;
				int a;
				a = decision(board, 'O', 'X');
				board[a] = 'O';
				win = checkBoard(board, 'O', 'X');

				if (win > 99)
				{
					winner = true;
					if (humanPlayer)
					{
						std::cout << "You win";
						//end the game
					}
					else
					{
						std::cout << "You lose";
						//end the game
					}
				}

			}
			//Tested and works
			humanPlayer = true;
			turn += 1;
		}
	}
}

int Games::checkBoard(char board[], char xo, char check)
{
	//Assume xo == 'X' and check == 'O' for commenting purposes

	int x1=0; int x2=0; 

	//vertical check

	if (board[0] == xo)
	{
		int mon = lineCheck(board[0], board[3], board[6], xo, check);
		mon += lineCheck(board[6], board[3], board[0], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[1] == xo)
	{
		int mon = lineCheck(board[1], board[4], board[7], xo, check);
		mon += lineCheck(board[7], board[4], board[1], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[2] == xo)
	{
		int mon = lineCheck(board[2], board[5], board[8], xo, check);
		mon += lineCheck(board[8], board[5], board[2], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	//horizontal

	if (board[0] == xo)
	{
		int mon = lineCheck(board[0], board[1], board[2], xo, check);
		mon += lineCheck(board[2], board[1], board[0], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[3] == xo)
	{
		int mon = lineCheck(board[3], board[4], board[5], xo, check);
		mon += lineCheck(board[5], board[4], board[3], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[6] == xo)
	{
		int mon = lineCheck(board[6], board[7], board[8], xo, check);
		mon += lineCheck(board[8], board[7], board[6], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}

	//diagonal

	if (board[0] == xo|| board[8] == xo)
	{
		int mon = lineCheck(board[0], board[4], board[8], xo, check);
		mon += lineCheck(board[8], board[4], board[0], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[2] == xo || board[6] == xo)
	{
		int mon = lineCheck(board[2], board[4], board[6], xo, check);
		mon += lineCheck(board[6], board[4], board[2], xo, check);
		if (mon >= 100) return mon;
		else if (mon == 3) x2 += 1;
		else if (mon == 1) x1 += 1;
		else;
	}
	if (board[4] == xo)
	{
		x1 += 1;
	}
	return ((3 * x2) + x1);
}

int Games::lineCheck(char a, char b, char c, char xo, char check)
{
	if (b == a && c == b) //If there's three in a row, return 100 so the line "win>99" is true.
	{
		return 100; // 3 in a row, you win.
	}
	else if ((b == a && c != check) || (c==a && b != check))
	{
		return 3; //two in a row with an open space in the third
	}
	else if (b != check && c != check)
	{
		return 1; // one in a row, with nothing else in that column
	}
	else
	{
		return 0; // one or two in a row with one or two other things in the column
	}
}

int Games::decision(char board[], char xo, char check)
{
	int x1 = 0; int x2 = 0;
	int a[9] = { 0 };
	int b[9] = {};
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != check && board[i] != xo)
		{
			b[i] = 1; //1 signifies the space is empty
		}
	
	}
	if (b[0] == 1)
	{
		a[0]= lineCheck('O', board[1], board[2], xo, check);			//horizontal
		a[0] += lineCheck(board[2], board[1], 'O', xo, check);
		a[0] += lineCheck('O', board[4], board[8], xo, check);			//diagonal
		a[0] += lineCheck(board[8], board[4], 'O',xo,check);
		a[0] += lineCheck('O', board[3], board[6],xo,check);			//Vertical
		a[0] += lineCheck(board[6],board[3], 'O',xo, check);
		if (a[0] >= 100) return 0;
		else;
	}
	if (b[1] == 1)
	{
		a[1] = lineCheck(board[0], 'O', board[2], xo, check);			//horizontal
		a[1] += lineCheck(board[2], 'O', board[0], xo, check);
		a[1] += lineCheck('O', board[4], board[7], xo, check);			//Vertical
		a[1] += lineCheck(board[7], board[4], 'O', xo, check);
		if (a[1] >= 100) return 1;
		else;
	}
	if (b[2] == 1)
	{
		a[2] = lineCheck(board[0], board[1], 'O', xo, check);			//horizontal
		a[2] += lineCheck('O', board[1], board[0], xo, check);
		a[2] += lineCheck('O', board[4], board[6], xo, check);			//diagonal
		a[2] += lineCheck(board[6], board[4], 'O', xo, check);
		a[2] += lineCheck('O', board[5], board[8], xo, check);			//Vertical
		a[2] += lineCheck(board[8], board[5], 'O', xo, check);
		if (a[2] >= 100) return 2;
		else;
	}
	if (b[3] == 1)
	{
		a[3] = lineCheck('O', board[4], board[5], xo, check);			//horizontal
		a[3] += lineCheck(board[5], board[4], 'O', xo, check);
		a[3] += lineCheck(board[0], 'O', board[6], xo, check);			//Vertical
		a[3] += lineCheck(board[6],'O', board[0], xo, check);
		if (a[3] >= 100) return 3;
		else;
	}	
	//b[4] should never == 1 because at the beginning of a rigged game O is in the center
	if (b[5] == 1)
	{
		a[5] = lineCheck(board[3], board[4], 'O', xo, check);			//horizontal
		a[5] += lineCheck('O', board[4], board[3], xo, check);
		a[5] += lineCheck(board[2], 'O', board[8], xo, check);			//Vertical
		a[5] += lineCheck(board[8], 'O', board[2], xo, check);
		if (a[5] >= 100) return 5;
		else;
	}	
	if (b[6] == 1)
	{
		a[6] = lineCheck('O', board[7], board[8], xo, check);			//horizontal
		a[6] += lineCheck(board[8], board[7],'O', xo, check);
		a[6] += lineCheck('O', board[4], board[2], xo, check);			//diagonal
		a[6] += lineCheck(board[2], board[4], 'O', xo, check);
		a[6] += lineCheck(board[0], board[3], 'O', xo, check);			//Vertical
		a[6] += lineCheck('O', board[3], board[0], xo, check);
		if (a[6] >= 100) return 6;
		else;
	}	
	if (b[7] == 1)
	{
		a[7] = lineCheck(board[6], 'O', board[8], xo, check);			//horizontal
		a[7] += lineCheck(board[8], 'O', board[6], xo, check);
		a[7] += lineCheck(board[1], board[4], 'O', xo, check);			//Vertical
		a[7] += lineCheck('O', board[4], board[1] , xo, check);
		if (a[7] >= 100) return 7;
		else;
	}	
	if (b[8] == 1)
	{
		a[8] = lineCheck(board[6], board[7], 'O', xo, check);			//horizontal
		a[8] += lineCheck('O', board[7], board[6], xo, check);
		a[8] += lineCheck(board[0], board[4], 'O', xo, check);			//diagonal
		a[8] += lineCheck('O', board[4], board[0], xo, check);
		a[8] += lineCheck(board[2], board[5], 'O', xo, check);			//Vertical
		a[8] += lineCheck('O', board[5], board[2], xo, check);
		if (a[8] >= 100) return 8;
		else;
	}
	int retValue = 0;
	for (int i = 1; i < 9; i++)
	{
		if (a[i] > a[i - 1])
		{
			retValue = i;
		}
	}
	return retValue;
}

//(3x2 + x1) - (3o2 + o1)