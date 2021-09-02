import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class hw2_2{
    
    
static void printPowerSet(String []set, int set_size) 
    {
        long pow_set_size = (long)Math.pow(2, set_size); 
        int counter, j; 
        ArrayList<String> printSet;
      
        /*Run from counter 000..0 to 
        111..1*/
        for(counter = 0; counter < pow_set_size; counter++) 
        { 
            printSet = new ArrayList<String>();
            System.out.print(String.format("%0"+set_size+"d",Integer.parseInt(Integer.toBinaryString(counter))) + ":");
            if(counter == 0){
                System.out.print("EMPTY");
            }
            for(j = 0; j < set_size; j++) 
            { 
                if((counter & (1 << j)) > 0) 
                    printSet.add(set[set_size-1-j]); 
            } 
             
            Collections.sort(printSet);
            for(String strTemp : printSet) 
                System.out.print(strTemp+" "); 
            System.out.println(); 
        } 
    } 

    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Integer set_size;
        String[] set;
        String delimit_set;
        
        set_size = Integer.parseInt(sc.nextLine());
        //crash
        if(set_size == 0){
            System.out.print("0:EMPTY");
            return;
        }
        delimit_set = sc.nextLine();
        
        set = new String[set_size];
        
        set = delimit_set.split(" ", set_size);

        
        printPowerSet(set, set_size);
        
    }
}




