/**
 * 
 */
package queue;

import java.util.Iterator;

/**
 * @author Romario Newell
 * Date: August 17, 2019
 * Linked list implementation of a Queue. Our queue is a generic queue and can use any type.
 */

public class Queue <Item> implements Iterable<Item>{
	
	
	private class Node
	{
		private Item data; //data portion of the node 
		private Node next; //next node within the queue
		
		public Node(Item data, Node next)
		{
			this.data = data; 
			this.next = next;
		}
		
		public Item getData() {return data;}
		public Node getNext() {return next;}
		public void setData(Item data) {this.data = data;}
		public void setNext(Node next) {this.next = next;}
	}
	
	private Node front;//front of the queue
	private Node rear; //rear of the queue
	private int size;// current size of the queue
	
	public Queue()
	{
		front = rear = null; 
		size = 0; 
	}
	
	public boolean isEmpty() {return front == null && rear == null? true : false;}
	public int getSize() {return size;}
	
	public boolean enqueue(Item item)
	{
		Node temp = new Node(item, null); 
		if(temp == null)//checks to see if we could allocate memory for the new node. False upon fail.
			return false; 
		
		/*
		 * Insertion of the new item below.
		 * */
		if(isEmpty())
			rear = front = temp; 
		else
		{
			rear.setNext(temp);
			rear = temp; 
		}
		size++; 
		return true; 
	}
	
	public Item dequeue()
	{
		if(isEmpty())
			return null;
		
		Item item = front.getData(); 
		Node tempFront = front.getNext(); 
		
		/*
		 *When there is only one element in the list we need to set front = rear = null. The code below achieves this. 
		 * 
		 * */
		if(front == rear)
			rear = null; 
		front = null; 
		front = tempFront; 
		size--;
		return item; 
	}
	
	/*
	 * Returns all memory used
	 * */
	public void destroy()
	{
		Item item;
		while((item = dequeue()) != null); 
	}
	
	private class QueueIterator implements Iterator<Item>
	{
		Node start = front; 
		@Override
		public boolean hasNext() {
			if(start == null)
				return false;
			else 
				return true;
		}

		@Override
		public Item next() {
			// TODO Auto-generated method stub
			Item item = start.getData();
			start = start.getNext();
			return item; 
		}
		
	}

	@Override
	public Iterator<Item> iterator() {
		// TODO Auto-generated method stub
		return new QueueIterator();
	}
	
	
}
