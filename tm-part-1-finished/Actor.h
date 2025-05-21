#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp



//base class
class StudentWorld; //call SW class
class Actor : public GraphObject {
public:

  //constructor
  Actor(int imageID, int startX, int startY,
        Direction dir, StudentWorld *world, double size = 1.0,
        unsigned int depth = 0) :
      GraphObject(imageID, startX, startY, dir, size, depth), m_alive(true), m_world(world) {}
  //destrucotr
  virtual~Actor() {}
  //setVisiblity function derived from Graphobject function
  virtual void setVisibility(bool isVisible) {
    GraphObject::setVisible(isVisible);
    //update curr visible state
    m_isVisible = isVisible;
  }
  //dosmting
  virtual void doSomething() = 0;
  //get SW ptr
  StudentWorld *getWorld() {
    return m_world;
  }
  //check curr alive state
  bool isAlive() const {
    return m_alive;
  }
  //set alive to false,i.e kill curr TM
  void makeDead() {
    m_alive = false;
  }

private:
  bool m_isVisible;
  bool m_alive;
  StudentWorld *m_world; //ptr to Student world
};

//TunnelMan class
class TunnelMan : public Actor {

public:
  /*
  TunnelMan(int imageID, int startX, int startY,
      Direction dir, StudentWorld* world, double size = 1.0,
      unsigned int depth = 0) :Actor(TID_PLAYER, 30, 60, right, world, 1.0, 0) {
      setVisible(true);
  }
  */
  TunnelMan(StudentWorld *world) : Actor(TID_PLAYER, 30, 60, right, world, 1.0, 0) {
    setVisible(true);
  }

  virtual ~TunnelMan() {;}
  virtual void doSomething();
  // get  and stats stats
  void setCurrHealth(int hp) {
    m_hitpoints = hp;
  }
  int getCurrHealth()const {
    return m_hitpoints;
  }

  int getSquirtCount() const {
    return m_waterSquirt;
  }
  int getGoldNuggetCount() const {
    return m_goldNuggets;
  }
  int getSonarChargeCount() const {
    return m_sonarCharge;
  }
  int getLeftOverBarrelCount() const {
    return m_barrelOil;
  }

  virtual bool giveup();
  // add gold G squirtwater W and sonar S
  void addToPlayerInventory(char input) {
    if (input == 'S') {
      m_sonarCharge++;
    }
    if (input == 'G') {
      m_goldNuggets++;
    }

    if (input == 'W') {
      m_waterSquirt += 5;

    }
  }
private:
  int m_hitpoints; //hp
  int m_waterSquirt;
  int m_sonarCharge;
  int m_goldNuggets;
  int m_barrelOil;

};


// Earth class

class Earth : public Actor {
public:
  Earth(int startX, int startY, StudentWorld *world) : Actor(TID_EARTH, startX, startY, right, world, 0.25, 3) {
    //display earth
    setVisible(true);
  }
  //destructor
 virtual ~Earth() {}

  virtual void doSomething() { ; }
};
// class Objects 
class Objects : public Actor {
  Objects(int imageID, int startX, int startY,
          Direction dir, StudentWorld *world, double size = 1.0,
          unsigned int depth = 0) : Actor(imageID, startX, startY, dir, world, size, depth) {}

// dummy class hold place for orgnazing later 

};

class Boulders : public Actor {
public:
  Boulders(int startX, int startY, StudentWorld *world) : Actor(TID_BOULDER, startX, startY, down, world, 1.0, 1) {
    m_currBoulderState = "stable";
    setVisible(true);
  }
  virtual void doSomething();
private:
  std::string m_currBoulderState;
  int m_boulderTicks;
};

//class Protesrs
class Protestors : public Actor {};

//class regular protestors
class RegularProtestors : public Protestors {

};
//class hard core protestors
class HardcoreProtestors : public Protestors {

};

// class Goodies: base class for player related classes
class Goodies : public Actor {
public:
  Goodies(int imageID, int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth);

  bool setVisbility(bool show) {
    GraphObject::setVisible(show);
    m_show = show;
    return true;
  }
private:
  bool m_show;
};

//class Squirt
class Squirt : public Goodies {
public:
  Squirt(int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth) : Goodies(
      TID_WATER_SPURT,
      startX,
      startY,
      dir,
      world,
      1.0,
      1) {
    m_initTravelDistance = 4;
    setVisible(true);
  }

  virtual void doSomething();
private:
  int m_initTravelDistance;
};
//class Barrel of Oil
class BarrelofOil : public Goodies {
  BarrelofOil(int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth) : Goodies(
      TID_BARREL,
      startX,
      startY,
      dir,
      world,
      1.0,
      2) {
    setVisible(true);
  }
  virtual void doSomething();
};

//class Gold Nugget
class GoldNugget : public Goodies {
  GoldNugget(int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth) : Goodies(
      TID_GOLD,
      startX,
      startY,
      dir,
      world,
      1.0,
      2) {
    setVisible(true);
  }
};
//class Sonar Kit
class SonarKit : public Goodies {
  SonarKit(int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth) : Goodies(
      TID_BARREL,
      startX,
      startY,
      dir,
      world,
      1.0,
      2) {
    setVisible(true);
  }

};
//class Water Pool
class WaterPool : public Goodies {
  WaterPool(int startX, int startY, Direction dir, StudentWorld *world, double size, unsigned int depth) : Goodies(
      TID_WATER_POOL,
      startX,
      startY,
      dir,
      world,
      1.0,
      2) {
    setVisible(true);
  }

};

#endif // ACTOR_H_