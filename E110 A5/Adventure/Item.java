/**
 * Created by Daniel Satur on 8/10/2017.
 */
public class Item {

    //Fields
    String itemName; //The description of the item
    double weight; //The weight of the item

    public Item (String itemName, double weight){
        this.itemName = itemName;
        this.weight = weight;
    }
    public String getDescription(){
        return this.itemName;
    }
}
