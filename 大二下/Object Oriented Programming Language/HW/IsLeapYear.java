
public class IsLeapYear {
	public boolean determine(int y) {
		if (y%400==0)
			return true;
		else if(!(y%100==0)&&y%4==0)
			return true;
		else 
			return false;
	}
}
