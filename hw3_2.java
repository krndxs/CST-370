import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.Collections;

public class hw3_2{
    public static void printGraph(HashMap<Integer, ArrayList<Integer>> graph){
        for (Map.Entry<Integer,ArrayList<Integer>> entry : graph.entrySet()){
            System.out.print(entry.getKey());
            for (Integer i : entry.getValue()){
                System.out.print("->"+i);
            }
            System.out.print("\n");
        }
    }
    
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        int vertices_amount;
        int edges_amount;
        vertices_amount = in.nextInt();
        edges_amount = in.nextInt();
        for (int i = 0; i < vertices_amount; i++){
            graph.put(i, new ArrayList<>());
        }
        for (int i = 0; i < edges_amount; i++){
            graph.get(in.nextInt()).add(in.nextInt());
        }
        for (int i = 0; i < vertices_amount; i++){
            Collections.sort(graph.get(i));
        }
        printGraph(graph);
    }
    
}