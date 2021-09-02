import java.util.Scanner;

public class hw2_1{
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String time1, time2, temp_time, temporary_hours, temporary_minutes, temporary_seconds, final_temp_time;
        Integer hours1, minutes1, seconds1, hours2, minutes2, seconds2, temp_hours, temp_minutes, temp_seconds;
        
        
        time1 = sc.next();
        time2 = sc.next();
        
        //System.out.println(time1);
        //System.out.println(time2);
        
        hours1 = Integer.valueOf(time1.substring(0,2));
        minutes1 = Integer.valueOf(time1.substring(3, 5));
        seconds1 = Integer.valueOf(time1.substring(6, 8));
        
        hours2 = Integer.valueOf(time2.substring(0,2));
        minutes2 = Integer.valueOf(time2.substring(3, 5));
        seconds2 = Integer.valueOf(time2.substring(6, 8));
        
        //hours2 = time2.substring(0,2);
        //minutes2 = time2.substring(3, 4);
        //seconds2 = time2.substring(6, 7);
        
        //System.out.println(hours1);
        //System.out.println(minutes1);
        //System.out.println(seconds1);
        
        temp_hours = (hours2 - hours1);
        temp_minutes = (minutes2 - minutes1);
        temp_seconds = (seconds2 - seconds1);
        
        
        if(temp_seconds < 0){
            temp_minutes--;
            temp_seconds += 60;
        }
        if(temp_seconds < 10){
            temporary_seconds = "0" + temp_seconds;
        }else{
            temporary_seconds = Integer.toString(temp_seconds);
        }
         
        if(temp_minutes < 0){
            temp_hours--;
            temp_minutes +=60;
        } 
        if(temp_minutes < 10){
            temporary_minutes = "0" + temp_minutes;
        }else{
            temporary_minutes = Integer.toString(temp_minutes);
        }
        
        if(temp_hours < 0){
            temp_hours += 24;
        }
        
        if(temp_hours < 10){
            temporary_hours = "0" + temp_hours;
        }else{
            temporary_hours = Integer.toString(temp_hours);
        }
        
        
        final_temp_time = temporary_hours + ":" + temporary_minutes + ":" + temporary_seconds; 
        System.out.println(final_temp_time);
        
    }   

}


