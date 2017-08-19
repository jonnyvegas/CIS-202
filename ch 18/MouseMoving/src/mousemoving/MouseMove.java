/**
File: MouseMove.java
Description: Draw a grid using java and 
* modify the grid so that when a square is clicked, you know which
* one is clicked and toggle a hit on the board.
Author: Jonathan Villegas
mail: jonathan.e.villegas@gmail.com
Date: 5/18/14
**/

package mousemoving;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;

import javax.swing.*;

public class MouseMove extends JPanel implements MouseListener {
    /**
    * 
    */
    private static final long serialVersionUID = 1L;
    private final int num_of_boxes = 625;
    //Create an array for all the squares.
    boolean panels[] = new boolean[num_of_boxes];
    //Create a new board.
    Board board;
    JTextArea textArea;
    static final String NEWLINE = System.getProperty("line.separator");
    
    public static void main(String[] args) {
        
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                createAndShowGUI();
            }
        });
    
    }
    
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("MouseEventDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //Create and set up the content pane.
        JComponent newContentPane = new MouseMove();
        newContentPane.setOpaque(true); //content panes must be opaque
        frame.setContentPane(newContentPane);
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }
    
    public MouseMove() {
        super(new GridLayout(0,1));
        setFocusable(true);
        //New board with a blue color.
        board = new Board(Color.blue);
        //Add the board to the panel.
        add(board);
        //Register for mouse events on blankArea and the panel.
        board.addMouseListener(this);
        addMouseListener(this);
        //Size in pixels of the grid.
        int sizeX = 500;
        int sizeY = 500;
        setPreferredSize(new Dimension(sizeX, sizeY));
    }
    
    void eventOutput(String eventDescription, MouseEvent e) {
    	System.out.println(eventDescription + " detected on "
                + e.getComponent().getClass().getName()
                + "." + NEWLINE);
    }
    
    @Override
    public void mousePressed(MouseEvent e) {
        eventOutput("Mouse pressed (# of clicks: " 
                + e.getClickCount() + ") and had " , e);
    }
    
    @Override
    public void mouseReleased(MouseEvent e) {
        //Get the x, y location of the mouse event for release.
    	Point p = e.getPoint();
    	int X = (int)p.getX();
    	int Y = (int)p.getY();
    	
        int theBoxX;
        int theBoxY;
        //Size of each box in pixels.
        int size_of_box = 20;
        theBoxX = (X / size_of_box) + 1;
        theBoxY = (Y / size_of_box) + 1;
        
        System.out.println("Mouse was clicked in row: " + theBoxY);
        System.out.println("Mouse was clicked in column: " + theBoxX);
        int j = 0;
        int size_of_row = 25;
        for(int i = 1; i <= size_of_row; i++)
        {
            if(theBoxY == i)//If the box we are at is the one clicked in the row
            {
                System.out.println("Box number " + (theBoxX + j) + " was clicked.");
                //Updates the panel and sees which box was clicked.
                updatePanel((theBoxX + j), num_of_boxes);
            }
            //Add 25 so that it is the next row and we can check each box by column.
            j += size_of_row;
        }
        repaint();
        
    }
    
    @Override
    public void mouseEntered(MouseEvent e) {
    }
    
    @Override
    public void mouseExited(MouseEvent e) {
    }
    
    @Override
    public void mouseClicked(MouseEvent e) {
        
    }
    
    public void updatePanel(int theBox, int boxes)
    {
        //Check every box in the array.
        for(int i = 1; i <= boxes; i++)
        {
            panels[i - 1] = false;
            if(theBox == i)//The box passed is the one we are currently at.
            {                
                //Change to true so we know it is painted.
                panels[i - 1] = true;         
                System.out.println("Updated for box " + i);
            }
        }
    }
    
    @Override
    public void paint(Graphics g) {
        try {
            int theX = 500;
            int theY = 500;
            int the_gap = 20;
            
            for(int i = 0; i < theX; i += the_gap)
            {
                for(int j = 0; j < theY; j += the_gap)
                {
                    //Draw two squares so that there will be a black outline.
                    g.setColor(Color.blue);
                    g.fillRect(i, j, the_gap, the_gap);
                    g.setColor(Color.black);
                    g.drawRect(i, j, the_gap, the_gap);
                }
            }
            
            //This is where I need to add code to import a picture and use it
            //instead of the yellow to fill with the hero or monster.
            File the_file = new File("hero.jpg");
            BufferedImage img;
            img = ImageIO.read(the_file);
            int w = img.getWidth(null);
            int h = img.getHeight(null);
            //BufferedImage bi = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
            //g = bi.getGraphics();
            //g.drawImage(img, 0, 0, null);
            int index1 = 1;
            int index2 = 0;
            int num_per_row = 25;
            //Check every square in the array.
            for(int k = 1; k <= num_of_boxes; k++)
            {
                if(panels[k-1] == true)//The panel in the array has been clicked
                {
                    //Paint a yellow square.
                    //g.setColor(Color.yellow);
                    g.drawImage(img, ((k - index1) * the_gap), index2, the_gap, the_gap, null);
                    //g.fillRect(((k - index1) * the_gap), index2, the_gap, the_gap);
                    g.setColor(Color.black);
                    g.drawRect(((k - index1) * the_gap), index2, the_gap, the_gap);
                }
                if(k % num_per_row == 0)//If we are on a multiple of 25
                {
                    //Increase the index so the x painted will be on the next row.
                    index1 += num_per_row;
                    //Increase the second index so that the correct y will be painted.
                    index2 += the_gap;
                }
            }
        } catch (IOException ex) {
        }
    }
}   

