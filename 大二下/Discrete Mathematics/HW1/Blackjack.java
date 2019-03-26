import java.io.*;
import java.util.ArrayList;

public class Blackjack {
	public void main() throws Exception {
		//read file=============
		String path = "C:\\Users\\User\\Documents\\GitHub\\Chieh\\¤j¤G¤U\\Discrete Mathematics\\HW1\\";
		FileReader fr=new FileReader(path+"input.txt");
        BufferedReader br=new BufferedReader(fr);
        
        String st;
        ArrayList<String>poker = new ArrayList<String>();
        while((st=br.readLine())!=null) {
        	st.replace("J","T");
        	st.replace("Q","T");
        	st.replace("K","T");
        	st.replace("10","T");
        	poker.add(st);
        }
        br.close();
        fr.close();
		//======================
        for(int ii=0;ii<poker.size();ii++) {
        	String eachpoker = poker.get(ii);
        	Poker currentpoker = new Poker();
        	String[] card = eachpoker.split("/");
        	//record cards used
        	if (card[0]!=null) {
        		for(int i=0;i<card[0].length();i++) {
        			if (card[0].charAt(i)==',')
        				continue;
        			currentpoker.used(card[0].charAt(i));
        		}
        	}
        	//record cards got
        	if (card[1]!=null) {
        		for(int i=0;i<card[1].length();i++) {
        			if (card[0].charAt(i)==',')
        				continue;
        			currentpoker.get(card[1].charAt(i));
        		}
        	}
        	
        	ArrayList<Double> answer = currentpoker.nextCardAndPossibility();
        	//write file=========
        	BufferedWriter bw = new BufferedWriter(new FileWriter(path+"output1.txt"));
        	bw.write("D="+(ii+1)+"\n");
        	for(int j=0;j<answer.size();j++) {
        		bw.write(String.format((j+1)+",%.3f\n",answer.get(j)));
        	}
        	bw.close();
        	//===================
        }
	}
}

class Poker{
	private int[] cardnumbers;
	private int point;
	private int numberofA;
	private int totalcardnumber;
	
	Poker(){
		for(int i=0;i<9;i++) {
			cardnumbers[i]=4;
		}
		cardnumbers[9]=16;
		point=0;
		numberofA=0;
		totalcardnumber=52;
	}
	
	public void used(char card) {
		if (card<='9'&card>='2') {
			cardnumbers[(int)card-1]--;
		}
		switch(card) {
		case 'A':
			cardnumbers[0]--;
			break;
		case 'T':
			cardnumbers[9]--;
			break;
		}
		totalcardnumber--;
	}
	
	public void get(char card) {
		used(card);
		if (card<='9'&card>='2') {
			point+=(int)card;
			return;
		}
		switch(card) {
		case 'A':
			point++;
			numberofA++;
			break;
		case 'T':
			point+=10;
			break;
		};
	}
	
	public void back(char card) {
		if (card<='9'&card>='2') {
			cardnumbers[(int)card-1]++;
			point-=(int)card;
		}
		switch(card) {
		case 'A':
			cardnumbers[0]--;
			point--;
			numberofA--;
			break;
		case 'T':
			cardnumbers[9]--;
			point-=10;
			break;
		}
		totalcardnumber++;
	}
	
	public int getPoint() {
		if(numberofA==0) {
			return point;
		}
		else {
			if(point+10<=21) {
				return point+=10;
			}
			else {
				return point;
			}
		}
	}
	
	public int assumeGetCard_point(char card) {
		get(card);
		int assumePoint;
		assumePoint = getPoint();
		back(card);
		return assumePoint;
	}
	
	public int getTotalCardNumber() {
		return totalcardnumber;
	}
	
	public ArrayList<Double> nextCardAndPossibility() {
		ArrayList<Double> result = new ArrayList<Double>(31);
		result.add(assumeGetCard_point('A'),(double) (cardnumbers[0]/totalcardnumber));
		result.add(assumeGetCard_point('T'),(double) (cardnumbers[9]/totalcardnumber));
		for(int i=2;i<=9;i++) {
			result.add(assumeGetCard_point((char)i),(double) (cardnumbers[i-1]/totalcardnumber));
		}
		return result;
	}
}
