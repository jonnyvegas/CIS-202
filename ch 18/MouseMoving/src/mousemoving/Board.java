/**
File: Board.java
Description: Draw a grid using java and 
* modify the grid so that when a square is clicked, you know which
* one is clicked and toggle a hit on the board.
Author: Jonathan Villegas
mail: jonathan.e.villegas@gmail.com
Date: 5/18/14
**/

package mousemoving;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *This class is a board and overrides the paint class,
 *which draws a grid.
 * @author Jonny
 */
public class Board extends JPanel{

    public Board(Color color) {
        setBackground(color);
    }
    
    @Override
    public void paint(Graphics g) {
        //Size of the grid in pixels.
        int size = 500;
        //Gap between each square in pixels.
        int gap = 20;
        
        //Draws the grid based on the size of the grid and the gap between each
        //square.
        for(int i = 0; i < size; i += gap)
        {
            for(int j = 0; j < size; j += gap)
            {
                g.setColor(Color.blue);
                g.fillRect(i, j, gap, gap);
                g.setColor(Color.black);
                g.drawRect(i, j, gap, gap);
                
            }
        }  	
    }   
}

