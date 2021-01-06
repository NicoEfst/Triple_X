#include "Level.h"
#include <cassert>
#include <numeric>
#include <functional>
#include <ctime>

class LevelImpl final {
    public:
        LevelImpl() = delete;
        LevelImpl(const LevelImpl&) = delete;
        LevelImpl& operator=(const LevelImpl&) = delete;
        ~LevelImpl() = default;

        explicit LevelImpl(const Stages CurLevel = Stages::LEVEL_1);

        const Stages get_stage(void) const { return this->level; }

        const std::string& get_info(void) const { return this->level_info; }

        void get_code(int &sum, int &product) const { sum = this->Sum; product = this->Product; }

    private:
        Stages      level = Stages::LEVEL_1;
        std::string level_info;
        int         Sum = 0;
        int         Product = 0;

        void        set_level_info(const Stages CurLevel = Stages::LEVEL_1);
        void        set_code(const Stages CurLevel = Stages::LEVEL_1);
};

/**
 * @brief
 * Constructs a new LevelImpl object.
 * @param CurLevel
 * The current level.
 */
LevelImpl::LevelImpl(const Stages CurLevel) : level(CurLevel)
{
    this->set_level_info(CurLevel);
    this->set_code(CurLevel);
}

/**
 * @brief
 * Sets the info message of the LevelImpl class.
 * @param CurLevel
 * The current level.
 */
