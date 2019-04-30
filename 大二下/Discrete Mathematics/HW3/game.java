import java.util.*;
import java.lang.*;
import java.util.Random;

public class game{
    public static void main(String[] argv){
        int timeAccu=0;
        blackjack b=new blackjack();            //DONT MODIFY
        for(int game=0;game<5;game++){          //DONT MODIFY
            long startTime = System.currentTimeMillis(); //DONT MODIFY
            while(!b.getEnded()){               //DONT MODIFY
                ArrayList<Integer> playerHand=b.getPlayerHand();    //API Example, get player's card as an ArrayList
                ArrayList<Integer> bankerHand=b.getBankerHand();    //API Example, get banker's card as an ArrayList (first one will be -1 if not standed yet)
                int remainChip=b.getPlayerChip();                   //API Example, get remaining chip as int
                int bet=b.getBet();                                 //API Example, get bet of this game as int
                b.getMsg();                                         //API Example, print msg while debugging

                //TODO: Your strategy here

                if(...){
                    //hit
                    b.playerHit();
                }else if(...){
                    //double (double bet, hit, stand) (bet will be reset to default (20) in next game)
                    b.playerDouble();
                }else{
                    //stand
                    b.playerStand();
                }

            }
            
            int gameResult=b.getGameResult();                       //API Example, get result as int (-1 for lose, 0 for push, 1 for win)
            ArrayList<Integer> bankerHand=b.getBankerHand();        //API Example, now you can access all of the cards of banker without masking
            if(game!=4){
                b.continueGame();                   //DONT MODIFY
            }
            timeAccu+=(System.currentTimeMillis()-startTime); //DONT MODIFY
        }
        System.out.println("FINAL REMAINING CHIP: "+b.getPlayerChip());   //DONT MODIFY
        System.out.println("TIME USED: "+timeAccu); //DONT MODIFY
    }
    
}