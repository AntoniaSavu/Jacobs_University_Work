/*
CH-230-A
a11_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>

using namespace std;

class Creature {
public:
  Creature();
  void run() const;
  ~Creature();

protected:
  int distance;
};
class Wizard : public Creature {
public:
  Wizard();
  void hover() const;

private:
  int distFactor;
};

class Fairy : public Creature { // created the fairy class
public:
  Fairy();
  void fly() const;
  // with the method fly
private:
  int flying;
  // and a flying property
};

class Dragon : public Creature { // created the dragon class
public:
  Dragon();
  void bfire() const;
  // with the breathing fire method

private:
  int fire;
  // and a fire property
};
Creature::~Creature() {
  cout << "Calling the destructor\n";
  // added a destructor and its comment
}

Creature::Creature() : distance(10) {
  cout << "Calling the creature constructor\n";
  // added comments for each constructor
}
Wizard::Wizard() : distFactor(3) { cout << "Calling the wizard constructor\n"; }
Fairy::Fairy() : flying(30) { cout << "Calling the fairy constructor\n"; }
Dragon::Dragon() : fire(15) { cout << "Calling the dragon constructor\n"; }
void Creature::run() const { cout << "running " << distance << " meters!\n"; }

void Fairy::fly() const {
  cout << "flying " << flying + distance << " meters!\n";
  // defining the methods
}
void Dragon::bfire() const { // for both of the new creatures
  cout << "breathing fire over " << (fire * distance) << " meters!\n";
}
void Wizard::hover() const {
  cout << "hovering " << (distFactor * distance) << " meters!\n";
}

int main() {
  cout << "Creating an Creature.\n";
  Creature c; // creating an instance of a creature
  c.run();    //

  cout << "\nCreating a Wizard.\n";
  Wizard w;  // creating an instance of a wizard
  w.run();   // calling the fly function specific to a creature
  w.hover(); // calling the hover function specific to a wizard

  cout << "\nCreating a Fairy.\n";
  Fairy f; // creating an instance of a fairy
  f.run(); // calling the run method specific to a creature
  f.fly(); // calling the fly function specific to a fairy

  cout << "\nCreating a Dragon.\n";
  Dragon d;  // creating an instance of a dragon
  d.run();   // calling the run method specific to a creature
  d.bfire(); // calling the breathing fire function specific to a dragon
  cout << "\n";
  return 0;
}