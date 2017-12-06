/**
 * Created by Daniel Satur on 8/10/2017.
 */
import java.util.*;

public class Player {

    //Fields
    ArrayList <Item> bag; //The items the player is carrying in their bag
    double health; //The players current health, if this reaches 0 the game is over and the player loses

    //Constructor
    public Player(){
        this.bag = new ArrayList<>();
        this.health = 100;
    }

}
