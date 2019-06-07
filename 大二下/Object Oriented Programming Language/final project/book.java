import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import org.json.simple.parser.ParseException;

import com.opencsv.CSVReader;

public class book {
	public static void book() throws IOException, ParseException, java.text.ParseException {
		System.out.println("enter<user id>,<hotel id>,<checkin>,<checkout>,<room type>,<room count>");
		System.out.println("ex: a123,0,5/16,5/20,double,20");
		ArrayList<Hotel> mainhotellist = ReadJSON.Reader();
		int[] everydayhotel = new int[365];
		Scanner ava = new Scanner(System.in);
		String cmd_str = ava.nextLine();
		String[] cmd_arr = cmd_str.split(",");

		// parse
		String[] checkindate = cmd_arr[2].split("/");
		int checkinmonth = Integer.parseInt(checkindate[0]);
		int checkinday = Integer.parseInt(checkindate[1]);
		String[] checkoutdate = cmd_arr[3].split("/");
		int checkoutmonth = Integer.parseInt(checkoutdate[0]);
		int checkoutday = Integer.parseInt(checkoutdate[1]);
		int daybetween = Hotel.datetonumber(checkoutmonth, checkoutday) - Hotel.datetonumber(checkinmonth, checkinday) + 1;
		// check every room's booking state
		for (int i = 0; i < daybetween; i++) {
			CSVReader reader = new CSVReader(new FileReader("data.csv"));
			String[] nextLine;
			while ((nextLine = reader.readNext()) != null) {
				if (nextLine[1].equals(cmd_arr[1]) && nextLine[2].equals(cmd_arr[4])
						&& nextLine[4].equals(Integer.toString(Hotel.datetonumber(checkinmonth, checkinday + i)))) {
					everydayhotel[Hotel.datetonumber(checkinmonth, checkinday + i)] += Integer.parseInt(nextLine[3]);
				}
			}
		}
		// check room type
		Long tpe = null,tpp = null;
		if (cmd_arr[4].equals("single")) {
			tpe = mainhotellist.get(Integer.parseInt(cmd_arr[1])).singleroom.number;
			tpp = mainhotellist.get(Integer.parseInt(cmd_arr[1])).singleroom.roomprice;
		}	
		else if (cmd_arr[4].equals("double")) {
			tpe = mainhotellist.get(Integer.parseInt(cmd_arr[1])).doubleroom.number;
			tpp = mainhotellist.get(Integer.parseInt(cmd_arr[1])).doubleroom.roomprice;
		}	
		else if (cmd_arr[4].equals("quad")) {
			tpe = mainhotellist.get(Integer.parseInt(cmd_arr[1])).quadroom.number;
			tpp = mainhotellist.get(Integer.parseInt(cmd_arr[1])).quadroom.roomprice;
		}
			
		// check if there's any empty room left
		int avail = 0;
		for (int i = 0; i < daybetween; i++) {
			if ((tpe - everydayhotel[Hotel.datetonumber(checkinmonth, checkinday + i)]) < Integer.parseInt(cmd_arr[5])) {
				String formatted=Hotel.numbertodate(Hotel.datetonumber(checkinmonth, checkinday + i));
				System.out.println("失敗: " + formatted + " " + cmd_arr[4] + " 房間數量不足/房間已售罄 ");
				System.out.println("please enter anything to restart the process");
				Scanner ava2 = new Scanner(System.in);
				String cmd_str2 = ava.nextLine();
				book();
				return;
			} else
				avail++;
		}
		// record book id
		FileReader fr = new FileReader("d.txt");
		BufferedReader br = new BufferedReader(fr);
		String bookid = null;
		if (br.ready()) {
			bookid = br.readLine();
		}
		fr.close();
		Integer newbookid = Integer.parseInt(bookid) + 1;
		FileWriter fw = new FileWriter("d.txt");
		fw.write(newbookid.toString());
		fw.flush();
		br.close();
		fw.close();
		// booking confirmed
		for (int i = 0; i < daybetween; i++) {
			Hotel.writeDataLineByLine(cmd_arr[0], cmd_arr[1], cmd_arr[4], cmd_arr[5],
					Hotel.datetonumber(checkinmonth, checkinday + i), newbookid);
		}
		System.out.println(newbookid + "  " + cmd_arr[0]);
		System.out.println("hotel id: " + cmd_arr[1]);
		System.out.println("roomtype: " + cmd_arr[4] + " with " + cmd_arr[5] + " rooms");
		System.out.println(cmd_arr[2] + "-" + cmd_arr[3]);
		System.out.println("共入住  "+ (daybetween) + " 晚");
		System.out.println("總價" + Integer.parseInt(cmd_arr[5])*tpp * (daybetween));
	}
}
