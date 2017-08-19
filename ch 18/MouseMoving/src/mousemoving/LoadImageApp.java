package mousemoving;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;
import javax.swing.*;
 
/**
 * This class demonstrates how to load an Image from an external file
 */
public class LoadImageApp extends Component {
           
    BufferedImage img;
    //BufferedImage img2 = toBufferedImage(img);

    @Override
    public void paint(Graphics g) {
        
        g.drawImage(img, 0, 0, 25, 25, null);
        
    }
 
    public LoadImageApp() {
       try {
           img = ImageIO.read(new File("monster.jpg"));
       } catch (IOException e) {
       }
 
    }
    public BufferedImage getImage()
    {
        return img;
    }
    public Dimension getPreferredSize() {
        if (img == null) {
             return new Dimension(100,100);
        } else {
           return new Dimension(500, 500);
       }
    }
    /*
    public static void main(String[] args) {
 
        JFrame f = new JFrame("Load Image Sample");
             
        f.addWindowListener(new WindowAdapter(){
                public void windowClosing(WindowEvent e) {
                    System.exit(0);
                }
            });
 
        f.add(new LoadImageApp());
        f.pack();
        f.setVisible(true);
    }
    */
}