void LevelImpl::set_level_info(const Stages CurLevel)
{
    switch (CurLevel) {
        case Stages::LEVEL_1:
            this->level_info = "Room 1:\nYou arrive at the facility and head towards the first door. You see a tablet lying on a\n"
                               "stand right next to the door. Suddenly, you hear footsteps and then a voice behind you:\n"
                               "- Unknown man: Hello!\n"
                               "- You: Hello sir! (you are starting to sweat thinking that they caught you! You turn your head\n"
                               "to see the man and you are relieved to notice that he is a pizza delivery guy)!\n"
                               "- Delivery guy: Hey man do you work here? I am trying to find the office of the security guard to\n"
                               " deliver his pizza and cola but I am lost in this maze you call workplace. Can you help me?\n"
                               "- You: Yeah, just follow these stairs over there. The office is on the 2nd floor, first door on the\n"
                               "right.\n"
                               "- Delivery guy: Thanks man, I hope there is a treasure at the end of this maze. Later...\n"
                               "You laugh with the guy's comparison of a tip with a treasure and turn back on the tablet.";
            break;
        case Stages::LEVEL_2:
            this->level_info = "Room 2:\nYou are now in a restricted area. There is no turning back now. However, from this place and beyond,\n"
                               "you won't be interrupted by anyone and you can focus on solving the riddles. You notice that the camera\n"
                               "does not follow your movement as you walk forward to the next door. You are excited that your assumption that the\n"
                               "guard will be watching the game and not the cameras, proved to be correct. You reach the door and you are looking\n"
                               "at the tablet.";
                               break;
        case Stages::LEVEL_3:
            this->level_info = "Room 3:\nYou start thinking that this might actually work! You move towards the next door, when suddenly you\n"
                               "notice that the camera is following you! You try to seem cool, and you head directly to the tablet.";
            break;
        case Stages::LEVEL_4:
            this->level_info = "Room 4:\nYou started to sweat. You enter the room and continue moving to the next door as if this is just another\n"
                               "day at work. You notice that the camera is still and does not move at all. What is going on? Did the guard turn back to\n"
                               "the game? Did he realize that you are an intruder and he is waiting for the police? You start thinking that maybe this\n"
                               "was not a good idea. You think of your family and the people you may never see again if you get caught......\n"
                               "No, what you are doing benefits the greated good of humanity and you need to find the inner strength to keep moving\n"
                               "forward. After standing over the tablet for around a minute fighting with your thoughts, you decided to read what's on\n"
                               "its screen.";
            break;
        case Stages::LEVEL_5:
            this->level_info = "Room 5:\nAs soon as the door opened, you start moving at a faster pace towards the next one. You notice that the camera\n"
                               "is following you. Maybe the guard is not so sure after all! Is he alone and looking at you? Did he call reinforcements or\n"
                               "other colleagues to verify your identity? You made your choice and these thoughts cannot affect your judgement anymore.\n"
                               "You just don't care about the consequences, the only thing that matters is to keep moving forward. You reach the tablet.";
            break;
        case Stages::LEVEL_6:
            this->level_info = "Room 6:\nYou finally made peace with yourself and realized that you are ready to accept the consequences of your actions.\n"
                               "You feel proud for both your courage and your performance so far, since you already solved 5 riddles.\n"
                               "Your pace is back to normal and you move to the next door, not caring about the camera anymore.";
            break;
        case Stages::LEVEL_7:
            this->level_info = "Room 7:\nYou understand that as you move forward the riddles are getting tougher and tougher. You like the challenge and\n"
                               "head towards the next door, when you suddenly hear a voice coming from the tablet!!!\n"
                               "- Guard: Identify yourself immediately!\n"
                               "- You: My name is James Halpert and I am an assistant to the Head Scientist of the COVID-19 vaccine program\n"
                               "Dr. John Hughes. What is this all about?\n"
                               "- Guard: Give a minute...... OK I found your name on the database and I confirm what you said to me. Why do you want\n"
                               "to access the computer?\n"
                               "- You: Dr. Hughes told me to come here immediately and check some of our data, before we announce the discovery of the\n"
                               "vaccine. He fears that the vaccine is not as effective as we think and he needs a second opinion. I am surprised that we\n"
                               "are even having this conversation! Dr. Hughes said that he will inform you about my arrival...\n"
                               " Guard: Hm... The truth is that the phone rang a few minutes earlier but I was busy arguing with the pizza delivery guy\n"
                               "and I missed it. The guy wanted an enormous tip because of some maze or something. I didn't figure it out completely.\n"
                               "Why does it take you so long to pass the rooms?\n"
                               "- You: I told Dr. Hughes that I would prefer to do this tomorrow in order to watch the game and he started yelling that\n"
                               "this is unprofessional behaviour and stuff. So in order to punish me, he didn't give me the passwords and I have to solve all\n"
                               "those riddles to get through. I believe he just wanted me to miss the game. Can you believe this guy?\n"
                               "- Guard: You are unlucky my friend! This is probably the best game I ever watched! Oh, the Time-Out is over,\n"
                               "good luck with your riddles man, you are OK. One last thing, if you use all your 10 guesses and the alarm is\n"
                               "trigged, I am obligated to call the police, so you 'll have to share your story with them. I 'm out!\n"
                               "......\n"
                               "That was close, but you are now sure that the guard believed your story! You just have to keep moving forward quickly.\n"
                               "You look at the tablet.";
            break;
        case Stages::LEVEL_8:
            this->level_info = "Room 8:\nOK only two rooms left and you will finally reach the computer. You just have to finish quickly and be very\n"
                               "careful not to trigger the alarm. You reach the stand and see the tablet.";
            break;
        case Stages::LEVEL_9:
            this->level_info = "Room 9:\nThis is it. Only one door stands between you and the vaccine formula. You just take a minute to realize what\n"
                               "you 've accomplished so far and how important it is to crack the last riddle. You reach the last door, you take a deep\n"
                               "breath and look at the tablet's screen.";
            break;
        case Stages::LEVEL_10:
            this->level_info = "Room 10:\nThe door opens and in front of you, you see a desk and a computer on it. You know that a visual clearance\n"
                               "must be provided by the guard, but you don't know the exact process. You walk towards the desk and sit on the chair.\n"
                               "- Guard: Sorry, for the delay Lebron hit a 3-pointer and I made a mess here, out of my excitement.... I hope you are a\n"
                               "Lakers fan, are you not?\n"
                               "- You: Of course I am. What's the score?\n"
                               "- Guard: We are up by 10 and there are seven minutes left.\n"
                               "- You: OK, then I should hurry! Perhaps, I could see the last minutes at the cafeteria. Can you give me clearance to get\n"
                               "this over with?\n"
                               "- Guard: Another 3-Pointer! Yeahhhh! OK I am sorry, yes you got your clearance man, the computer will soon open and you can\n"
                               "do your job. Go Lakers!!!\n"
                               "The computer opened automatically and you start searching for the formula. After 2 minutes of digging in the hard drive\n"
                               "you find the formula. You slightly remove a USB-stick from your pocket and insert it in the computer. You copy the data,\n"
                               "and as soon as the process is over, you stand up and start your way back with a fast pace. While you are in Room 6,\n"
                               "you here a voice.\n"
                               "- Guard: There are still 2 minutes! I will open all the doors, to save you time! Go straight to the cafeteria and enjoy the\n"
                               "rest of the game. We are up by 6!\n"
                               "- You: Thanks man! You are a life saver!\n"
                               "You never seen a basketball game in your life, however you go straight to the cafeteria in order not to draw attention.\n"
                               "You 've done it!!!";
            break;
        case Stages::MAX_LEVEL:
        default:
            assert(0);
            break;
    }
}

