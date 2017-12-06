/**
 * Created by Daniel Satur on 8/10/2017.
 */
import java.util.ArrayList;

public class Trap {

    //Fields
    String trapName; //The description of the trap
    ArrayList<Item> itemsForTrap; //A list of the items needed to diffuse the trap
    boolean trapOnline; //Whether or not the trap has been disabled

    public Trap(String trapName, ArrayList<Item> itemsForTrap){
        this.trapName=trapName;
        this.itemsForTrap = itemsForTrap;
        this.trapOnline = true;
    }

    public String getDescription(){return this.trapName;}

}
