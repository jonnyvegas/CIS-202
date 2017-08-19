/**
File: GridLinesPanel.java
Description: Draw a grid using java. The grid should be 25x25.
Author: Jonathan Villegas
mail: jonathan.e.villegas@gmail.com
Date: 5/18/14
**/

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JPanel;

public class GridLinesPanel extends JPanel {

   public GridLinesPanel() {
   
   }
   
   public void paintComponent(Graphics g) {
   
      super.paintComponent(g);  // Call the paintComponent method from the 
                                // superclass, JPanel.  This simply fills the 
                                // entire panel with the background color, black.
      
      int size = 500, gap = 20;
      //Draws a grid based on the size of the pixels and the gap between each square.
      //This will output a blue 25x25 grid.
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

   } // end paintComponent()
   

}  // end class GridLinesPanel
