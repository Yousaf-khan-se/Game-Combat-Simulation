#include <iostream>
using namespace std;

//_________________________________________________implementation of the class creature
class Creature
{
protected:
  // variable declaration
  const string name;
  int level;
  int health_points;
  int force;
  int Position;

public:
  // parameterized constructor to set the values
  Creature(const string name, int level, int health_points, int force, int Position = 0) : name(name) // as name is const string
  {
    if (level >= 0) // validation for the level
    {
      this->level = level;
    }
    else
    {
      cout << "(negative input!) invalid input for the level" << endl;
    }

    if (health_points >= 0) // validation for health points
    {
      this->health_points = health_points;
    }
    else
    {
      cout << "(negative input!) invalid input for the health points" << endl;
    }

    if (force >= 0) // validation for the force
    {
      this->force = force;
    }
    else
    {
      cout << "(negative input!) invalid input for the force" << endl; // error message for the validation
    }

    if (Position >= 0) // validation for the postion
    {
      this->Position = Position;
    }
    else
    {
      cout << " (negative input!)invalid input for the Position" << endl;
    }
  }

  // getter of the position of the creature
  int position()
  {
    return this->Position;
  }

  // to check if the creature is alive or not
  bool alive()
  {
    if (health_points > 0) // if the creature is alive then its healthpoints are greater than zero
    {
      return true;
    }
    else
    {
      this->health_points = 0;
      return false;
    }
  }

  // function to calculate the attack points of the creature
  int AttackPoints()
  {
    if (alive() == true) // calculate attackpoints only if the creature is alive
    {
      return (this->level * this->force);
    }
    else
    {
      return 0;
    }
  }

  // function to move the creature froward from their current position.
  void Move(int addToPosition)
  {
    if (addToPosition >= 0) // validation of the passed parameter
    {
      this->Position += addToPosition; // the parameter is added to the current position of the creature
    }
    else
    {
      cout << "(negative input!) invalid input of points to move this creature" << endl; // error message for validation
    }
  }

  // this function notifies by giving the message if the creature is dead
  void GoodBye()
  {
    cout << this->name << " is no more!" << endl;
  }

  // function to subtract the total damage from the health points of the creature
  void Weak(int points)
  {
    if (points < 0) // validation for the points
    {
      cout << "(negative input!) invalid input for points for Weak " << endl;
      return;
    }
    if (this->alive() == true) // the creature must be alive ohterwise the health points would be already be zero.
    {
      this->health_points -= points; // subtracting health points
      if (this->health_points <= 0)  // if the health points become less than zero, the creature dies and good bye message is called
      {
        this->health_points = 0;
        GoodBye();
      }
    }
    else
    {
      GoodBye(); // if the creature is already dead
    }
  }

  // displays the detail of the crature
  void display()
  {
    cout << " Name: " << this->name << ", level: " << this->level << ", health_status : " << this->health_points << ", force: " << this->force << ", Attacking Points: " << this->AttackPoints() << ", Position: " << this->Position << endl;
  }

  // calculate the distance between the two creatures
  int distance(Creature &obj)
  {
    if (this->Position >= obj.Position) // validation to keep the value of the distance positive
    {
      return (this->Position - obj.Position);
    }
    else // validation to keep the value of the distance positive
    {
      return (obj.Position - this->Position);
    }
  }
};

//_____________________________________________________implementation of the class Dragon
class Dragon : public Creature // inherets the public and protected members of the class creature
{
  int flame_range; // specific member of the class Dragon

public:
  // parameterized constructor to set the values
  Dragon(const string name, int level, int health_points, int force, int flame_range, int Position = 0) : Creature(name, level, health_points, force, Position) // passing values to the constructor of the creature to set
  {
    if (flame_range >= 0) // validation for the parameter flame_range
    {
      this->flame_range = flame_range;
    }
    else
    {
      cout << "(negative input!) invalid input for the flame range" << endl; // error message if the parameter flame_range is negative
    }
  }

  // function to set the position of the dragon to that position where it flew
  void Fly(int set_Position)
  {
    if (set_Position >= 0) // validation of the parameter of the function
    {
      this->Position = set_Position;
    }
    else
    {
      cout << "(negative input!) invalid input for the Position" << endl; // error message if the parameter is negative
    }
  }

