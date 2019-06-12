
public class Hand {
	boolean ace;
	int point;
	Hand(){
		ace = false;
		point = 0;
	}
	public void get(int card){
		if(card==1) {
			ace = true;
			point += 1;
		}
		else if(card>=2 && card<=10)
			point += card;
		else
			point += 10;
	}
	public int getPointA11() {
		return point<=11?point+10:point;
	}
	public int getPoint() {
		return point;
	}
	public boolean withAOrNot() {
		return ace;
	}
}