/**
 * @brief
 * Finds the 3-digit code of the current LevelImpl class. After finding the code, it stores the
 * sum and product of the 3 digits.
 * @param CurLevel
 * The current level.
 */
void LevelImpl::set_code(Stages CurLevel)
{
    srand(static_cast<unsigned int>(time(NULL))); // Create a new random sequence based on time of day.

    int AddVal = (CurLevel == Stages::LEVEL_10) ? 0 : 1;
    int Difficulty = static_cast<int>(CurLevel) + AddVal;
    int Vals[] = {rand() % Difficulty, rand() % Difficulty, rand() % Difficulty};

    for (auto &Val : Vals) {
        if (Val != 0) continue;
        Val = (CurLevel == Stages::LEVEL_10) ? Difficulty-1 : Difficulty; // Avoid zero values that lead to zero product.
    }

    this->Sum = std::accumulate(std::begin(Vals), std::end(Vals), 0);
    this->Product = std::accumulate(std::begin(Vals), std::end(Vals), 1, std::multiplies<int>());
}

/**
 * @brief
 * Constructs a new Level object.
 * @param CurLevel
 * The current level. 
 */
Level::Level(const Stages CurLevel) : pImpl(std::make_shared<LevelImpl>(CurLevel))
{
}

/**
 * @brief
 * Get the stage at which a Level class corresponds to.
 * @return const Stages
 * The stage of the level class.
 */
const Stages Level::get_stage(void) const
{
    return this->pImpl->get_stage(); 
}

/**
 * @brief
 * Retrieve the info message of a Level class.
 * @return const std::string& 
 * The message containing all the info of a level.
 */
const std::string& Level::get_info(void) const
{
    return this->pImpl->get_info();
}

/**
 * @brief
 * Get the sum, product that correspond to the internally (not stored)
 * calculated 3-digit code.
 * @param Sum
 * The sum of the 3-digit code.
 * @param Product
 * The product of the 3-digit code.
 */
void Level::get_code(int &Sum, int &Product) const
{
    this->pImpl->get_code(Sum, Product);
}

/**
 * @brief
 * The prefix increment operator for the Stages enum class.
 * @param stage
 * A reference to a Stage object.
 * @return Stages&
 * A reference to the same Stage object, which has been incremented.
 */
Stages& operator++(Stages& Stage)
{
    using IntType = typename std::underlying_type<Stages>::type;
    if (Stage < Stages::MAX_LEVEL) Stage = static_cast<Stages>(static_cast<IntType>(Stage) + 1);
    return Stage;
}