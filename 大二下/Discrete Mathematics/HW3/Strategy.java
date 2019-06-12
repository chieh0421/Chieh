import java.util.*;

public class Strategy {
	Cards status;
	Hand hand;
	int banker;
	Strategy(){
		status = new Cards();
		hand = new Hand();
	}
	public void Init(ArrayList<Integer> handIn, int bankerIn) {
		for(int i=0;i<handIn.size();i++) {
			get(handIn.get(i));
		}
		update(bankerIn);
		banker = bankerIn;
	}
	public void gameUpdate(ArrayList<Integer> playerHand, int card) {
		hand = new Hand();
		for(int i=0;i<playerHand.size();i++) {
			get(playerHand.get(i));
		}
		update(card);
		banker = card;
	}
	public void update(int card) {
		status.used(card);
	}
	public void get(int card) {
		status.used(card);
		hand.get(card);
	}
	
	public int decision() {  // 1 for double  0 for hit   -1 for stand
		if(banker==1 && hand.withAOrNot()) {
			if(hand.getPoint()<=11) {
				if(hand.getPointA11()>=20)
					return -1;
				else if(hand.getPointA11()>=16) {
					if((status.getBig()+status.getMid())<=10)
						return 1;
					else
						return 0;
				}
				else {
					if((status.getBig()+status.getSmall())<=16)
						return 1;
					else
						return 0;
				}
			}
			else {
				if(hand.getPoint()>=19)
					return -1;
				else if(hand.getPoint()>=15) {
					if((status.getBig()+status.getMid())<=10)
						return 1;
					else
						return 0;
				}
				else
					return 0;
			}
		}
		else if(banker==1 && !hand.withAOrNot()) {
			if(hand.getPoint()>=19)
				return -1;
			else if(hand.getPoint()>=17) {
				if((status.getBig()+status.getMid())<=10)
					return 1;
				else
					return -1;
			}
			else if (hand.getPoint()>=13) {
				if(status.getBig()<=(status.getMid()+status.getSmall()))
					return 1;
				else
					return 0;
			}
			else if(hand.getPoint()>=11) {
				if(status.getBig()>=(status.getMid()+status.getSmall()))
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else if(hand.withAOrNot()) {
			if(hand.getPoint()<=11) {
				if(hand.getPointA11()>=20)
					return -1;
				else if(hand.getPointA11()>=16) {
					if((status.getBig()+status.getMid())<=10)
						return 1;
					else
						return 0;
				}
				else {
					if((status.getBig()+status.getSmall())<=16)
						return 1;
					else
						return 0;
				}
			}
			else {
				if(hand.getPoint()>=19)
					return -1;
				else if(hand.getPoint()>=15) {
					if((status.getBig()+status.getMid())<=10)
						return 0;
					else
						return -1;
				}
				else
					return 0;
			}
		}
		else {
			if(banker>=7) {
				if((status.getBig()+status.getMid())>=status.getSmall() && hand.getPoint()<=12)
					return 0;
				else if(hand.getPoint()<=17)
					return 0;
				else
					return -1;
			}
			else {
				if(hand.getPoint()>=17)
					return -1;
				else
					return 0;
			}
		}
	}
}
