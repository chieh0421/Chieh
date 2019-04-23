
public class GreenCrud {
	static int[] arr = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946};
	public int calPopulation(int initialSize, int days) {
		int pos = days/5;
		return initialSize*arr[pos];		
	}
}
