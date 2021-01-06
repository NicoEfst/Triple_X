#ifndef _LEVEL_H
#define _LEVEL_H

#include <string>
#include <memory>

class LevelImpl;

/**
 * @brief
 * This class describes all the levels that the user has to pass successfully to finish the game.
 */
typedef enum class Stages {
    LEVEL_1 = 1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    LEVEL_7,
    LEVEL_8,
    LEVEL_9,
    LEVEL_10,

    MAX_LEVEL
} Stages;

extern Stages& operator++(Stages& Stage);

/**
 * @brief
 * This class contains all the necessary features of a level (room).
 */
class Level final {
    public:
        Level() = delete;
        Level(const Level&) = delete;
        Level& operator=(const Level&) = delete;
        ~Level() = default;

        explicit Level(const Stages cur_level = Stages::LEVEL_1);

        const Stages get_stage(void) const;

        const std::string& get_info(void) const;

        void get_code(int &Sum, int &Product) const;

    private:
        std::shared_ptr<LevelImpl>  pImpl;
};

#endif