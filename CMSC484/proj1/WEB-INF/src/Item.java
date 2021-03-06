public class Item {
	private String id, title, author, genre, binding, availability;
	private double price;

	public Item(String id, String title, String author, String genre, String binding, double price, String availability) {
		this.id = id;
		this.title = title;
		this.author = author;
		this.genre = genre;
		this.binding = binding;
		this.price = price;
		this.availability = availability;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public String getGenre() {
		return genre;
	}

	public void setGenre(String genre) {
		this.genre = genre;
	}

	public String getBinding() {
		return binding;
	}

	public void setBinding(String binding) {
		this.binding = binding;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String getAvailability() {
		return availability;
	}

	public void setAvailability(String availability) {
		this.availability = availability;
	}

	public boolean equals(Object o) {
		if (!(o instanceof Item))
			return false;

		return getId().equals(((Item) o).getId());
	}
}
