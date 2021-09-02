import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeMap;


public class hw3_1 {

    public static void main(String[] args) {
        String input1, input2;

        Scanner sc = new Scanner(System.in);

        input1 = sc.next();
        input2 = sc.next();

        TreeMap<Character, Integer> charCount1 = new TreeMap<>();
        TreeMap<Character, Integer> charCount2 = new TreeMap<>();

        if(input1.length() == input2.length()){
            for(int i = 0; i<input1.length(); i++){
                charCount1.put(input1.charAt(i), 0);
            }

            for(int i = 0; i<input1.length(); i++){
                charCount1.put(input1.charAt(i), charCount1.get(input1.charAt(i))+1);
            }

            for(int i = 0; i<input2.length(); i++){
                charCount2.put(input2.charAt(i), 0);
            }

            for(int i = 0; i<input2.length(); i++){
                charCount2.put(input2.charAt(i), charCount2.get(input2.charAt(i))+1);
            }
            if(charCount1.equals(charCount2)){
                System.out.println("ANAGRAM");

                for (Map.Entry<Character,Integer> entry : charCount1.entrySet()){
                    System.out.println(entry.getKey()+ ":" + entry.getValue());
                }

            }else{
                System.out.println("NO ANAGRAM");

            }
            

        }else{
            System.out.println("NO ANAGRAM");
        }

      //  Map<Character, Integer> treeMap1 = new TreeMap<>(charCount1);
      //  Map<Character, Integer> treeMap2 = new TreeMap<>(charCount2);




    }
}
