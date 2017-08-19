/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package someproject;
import java.util.Random;

/**
 *
 * @author Jonny
 */
public class SomeProject {

    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        Random randomNum = new Random();
        for (int index = 1; index <=10; index++)
        {
            showRandomInteger(0, 100, randomNum);
        }
    }
    
}
