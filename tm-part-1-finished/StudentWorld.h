#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

/* my includes */
#include"Actor.h"
#include <vector>
#include<algorithm>
#include<sstream>


/* Prof comment */
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Earth;
class TunnelMan;
class Actor;

class StudentWorld : public GameWorld {
public:
  StudentWorld(std::string assetDir)
      : GameWorld(assetDir) {
  }

  //destructor
  ~StudentWorld();

  virtual int init();

  virtual int move();

  virtual void cleanUp();

  //update display text status
  void updateDisplayText();

  //formate text
  std::ostringstream formateText(int level,
                                 int lives,
                                 int health,
                                 int squirts,
                                 int gold,
                                 int barrelsLeft,
                                 int sonar,
                                 int score);

  // initilize input for player
  //void initInput(char* c) {
//{ 'G','S','W','\0'};

  //}
  //MARK: update below functions
  //check if player is alive in curr tick
  bool isPlayerDeadInCurrTick();

  // return true of all Barrels are picked up
  bool playerCompletedCurrLevel();
  // make the tunnelman dig curr earth
  bool dig(int x, int y);
  bool dropGold(int x, int y);

  //check if the tunnelman is annoyed
  bool isPlayerAnnoyed();
  //show all hidden objects

  bool showHidden(int x, int y);

  // fire squirt x,y,dir , return true if squirt is shot
  bool fireSquirt(int x, int y, GraphObject::Direction currDirection);
private:
  // object distribution
  int B, G, L;
  //tracking  objects
  int numRegularProtestors;
  int numBarrelOil;
  int numBoulders;
  int numGold;
  int numTicks;
  int numEarth;

  // add to players inventory

  char input[4] = {'G', 'S', 'W', '\0'};
  //TunnelMan pointer
  TunnelMan *m_TunnelMan;
  //earth object ptr for filling oil field
  Earth *m_earth[64][64];
  Earth *m_eartharr[64];
  // vector ptr of all actors
  std::vector<Actor *> m_actors;

  // display screen size
  char m_Display[64][64];

};

#endif // STUDENTWORLD_H_