  // this function calculates and subtract the damage to the creature, which is attacked by Dragon with blowing flame on it.
  void BlowFlame(Creature &obj)
  {
    if (this->alive() == true && obj.alive() == true && (distance(obj) <= this->flame_range))
    /* damaged to the creature occurs if the both dragon and creature are alive and the distance between the creature and the dragon
    is smaller than or equal to the flame range of the dragon.*/
    {
      obj.Weak(this->AttackPoints()); // subtracting attack points of the dragon from the health points of the creature
      this->Weak(distance(obj));      // subtracting health points of the Dragon = to the distance between the creature and the dragon

      if ((this->alive() == true) && (obj.alive() == false)) // after the attack if the creature dies level of the dragon increses
      {
        this->level++;
      }
    }
  }
};

//______________________________________________________implement of the class Ichneumon
class Ichneumon : public Creature // inherets the public and protected members of the class creature
{
  int neck_length; // specific member of the class Ichneumon
  int poison_dose; // specific member of the class Ichneumon

public:
  // parameterized constructor to set the values
  Ichneumon(string name, int level, int health_points, int force, int neck_length, int poison_dose, int Position = 0) : Creature(name, level, health_points, force, Position) // passing values to the constructor of the creature to set
  {
    if (poison_dose >= 0) // validation for the parameter poison_dose
    {
      this->poison_dose = poison_dose;
    }
    else
    {
      cout << "(negative input!) invalid input for the poison dose" << endl; // error message on the negative parameter poison_dose
    }

    if (neck_length >= 0) // validation for the parameter neck_length
    {
      this->neck_length = neck_length;
    }
    else
    {
      cout << "(negative input!) invalid input for the neck_length" << endl; // error message on the negative parameter neck_length
    }
  }

  // this function calculates and subtract the damage to the creature, which is attacked by Ichneumon with injecting poison in it.
  void InjectPoison(Creature &obj)
  {
    if (this->alive() == true && obj.alive() == true && distance(obj) <= this->neck_length)
    /* damaged to the creature occurs if the both Ichneumon and creature are alive and the distance between the creature and the ichneumon
    is equal to or smaller than neck length of the Ichneumon.*/
    {
      obj.Weak(this->AttackPoints() + this->poison_dose); // subtracting (attack points+poison dose) of the Ichneumon from the health points of the creature.

      if (this->alive() == true && obj.alive() == false) // after the attack if the creature dies level of the Ichneumon increses.
      {
        this->level++;
      }
    }
  }
};

// A function to procceed the fight between the dragon and Ichneumon by initiating the attack of Ichneumon and the dragon respectively.
void Fight(Dragon &objD, Ichneumon &objI)
{
  objI.InjectPoison(objD); // Ichneumon poisoning the dragon.
  objD.BlowFlame(objI);    // dragon blowing flame on the Ichneumon
}

/*-------------------------Main----------------------------------*/
int main()
{
  Dragon dragon("Dragon red", 2, 10, 3, 20);
  Ichneumon ichneumon("ichneumon evil", 2, 10, 1, 10, 1, 42);

  dragon.display();
  cout << "is preparing for fight with :" << endl;
  ichneumon.display();

  cout << endl;
  cout << "1st Fight :" << endl;
  cout << "    the creature-s are not within range, so can not Attacke."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon has flown close to ichneumon :" << endl;
  dragon.Fly(ichneumon.position() - 1);
  dragon.display();

  cout << endl;
  cout << "ichneumon moves :" << endl;
  ichneumon.Move(1);
  ichneumon.display();

  cout << endl;
  cout << "2nd Fight :" << endl;
  cout << ""
       << "+ ichneumon inflicts a 3-point attack on dragon\n"
          " [ level (2) * force (1) + poison (1) = 3 ] ;\n"
          "+ Dragon inflicts a 6-point attack on ichneumon\n"
          "[ level (2) * force (3) = 6 ] ;\n"
          "+ during his attack, dragon loses two additional points\n"
          "      [ corresponding to the distance between dragon and ichneumon : 43 - 41 = 2 ]."
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "Dragon moves by one step " << endl;
  dragon.Move(1);
  dragon.display();

  cout << endl;
  cout << "3rd Fight :" << endl;
  cout << "  + ichneumon inflicts a 3-point attack on dragon \n "
          "    [ level (2) * force (1) + poison (1) = 3 ] ; \n "
          "+ Dragon inflicts a 6-point attack on ichneumon \n "
          "      [ level (2) * force (3) = 6 ] ; \n"
          "+ during his attack, dragon lost 1 additional life point.\n"
          "[ corresponding to the distance between dragon and ichneumon : 43 - 42 = 1 ] ;\n"
          "+ ichneumon is defeated and the dragon rises to level 3"
       << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  cout << endl;
  cout << "4th Fight :" << endl;
  cout << "    when one creatures is defeated, nothing happpens" << endl;
  Fight(dragon, ichneumon);

  cout << "After the Fight :" << endl;
  dragon.display();
  ichneumon.display();

  return 0;
}
