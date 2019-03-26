import java.io.*;
import java.util.ArrayList;

public class Blackjack_1_2 {
	public static void main(String[] args) throws Exception {
		//read file=============
		String path = "C:\\Users\\User\\Documents\\GitHub\\Chieh\\¤j¤G¤U\\Discrete Mathematics\\HW1\\";
		FileReader fr=new FileReader(path+"input.txt");
        BufferedReader br=new BufferedReader(fr);
        
        String st;
        ArrayList<String>poker = new ArrayList<String>();
        while((st=br.readLine())!=null) {
        	st=st.replaceAll("J","T");
        	st=st.replaceAll("Q","T");
        	st=st.replaceAll("K","T");
        	st=st.replaceAll("10","T");
        	poker.add(st);
        }
        br.close();
        fr.close();
		//======================
        
        double[] possibilityArray = new double[7];
        for(int ii=0;ii<poker.size();ii++) {
        	String eachpoker = poker.get(ii);
        	Poker currentpoker = new Poker();
        	boolean right = false;//false:used true:got
        	for(int i=0;i<eachpoker.length();i++) {
        		char card = eachpoker.charAt(i);
        		if (card=='/') {
        			right=true;
        			continue;
        		}
        		if (card==',')
        			continue;
        		if(right)
        			currentpoker.get(card);//record cards got
        		else
        			currentpoker.used(card);//record cards used
        	}
        	possibilityArray[ii] = currentpoker.explodePossibility();
        }
        
      //write file=========
    	BufferedWriter bw = new BufferedWriter(new FileWriter(path+"output2.txt"));
    	for(int i=0;i<possibilityArray.length;i++) {
    		bw.write("D="+(i+1)+System.getProperty("line.separator"));
    		bw.write(String.format("%.3f", possibilityArray[i])+System.getProperty("line.separator"));
    	}
    	bw.close();
    	//===================
	}
}

class Poker{
	private int[] cardnumbers=new int[10];
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
		if (card<='9'&&card>='2') {
			cardnumbers[card-'1']--;
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
		if (card<='9'&&card>='2') {
			point+=(int)(card-'0');
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
	
	public double explodePossibility() {
		double possibility=0.00;
		if(point>11) {
			int cardsNumber=0;
			for (int i =9;i>=(21-point);i--) {
				cardsNumber+=cardnumbers[i];
			}
			possibility = (double)cardsNumber/(double)totalcardnumber;
		}
		return possibility;
	}
	
}