import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import org.json.simple.parser.ParseException;

import com.opencsv.CSVReader;

public class check {
	static void check() throws IOException, ParseException {
		System.out.println("enter<user id>,<book id>");
		System.out.println("ex: aaa,4");
		Scanner ava = new Scanner(System.in);
		String cmd_str = ava.nextLine();
		String[] cmd_arr = cmd_str.split(",");
		CSVReader reader = new CSVReader(new FileReader("data.csv"));
		List<String[]> csvBody = reader.readAll();
		String checkin = null, hotellid = null, room = null, roomnum = null, checkout = null;
		Long price = null;
		ArrayList<Hotel> mainhotellist = ReadJSON.Reader();
		int cou = 0;// to record checkin date
		for (int i = 0; i < csvBody.size(); i++) {
			if (csvBody.get(i)[5].equals(cmd_arr[1]) && csvBody.get(i)[0].equals(cmd_arr[0])) {
				cou++;
				if (cou == 1) {
					checkin = csvBody.get(i)[4];
				}
				hotellid = csvBody.get(i)[1];
				room = csvBody.get(i)[2];
				roomnum = csvBody.get(i)[3];
				checkout = csvBody.get(i)[4];
			}
		}
		if (cou == 0) {
			System.out.println("�z��J�������ѧO�X/�q��N�����~�A�Э��s��J");
			check();
			return;
		}
		for (int i = 0; i < mainhotellist.size(); i++) {
			if (mainhotellist.get(i).hotelid.equals(Long.parseLong(hotellid))) {
				if (room.equals("single"))
					price = mainhotellist.get(i).singleroom.roomprice;
				else if (room.equals("double"))
					price = mainhotellist.get(i).doubleroom.roomprice;
				else if (room.equals("quad"))
					price = mainhotellist.get(i).quadroom.roomprice;
			}
		}
		System.out.println("���]�s��:" + hotellid);
		System.out.println("�Ы�:" + room + "�ƶq:" + roomnum);
		String checkinfor = Hotel.numbertodate(Integer.parseInt(checkin));
		String checkoutfor =  Hotel.numbertodate(Integer.parseInt(checkout));
		System.out.println(checkinfor + "-" + checkoutfor);
		System.out.println("�@�J��" + (Integer.parseInt(checkout) - Integer.parseInt(checkin) + 1) + "��");
		System.out.println("�`��:"
				+ ((Integer.parseInt(checkout) - Integer.parseInt(checkin) + 1) * (price) * Integer.parseInt(roomnum)));
	}
}
