#ifndef OOZE_H_
#define OOZE_H_

#include <SDL.h>
#include <unordered_map>
#include <vector>
#include <cmath>
#include "object.h"
#include "spritesheet.h"
#include "animation.h"
#include "utils.h"
#include "HUD.h"
#include "player.h"
#include "collision.h"
#include "circle.h"
#include "game.h"
#include "pickup.h"
#include "generator.h"
#include "tilemap.h"
#include "room.h"

class Pickup;

enum OozeState { // is public
        HANGRY, //temp state
        ROAMING,
        EATING,
        CLONING,
        FIGHTING,
        FLEEING,
        HIDING,
        DYING
};

class Ooze : public Object {
    

private:
    SDL_Rect rect; // includes x_pos, y_pos, width, height
    //Used to check line of sight
    SDL_Rect colRect;

    int x_vel;
    int y_vel;
    int x_deltav;
    int y_deltav;

    OozeState state;
    int hostility;
    Player *player;
    HUD *hud;
    SpriteSheet sheet;
    Animation* anim;
    int overlapTicks;
    std::unordered_map<std::string, Animation> anims;
    int ate;
    SDL_Rect *target;
    SDL_Rect *lastRoom;
    bool initialized;

    Room* curRoom;
    Tilemap* tilemap;
    
public:

    

    // Variables
    int oozeNumber;         // This ooze's ID #
    static int totalOoze; //How many instances of the object exist? (initializes to 0)
    int damage = 5;
    // Constructors & destructor

    Ooze(); // Default constructor
    Ooze(Room* room, Player *player, HUD *h);

//    Ooze(oozeState st, int hostil);
//    Ooze(const Ooze& other);    // copy constructor
//    Ooze& operator=(Ooze other); // copy assignment
//    Ooze& operator=(rule_of_five&& other) noexcept // move assignment
//    Ooze(rule_of_five&& other) noexcept // move constructor
    ~Ooze(); // Destructor
    
    
    // NEW
    Pickup* getPickup(std::unordered_map<std::string, Object*> *objectList);
    SDL_Rect* pickTarget(std::unordered_map<std::string, Object*> *objectList, std::vector<std::vector<int>> grid);
    bool foundFood(Pickup* pickUp);
    int getAte();
    OozeState getState();
    void initRoom(std::vector<std::vector<int>> grid, SDL_Rect* t);

    // Updates
    void update(std::unordered_map<std::string, Object*> *objectList, Uint32 ticks);
    bool updateState(std::unordered_map<std::string, Object*> *objectList, Uint32 ticks);
    void updateVelocity(int _xdv, int _ydv); 
    void updatePosition();
    void updateAnimation(Uint32 ticks);
    // SDL
    std::string getInstanceName();
    void input(const Uint8* keystate);
    void init(SDL_Renderer* gRenderer);
    void setSpriteSheet(SDL_Texture* _sheet, int _cols, int _rows);
    void update(std::unordered_map<std::string, Object*> *objectList, std::vector<std::vector<int>> grid, Uint32 ticks);
    SDL_Renderer* draw(SDL_Renderer* renderer, SDL_Rect cam);
    bool checkOozeOverlap(std::unordered_map<std::string, Object*> *objectList, Uint32 ticks);
    bool isUsed();

    //Movement
    void checkBounds(int max_width, int max_height, bool move);
    bool checkCollision(int curX, int curY, std::vector<std::vector<int>> grid, bool move);
    bool drawLine(std::vector<std::vector<int>> grid, SDL_Rect* target);
    void moveLine(std::vector<std::vector<int>> grid, SDL_Rect* target);
    void moveRoom(std::vector<std::vector<int>> grid);
    
    // Math
    void increaseHostility();
    void decreaseHostility();
//    bool checkPlayerDistance(std::vector<Object*> objectList);
    // Getters
    int getWidth();
    int getHeight();
    int getX();
    int getY();
    SDL_Rect* getRect();
    SpriteSheet getSheet();
    //Animation
    void addAnimation(std::string tag, Animation anim);
    Animation* getAnimation(std::string tag);
    void setAnimation(std::string tag);
    //void updateAnimation(Uint32 ticks);
};

#endif  //  OOZE_H_