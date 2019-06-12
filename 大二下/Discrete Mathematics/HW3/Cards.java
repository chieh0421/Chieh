
public class Cards {
	int Small;//1~4
	int Mid;  //5~7
	int Big;  //8~10
	Cards(){
		Small = 16;
		Mid = 12;
		Big = 24;
	}
	
	public void used(int card) {
		if(card<=4) 
			Small--;
		else if(card>=8)
			Big--;
		else
			Mid--;
	}
	
	public int getSmall() {
		return Small;
	}
	public int getMid() {
		return Mid;
	}
	public int getBig() {
		return Big;
	}
}
