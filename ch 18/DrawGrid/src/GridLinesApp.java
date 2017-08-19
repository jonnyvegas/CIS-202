/**
File: GridLinesApp.java
Description: Draw a grid using java. The grid should be 25x25.
Author: Jonathan Villegas
mail: jonathan.e.villegas@gmail.com
Date: 5/18/14
**/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class GridLinesApp { 
  
  //static private GridLinesPanel paintPanel;

  private static void createAndShowGUI() {
	  JFrame frame = new JFrame("GridLines");
	  frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	  GridLinesPanel paintPanel = new GridLinesPanel();
          int theX = 500, theY = 500;
	  paintPanel.setPreferredSize(new Dimension(theX,theY));
	  frame.getContentPane().add(paintPanel,BorderLayout.CENTER);

	  frame.pack();
	  frame.setVisible(true);
  }

  public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }
}
