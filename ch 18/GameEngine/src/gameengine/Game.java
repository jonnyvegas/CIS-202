/**
File: Game.java
Description:Download the event simulator for the game engine discussed in class.  
* Generalize the MonsterSimulator and HeroSimulator classes so that the hit 
* types are in a base class.  Combine the code from the event simulator with the 
* game engine so that a fight can be simulated between the monster and the hero. 
* Add effects to the monster and the hero so that when there is a hit, damage is 
* done to either character.   Add a member to the Character class which 
* represents the life of the character so at the end of the fight, it is known 
* which character has more life (or wins).
Author: Jonathan Villegas
mail: jonathan.e.villegas@gmail.com
Date: 5/18/14
**/

package gameengine;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class Game {
   
   public static void main(String [] args){
    Scanner input = new Scanner(System.in);
    int numOfEvents;
    boolean next_to = false;
    System.out.print("Please enter the number of rounds you would like to simulate: ");
    numOfEvents = input.nextInt();
    Hero the_hero = new Hero(numOfEvents);
    Monster the_monster = new Monster(numOfEvents);
    //Start the hero at the bottom and the monster on the opposite side.
    the_hero.setCoordinates(0, 0);
    the_monster.setCoordinates(10, 10);
    //Move the characters until they meet up.
    /*
    while(!next_to)
    {
        move(the_hero, the_monster);
        if(the_hero.standingNextTo(the_monster))
        {
            next_to = true;
        }
    }
    if(next_to)//If they are standing next to each other, they will fight.
    {
        System.out.println("They are next to each other!!! A battle ensues!!!");
        fight(the_hero, the_monster, numOfEvents);
    }
    */
    System.out.println("Hero Stats:\n"+the_hero.getStats());
    System.out.println("Monster Stats:\n"+the_monster.getStats());
    }
   //Moves the characters.
   public static void move(CharacterClass char1, CharacterClass char2)
   {
       Random r;
       Random r2;
       r = new Random();
       r2 = new Random();
       int num1 = Math.abs(r.nextInt()) % 4 + 0;
       int num2 = Math.abs(r2.nextInt()) % 4 + 0;
       //Move the characters between 0-4 spaces.
       System.out.println("Moving the hero...");
       char1.move(num1);
       System.out.println("Moving the monster...");
       char2.move(num2);
       if(char1.standingNextTo(char2))
       {
           System.out.println("Standing next to each other.");
       }
       else
       {
           System.out.println("Not standing next to each other.");
       }
   }

    /**
     *Function to have the two types fight based on the number of events.
     * @param the_hero the character class for the hero
     * @param the_monster the character class for the montser
     * @param numOfEvents the number of events to simulate
     */
    public static void fight(CharacterClass the_hero, CharacterClass the_monster, int numOfEvents)
   {
       int i = 0;
       //While neither one is dead and the number of events hasn't gone past
       while(the_hero.getHealth() > 0 && the_monster.getHealth() > 0 && i < numOfEvents)
        {
            i++;
            Event heroHit = the_hero.nextEvent();
            Event monsterHit = the_monster.nextEvent();
            the_hero.setDamage(heroHit.execute(the_hero));
            System.out.println("Health left for Hero: " + the_hero.getHealth());
            the_monster.beAttacked(the_hero.getDamage());
            the_monster.setDamage(monsterHit.execute(the_monster));
            System.out.println("Health left for Monster: " + the_monster.getHealth());
            the_hero.beAttacked(the_monster.getDamage());
        }

      if(the_hero.getHealth() <= 0)
      {
          System.out.println("Hero dies.");
      }
      else if (the_monster.getHealth() <= 0)
      {
          System.out.println("Monster dies.");
      }
      else if(the_monster.getHealth() < the_hero.getHealth())
      {
          System.out.println("Hero wins with more health.");
      }
      else if (the_hero.getHealth() < the_monster.getHealth())
      {
          System.out.println("Monster wins with more health.");
      }
      else
      {
          System.out.println("They tied?!!!?");
      }
   }
}
