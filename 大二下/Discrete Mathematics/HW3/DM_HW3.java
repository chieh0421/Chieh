import java.util.*;
import java.lang.*;
import java.util.Random;

public class DM_HW3{
    public static void main(String[] argv){
        int timeAccu=0;
        
        Strategy stra = new Strategy();
        
        blackjack b=new blackjack();            //DONT MODIFY
        for(int game=0;game<5;game++){          //DONT MODIFY
            long startTime = System.currentTimeMillis(); //DONT MODIFY
            
            ArrayList<Integer> playerHand=b.getPlayerHand();
            ArrayList<Integer> bankerHand=b.getBankerHand();
            if(game == 0) {
            	stra.Init(playerHand,bankerHand.get(1));
            }
            else {
            	stra.gameUpdate(playerHand,bankerHand.get(1));
            }
            
            while(!b.getEnded()){               //DONT MODIFY
                //ArrayList<Integer> playerHand=b.getPlayerHand();    //API Example, get player's card as an ArrayList
                //ArrayList<Integer> bankerHand=b.getBankerHand();    //API Example, get banker's card as an ArrayList (first one will be -1 if not standed yet)
                //int remainChip=b.getPlayerChip();                   //API Example, get remaining chip as int
                //int bet=b.getBet();                                 //API Example, get bet of this game as int
                //b.getMsg();                                         //API Example, print msg while debugging

                //TODO: Your strategy here
                int decision = stra.decision();
                if(decision==0){
                    //hit
                    b.playerHit();
                    stra.get(b.getPlayerHand().get(b.getPlayerHand().size()-1));
                }else if(decision==1){
                    //double (double bet, hit, stand) (bet will be reset to default (20) in next game)
                    b.playerDouble();
                    stra.get(b.getPlayerHand().get(b.getPlayerHand().size()-1));
                }else{
                    //stand
                    b.playerStand();
                }

            }
            
            int gameResult=b.getGameResult();                       //API Example, get result as int (-1 for lose, 0 for push, 1 for win)
            bankerHand=b.getBankerHand();        //API Example, now you can access all of the cards of banker without masking
            for(int i=0;i<bankerHand.size();i++) {
            	if(i==1)
            		continue;
            	stra.update(bankerHand.get(i));
            }
            
            if(game!=4){
                b.continueGame();                   //DONT MODIFY
            }
            timeAccu+=(System.currentTimeMillis()-startTime); //DONT MODIFY
        }
        System.out.println("FINAL REMAINING CHIP: "+b.getPlayerChip());   //DONT MODIFY
        System.out.println("TIME USED: "+timeAccu); //DONT MODIFY
    }
}