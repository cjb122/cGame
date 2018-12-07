/* Team Bandcamp
 * Class function: Calls game class
 *
 */

#include "include/game.h"

int main(int argc, char* argv[]) {
    
    Game game = Game();
    if(!game.init())
    {
        std::cout << "Error starting SDL" << std::endl;
        return 1;
    }
    game.run();
    return 0;
}
