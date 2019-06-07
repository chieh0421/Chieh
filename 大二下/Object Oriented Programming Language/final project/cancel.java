import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import org.json.simple.parser.ParseException;

import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;

public class cancel {
	static void cancel() throws FileNotFoundException, IOException, ParseException {
		System.out.println("enter<user id>,<book id>,<action>");
		System.out.println("ex: aaa,4,1");
		System.out.println("action 0: cancel, action 1: reduce, action 2: change date");
		ArrayList<Hotel> mainhotellist = ReadJSON.Reader();
		Scanner ava = new Scanner(System.in);
		String cmd_str = ava.nextLine();
		String[] cmd_arr = cmd_str.split(",");
		CSVReader reader = new CSVReader(new FileReader("data.csv"));
		List<String[]> csvBody = reader.readAll();
		// get CSV row column and replace with by using row and column
		int p = 0;
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(cmd_arr[1])) {
				p++;
			}
		}
		if (p == 0) {
			System.out.println("退訂/修改失敗，此訂位代號不存在");
			cancel();
		}
		switch (cmd_arr[2]) {
		case "0":
			canceler(cmd_arr[0], cmd_arr[1]);
			break;
		case "1":
			System.out.println("enter<room>,<number>, ex: single,4");
			Scanner avareduce = new Scanner(System.in);
			String cmd_str_reduce = avareduce.nextLine();
			String[] cmd_arr_reduce = cmd_str_reduce.split(",");
			reducer(cmd_arr[0], cmd_arr[1], cmd_arr_reduce[0], cmd_arr_reduce[1]);
			break;
		case "2":
			System.out.println("enter<check in date>,<check out date>, ex: 5/16,5/20");
			Scanner avadate = new Scanner(System.in);
			String cmd_str_date = avadate.nextLine();
			String[] cmd_arr_date = cmd_str_date.split(",");
			String[] checkindate = cmd_arr_date[0].split("/");
			int checkinmonth = Integer.parseInt(checkindate[0]);
			int checkinday = Integer.parseInt(checkindate[1]);
			String[] checkoutdate = cmd_arr_date[1].split("/");
			int checkoutmonth = Integer.parseInt(checkoutdate[0]);
			int checkoutday = Integer.parseInt(checkoutdate[1]);
			datechanger(cmd_arr[0], cmd_arr[1], Hotel.datetonumber(checkinmonth, checkinday),
					Hotel.datetonumber(checkoutmonth, checkoutday));
			break;
		default:
			System.out.println("please enter correct action!");
			break;
		}

	}
	private static void datechanger(String userid, String bookid, Integer checkin, Integer checkout)
			throws IOException, ParseException {
		CSVReader reader = new CSVReader(new FileReader("data.csv"));
		List<String[]> csvBody = reader.readAll();
		// get CSV row column and replace with by using row and column
		String save = null;
		// save original number
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid)) {
				save = csvBody.get(i)[3];
			}
		}

		// set number to 0 for all the data in same id
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid)) {
				csvBody.get(i)[3] = "0";
			}
		}
		// change lines corresponding to the input data to save
		for (int j = 0; j < checkout - checkin + 1; j++) {
			for (int i = 0; i < csvBody.size(); i++) {
				if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid)
						&& csvBody.get(i)[4].equals(((Integer) (checkin + j)).toString())) {
					csvBody.get(i)[3] = save;
				}
			}

		}
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid) && csvBody.get(i)[3].equals("0")) {
				csvBody.get(i)[5] = null;
				csvBody.get(i)[0] = null;
			}
		}
		reader.close();
		// Write to CSV file which is open
		CSVWriter writer = new CSVWriter(new FileWriter("data.csv"));
		writer.writeAll(csvBody);
		writer.flush();
		writer.close();
		String formatted = Hotel.numbertodate(checkin);
		String formatted2 = Hotel.numbertodate(checkout);
		System.out.println("修改成功，已將您的住宿日期變更為" + formatted + "-" + formatted2);
	}
	private static void reducer(String userid, String bookid, String roomtype, String number) throws IOException {
		CSVReader reader = new CSVReader(new FileReader("data.csv"));
		List<String[]> csvBody = reader.readAll();
		String save = null;
		boolean found = false;
		// get CSV row column and replace with by using row and column
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid)
					&& csvBody.get(i)[2].equals(roomtype)){
				found = true;
				if((Integer) (Integer.parseInt(csvBody.get(i)[3]) - Integer.parseInt(number)) >= 0) {
					csvBody.get(i)[3] = ((Integer) (Integer.parseInt(csvBody.get(i)[3]) - Integer.parseInt(number)))
							.toString();
					save = csvBody.get(i)[3];
					if (save == "0") {
						csvBody.get(i)[5] = null;
						csvBody.get(i)[0] = null;
					}
				}
				else {
					System.out.println("修改失敗，修改數量超過訂房數量 ");
					return;
				}
			}
			if(!found) {
				System.out.println("修改失敗，您輸入的身分識別碼/訂位代號有誤 ");

			}
		}

		reader.close();
		// Write to CSV file which is open
		CSVWriter writer = new CSVWriter(new FileWriter("data.csv"));
		writer.writeAll(csvBody);
		writer.flush();
		writer.close();
		System.out.println("修改成功，已將您的訂房數量變更為 " + roomtype + "," + save);
	}
	private static void canceler(String userid, String bookid) throws IOException {
		CSVReader reader = new CSVReader(new FileReader("data.csv"));
		List<String[]> csvBody = reader.readAll();
		// get CSV row column and replace with by using row and column
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(bookid) && csvBody.get(i)[0].equals(userid)) {
				csvBody.get(i)[5] = null;
				csvBody.get(i)[0] = null;
				csvBody.get(i)[3] = "0";
			}
		}
		reader.close();
		// Write to CSV file which is open
		CSVWriter writer = new CSVWriter(new FileWriter("data.csv"));
		writer.writeAll(csvBody);
		writer.flush();
		writer.close();
		System.out.println("退訂成功，已取消您的訂房紀錄");
	}
}
