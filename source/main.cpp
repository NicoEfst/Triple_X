#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <numeric>
#include <functional>
#include "Level.h"

/**
 * @brief 
 * Prints the info message of each level. Each character is printed with
 * a time-delay to make it easier for the player to read the message.
 * @param Message
 * The info message of a particular level.
 * @param SleepSec
 * The pause-time between the printing of two concecutive characters.
 */
void print_info_message(const std::string &Message, double SleepSec = 0.05)
{
    for (const char &c : Message) {
        std::this_thread::sleep_for(std::chrono::duration<double>(SleepSec));
        std::cout << c;
    }
    std::cout << std::endl;
}

/**
 * @brief 
 * The introductory message that describes the context of the game.
 */
inline void print_start_msg(void)
{
    std::string S("\tThe COVID-19 vaccine has been discovered in a secret government lab. The government, \n"
                 "refuses to make the formula publicly available, in an attempt to make a fortune from its \n"
                 "global level demand.\n"
                 "\tAs a scientist that worked in this project for months, you feel betrayed and \n"
                 "outraged that your hard work will be used as a money maker for the rich and \n"
                 "privileged, while poor people will continue to die from COVID-19. After sleeping \n"
                 "over it, you decide to steal the formula, and publish it anonymously on the Internet, \n"
                 "in an attempt to make it possible for every country to independently produce the \n"
                 "vaccine at a fair price or even free.\n"
                 "\tThe formula is stored in a computer with no Internet access in an enclosed facility \n"
                 "next to the laboratory you worked for months. At discussions over lunch, you overheard \n"
                 "security guards mocking the security protocol of this enclosed facility, which consists of \n"
                 "10 sequential rooms and in order to move forward, you have to solve a mathematical riddle!!!\n"
                 "The 3 head scientists that have access, know the answers to these riddles and they pass all the \n"
                 "rooms very quickly. Afterwards, the security guards, provide visual confirmation through the \n"
                 "cameras and the scientist receives clearance to open the computer.\n"
                 "\tToday is the day of the last game of the NBA finals so everyone will be watching the game \n"
                 "including the guard on duty. So, you decide to sneak in the facility, try to solve the riddles \n"
                 "and then depend on the fact that the guard will give immediate clearance in order to not miss \n"
                 "even a second of the match.\n"
                 "\tThe faith of many people around the globe depends on the success or not of your mission. \n"
                 "Good luck and may the force be with you!\n");
    
    print_info_message(S);
}

/**
 * @brief 
 * The message printed at the end of the game. If the player has health points left (HP)
 * then the game is succesfully finished. However, if the player consumed all their HP the
 * game is over.
 * @param HP
 * The player's health points.
 */
inline void print_end_msg(int HP)
{
    if (!HP) {
        std::string S("Due to the many wrong answers, an alarm was trigged!!! The guard hears the alarm and runs\n"
                     "immediately to the enclosed facility dropping his pizza and cola to the floor, swearing\n"
                     "that all he wanted was a peaceful evening to watch the game. He immediately notifies the\n"
                     "police, which arrives after a few minutes and arrests you.\n"
                     "...\nYou are now in jail and waiting for your trial...\nGame Over");
        print_info_message(S);
        return;
    }

    std::string S("You go back to your room and try to get some sleep. You put the USB stick under your pillow\n"
                  "and hold it tight all night long. Tomorrow, a friend of yours will come visit and you will hand\n"
                  "him the USB for safe-keeping. He will upload the formula maybe after a month in order not to draw\n"
                  "attention.\n"
                  "Congratulations, you saved the world!\n"
                  "The End");
    print_info_message(S);
}

/**
 * @brief 
 * Prints a block of text containing general information (room, HP) and the
 * sum, product of the current level.
 * @param CurLevel
 * The current level.
 * @param HP
 * The players' health points.
 */
void user_guess_header(const Level &CurLevel, const int HP)
{
    int Sum = 0, Product = 0;

    CurLevel.get_code(Sum, Product);

    std::cout << std::endl;
    std::cout << "Room: " << int(CurLevel.get_stage()) << "\t" << "Wrong Guesses left: " << HP << std::endl;
    std::cout << "Give the 3-digit code so that:" << std::endl;
    std::cout << "Total sum = " << Sum << std::endl;
    std::cout << "Total product = " << Product << std::endl;
}

/**
 * @brief 
 * Prints the sum, product of the current level and reads the 3-digit code provided
 * by the player.
 * @param CurLevel 
 * The current level.
 * @param HP
 * The players' health points.
 * @return true 
 * The user provided 3-digit code is correct.
 * @return false
 * The user provided 3-digit code is wrong. The user looses one HP and the process is
 * repeated.
 */
bool user_guessed_correctly(const Level &CurLevel, const int HP)
{
    user_guess_header(CurLevel, HP);

    int Vals[3]{};
    if (!(std::cin >> Vals[0] >> Vals[1] >> Vals[2])) {
        std::cin.clear(); // Clears any errors.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the buffer.
    }

    int UserSum = std::accumulate(std::begin(Vals), std::end(Vals), 0);
    int UserProduct = std::accumulate(std::begin(Vals), std::end(Vals), 1, std::multiplies<int>());

    int LevelSum = 0, LevelProduct = 0;
    CurLevel.get_code(LevelSum, LevelProduct);

    bool CodeIsCorrect = false;
    if (UserSum == LevelSum && UserProduct == LevelProduct) {
        std::cout << "\nCongratulations! The door leading to the next room was opened!\n" << std::endl;
        CodeIsCorrect = true;
    } else {
        std::cout << "\nOops! The code is incorrect. Take a closer look to the problem and try again..." << std::endl;
    }

    return CodeIsCorrect;
}

/**
 * @brief
 * Main function of the program.
 * @return
 * Always 0.
 */
int main()
{

    print_start_msg();

    Stages  Stage = Stages::LEVEL_1;
    int     HP = 10;
    while (Stage < Stages::MAX_LEVEL) {
        Level   CurLevel(Stage);        

        print_info_message(CurLevel.get_info());

        while (Stage < Stages::LEVEL_10 && !user_guessed_correctly(CurLevel, HP)) {
            HP--;
            if (!HP) break;
        }

        if (!HP) break;
        ++Stage;
    }

    print_end_msg(HP);

    return 0;
}