/**
 * Created by Daniel Satur on 8/10/2017.
 */
import java.util.ArrayList;

public class Pod {

    //Fields
    String podName; //The name of the current pod (e.g Pod 11, etc)
    boolean hasRecoveryKit; //Whether or not the pod contains a recovery kit
    boolean hasDataCache; //Whether or not the pod contains the data cache
    ArrayList <Pod> portals; //A list of the portals to other pods
    Trap podTrap; //A trap in the pod
    ArrayList <Item> podsItems; //A list of the items on the ground of the pod to be picked up

    public Pod(String podName, boolean hasRecoveryKit, boolean hasDataCache){
        this.podName = podName;
        this.hasRecoveryKit = hasRecoveryKit;
        this.hasDataCache=hasDataCache;
        this.portals=new ArrayList<>();
        this.podsItems = new ArrayList<>();

    }

    public void addPortalTo(Pod newPod){
        this.portals.add(newPod);
    }

    public Trap getTrap(){
        return this.podTrap;
    }

    public void setTrap(Trap newTrap){
        this.podTrap = newTrap;
    }

    public void addItem(Item newItem){
        podsItems.add(newItem);
    }

    public String getDescription(){
        return this.podName;
    }

}
