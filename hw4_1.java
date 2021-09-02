/*
 * 
 * Title: hw4_1.cpp
 * Abstract: . 1. Write a C++ (or Java) program named hw4_1.cpp (or hw4_1.java) to solve the Knapsack problem. To recall the Knapsack problem, 
 watch this video: https://youtu.be/OC85aM7SFts Or you can check it at the slide number 28 and 29 of the lecture_3.ppt on the iLearn.
For the homework, your program should read the weight and value of each item from a user and determine the best subset. 
In the homework, you can assume that the number of items is less than 15. Also, you should assume that each item has only one. 

 * Author: Karandeep Singh
 * ID: 2004
 * Date: 02/21/2021
 */

import java.util.*;
import java.util.ArrayList;

public class hw4_1 {

    public int value, size;
    public ArrayList<Integer> stored_items = new ArrayList<>();
    
    hw4_1(){
        value = 0;
        size = 0;
    }
    
    public static hw4_1 convert_subset(ArrayList<ArrayList<Integer>> subset, int capacity){
        hw4_1 object = new hw4_1();
        for(int i = 0; i < subset.size(); i++){
            if(object.size+subset.get(i).get(0) <= capacity){
                object.size += subset.get(i).get(0);
                object.value += subset.get(i).get(1);
                object.stored_items.add(subset.get(i).get(2) + 1);
            }else{
                return new hw4_1();
            }
        }
        return object;
    }

    public String toString(boolean flag){//overriding the toString() method
        if(flag){
            return ("Item:" + "Multiple solutions" + "\n" + "Capacity:" + size + "\n" + "Value:" + value + "\n").replace("[", "").replace("]", "").replace(",", "");

        }
        return ("Item:" + stored_items + "\n" + "Capacity:" + size + "\n" + "Value:" + value + "\n").replace("[", "").replace("]", "").replace(",", "");
    }


    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        Integer num_items, capacity;

        num_items = scanner.nextInt();
        capacity = scanner.nextInt();

        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        for(int i = 0; i < num_items; i++){
           ArrayList<Integer> temp_list = new ArrayList<>();
            for(int k = 0; k < 2; k++){
                temp_list.add(scanner.nextInt());
            }
            temp_list.add(i);
            list.add(temp_list);
        }
     //   System.out.print(list);
        Integer pow_set_size = (int)(Math.pow(2, num_items));
        ArrayList<ArrayList<ArrayList<Integer>>> power_set = new ArrayList<>();

        for(int counter = 0; counter < pow_set_size; counter++)
        {
            ArrayList<ArrayList<Integer>> temp_list = new ArrayList<>();
            for(int j = 0; j < num_items; j++)
            {
                if((counter & (1 << j)) > 0)
                    temp_list.add(list.get(j));
            }

            power_set.add(temp_list);
        }
        ArrayList<hw4_1> array_of_objects = new ArrayList<>();
        for(ArrayList<ArrayList<Integer>> new_list: power_set){
            array_of_objects.add((hw4_1.convert_subset(new_list, capacity)));
        }
        int max_index = 0;
        int max_value = 0;
        boolean flag = false;
        for(int i = 0; i < array_of_objects.size(); i++){
            if(max_value < array_of_objects.get(i).value){
                max_index = i;
                max_value = array_of_objects.get(i).value;
                flag = false;
            }else if(max_value == array_of_objects.get(i).value){
                flag = true;

            }
        }
        //System.out.println(array_of_objects);
        System.out.println(array_of_objects.get(max_index).toString(flag));
    }
}
