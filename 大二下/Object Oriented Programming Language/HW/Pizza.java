
public class Pizza {
	private String size;
	private int numberOfCheese;
	private int numberOfPepperoni;
	private int numberOfHam;
	public Pizza() {
		size = "small";
		numberOfCheese = 1;
		numberOfPepperoni = 1;
		numberOfHam = 1;
	}
	public Pizza(String Size, int Cheese, int Pepperoni, int Ham) {
		size = Size;
		numberOfCheese = Cheese;
		numberOfPepperoni = Pepperoni;
		numberOfHam = Ham;
	}
	public void setSize(String Size){
		size = Size;
	}
	public void setNumberOfCheese(int NumberOfCheese) {
		numberOfCheese = NumberOfCheese;
	}
	public void setNumberOfPepperoni(int NumberOfPepperoni) {
		numberOfPepperoni = NumberOfPepperoni;
	}
	public void setNumberOfHam(int NumberOfHam) {
		numberOfHam = NumberOfHam;
	}
	public String getSize() {
		return size;
	}
	public int getNumberOfCheese() {
		return numberOfCheese;
	}
	public int getNumberOfPepperoni() {
		return numberOfPepperoni;
	}
	public int getNumberOfHam() {
		return numberOfHam;
	}
	public double calcCost() {
		double price = 0.0;
		if (size == "small")
			price += 10.0;
		else if (size == "medium")
			price += 12.0;
		else if (size == "large")
			price += 14.0;
		price += 2.0*(numberOfCheese + numberOfPepperoni + numberOfHam);
		return price;
	}
	public String toString() {
		return "size = " + size + ", numOfCheese = " + numberOfCheese + ", numOfPepperoni = " + numberOfPepperoni + ", numOfHam = " + numberOfHam;
	}
	public boolean equals(Pizza OtherPizza) {
		boolean result = true;
		if (size!= OtherPizza.getSize() || numberOfCheese!= OtherPizza.getNumberOfCheese() || numberOfPepperoni!= OtherPizza.getNumberOfPepperoni() || numberOfHam!= OtherPizza.getNumberOfHam())
			result = false;
		return result;
	}
}
