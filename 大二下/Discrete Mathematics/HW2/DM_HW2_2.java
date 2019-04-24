import java.util.*;
import java.lang.*;
public class DM_HW2_2{
    public static void main(String[] argv){
        int wintotal=0;                     //DON'T MODIFY, Result recording
        int losetotal=0;                    //DON'T MODIFY, Result recording
        int pushtotal=0;                    //DON'T MODIFY, Result recording
        for (int round=0;round<20;round++){ //DON'T MODIFY, Play for 20 rounds
            blackjack b=new blackjack();    //DON'T MODIFY, New Round
            
            int[] cards = {4,4,4,4,4,4,4,4,4,16};
            int cardNumber=52;
            
            for(int game=0;game<5;game++){  //DON'T MODIFY, 5 games for each round
            	
            	boolean twentyOne=false, hitOrNot = false,haveAOrNot = false;
            	int myPoint=0;
            	ArrayList<Integer> playerHand=b.getPlayerHand();
            	for(int i :playerHand) {
                	if(i>=10) {
                		cards[9]--;
                		myPoint+=10;
                	}
                	else {
                		cards[i-1]--;
                		myPoint+=i;
                	}
                	if(i==1)
                		haveAOrNot=true;
                	cardNumber--;
                }
            	int knowBankerCard = b.getBankerHand().get(1);
            	if(knowBankerCard>=10) {
            		cards[9]--;
            		myPoint+=10;
            	}
            	else {
            		cards[knowBankerCard-1]--;
            		myPoint+=knowBankerCard;
            	}
            	cardNumber--;
            	
                while(!b.getEnded()){       //DON'T MODIFY
                    //TODO: Your strategy, you can implement it as a function, of course.
                    if(hitOrNot) {
                    	int lastGetCard = b.getPlayerHand().get(b.getPlayerHand().size()-1);
                    	if(lastGetCard>=10) {
                    		cards[9]--;
                    		myPoint+=10;
                    	}
                    	else {
                    		cards[lastGetCard-1]--;
                    		myPoint+=lastGetCard;
                    	}
                    	if(lastGetCard==1 && !haveAOrNot)
                    		haveAOrNot=true;
                    }
                    if(haveAOrNot && myPoint==11)
                    	twentyOne=true;
                    if(!twentyOne && (possibility.lessthan21(cards,myPoint,knowBankerCard,cardNumber,haveAOrNot)>=0.5 || (double)(cards[0]+cards[1])/cardNumber>=0.35)){               //According to strategy, if you want another card 
                        b.playerHit();      //API Example
                        cardNumber--;
                        if(!hitOrNot)
                        	hitOrNot=true;
                    }else{                  //According to strategy, if you don't want another card 
                        b.playerStand();    //API Example
                    }
                }
                
                ArrayList<Integer> bankerHand=b.getBankerHand(); //API Example, when game ended, you can get all cards in banker's hand
                for(int i=0;i<bankerHand.size();i++) {
                	if(i==1)
                		continue;
                	int card = bankerHand.get(i);
                	if(card>=10) {
                		cards[9]--;
                		myPoint+=10;
                	}
                	else {
                		cards[card-1]--;
                		myPoint+=card;
                	}
                	cardNumber--;
                }
                
                int gameResult=b.getGameResult(); //API Example
                if(gameResult==1){          //DON'T MODIFY, Result recording
                    wintotal+=1;            //DON'T MODIFY, Result recording
                }else if(gameResult==0){    //DON'T MODIFY, Result recording
                    pushtotal+=1;           //DON'T MODIFY, Result recording
                }else{                      //DON'T MODIFY, Result recording
                    losetotal+=1;           //DON'T MODIFY, Result recording
                }                           //DON'T MODIFY, Result recording
                b.continueGame();           //DON'T MODIFY, continue game with left cards
            }
        }
        
        System.out.println("WIN : "+wintotal);  //DON'T MODIFY, print result
        System.out.println("PUSH: "+pushtotal); //DON'T MODIFY, print result
        System.out.println("LOSE: "+losetotal); //DON'T MODIFY, print result
    }
}

class possibility{
	public static double lessthan21(int[] cards ,int myPoint, int bankerHand,int cardsUnused,boolean haveAOrNot) {
		double result=0.0;
		if(!haveAOrNot || myPoint>=11) {
			if(myPoint<11)
				result = 1.0;
			else {
				result = 0.0;
				for(int i=1;i<=10;i++) {
					if(myPoint+i<21)
						result += (double)cards[i-1]/cardsUnused;
				}
			}
		}
		else {
			for(int i=1;i<=10;i++) {
				if(myPoint+i<11)
					result += (double)cards[i-1]/cardsUnused;
			}
		}
		return result;
	}
}