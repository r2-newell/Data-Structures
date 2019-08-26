package queue;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*
		 * Let's use our generic queue. This example will be a shopping / supermarket list
		 * I felt hungry while doing this one. Hence, I thought of my super market shopping list. Would you 
		 * like any thing at the supermarket? :)
		 * */
		
		Queue<String> shoppingList = null;
		try {
			shoppingList = new Queue<String>(10);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		shoppingList.enqueue("Pork Chops"); 
		shoppingList.enqueue("Carton of Milk"); 
		shoppingList.enqueue("Hand towels"); 
		shoppingList.enqueue("Cinnamon Toast Cereal");
		shoppingList.enqueue("Case of water");
		shoppingList.enqueue("Some vegetables"); 
		shoppingList.enqueue("Figure out something else to add dummy!!!");
		
		System.out.println("-------------Supermarket List---------");
		for(String item : shoppingList)
		System.out.println(item); 
		System.out.println(shoppingList.dequeue() + " was just removed from your list.");
		System.out.println(shoppingList.dequeue() + " was just removed from your list.");
		System.out.println(shoppingList.dequeue() + " was just removed from your list.");
		System.out.println(shoppingList.dequeue() + " was just removed from your list.");
		System.out.println(shoppingList.dequeue() + " was just removed from your list.");
		System.out.println(shoppingList.getSize() + " is the current number of items on your list"); 
		System.out.println("-------------Supermarket List---------");
		for(String item : shoppingList)
			System.out.println(item); 
		
		
		
	}

}
