
package queue;

import java.util.Iterator;

/**
 * @author Romario Newell
 * Date: August 17, 2019 
 * Implementation of the array version of a queue. 
 */

public class Queue <Item> implements Iterable<Item>{
	
	private Item [] queue;//queue of items
	private int size; //current size of queue
	private int front; //front of the queue
	private int rear; //rear of the queue
	
	@SuppressWarnings("unchecked")
	public Queue(int size) throws Exception
	{
		queue = (Item []) new Object[size]; 
		if(queue == null)
			throw new Exception("Could not allocate memory for queue."); 
		front = rear = this.size = 0; 
	}
	/*
	 * Enqueue operation. Returns true when operation was successful, otherwise false.
	 * */
	public boolean enqueue(Item item)
	{
		if(size == queue.length)
		{
			System.out.println("Overflow error. Queue is full."); 
			return false; 
		}
		queue[rear] = item; 
		rear = (rear + 1) % queue.length;//this makes rear wrap around to the start index when reaches queue.length
		size++;
		return true;
	}
	
	/*
	 * Returns an item dequeue, else a null pointer.
	 * */
	public Item dequeue()
	{
		if(size == 0)
		{
			System.out.println("Underflow error. Queue empty.");
			return null; 
		}
		
		Item item = queue[front]; 
		queue[front] = null; 
		front = (front + 1) % queue.length;//makes front wrap around to the start index when reaches queue.length
		size--; 
		return item;
	}
	
	/*
	 * Straightforward. 
	 * */
	public int getSize() {return size;}
	public boolean isFull() {return size == queue.length? true : false;}
	public boolean isEmpty() {return size  == 0? true : false; }
	/*
	 * Queue iterator that implements the iterator interface. Gives us the ability to use the for each construct
	 * and traverse through the queue without caring about the type underneath. A good Java book like Dietel should 
	 * explain iterators. By the way I'm fairly new to iterators and generics.
	 * */
	private class queueIterator implements Iterator<Item>
	{
		private int start = front; 
		int count = 0; 
		
		@Override
		public boolean hasNext() {
			if(count != size)
				return true;
			else
				return false; 
		}

		@Override
		public Item next() {
			Item item = queue[start]; 
			start = (start + 1) % queue.length;
			count++;
			return item;
		}
		
	}
	
	/*
	 * Erases the entire queue
	 * */
	@SuppressWarnings("unchecked")
	public void erase() throws Exception
	{
		queue = null; 
		queue =  (Item []) new Object[size];
		
		if(queue == null)
			throw new Exception("Could not allocate memory for the  queue"); 
		front = rear = size = 0; 
	}
	

	public boolean copy(Iterator iterator) throws NullPointerException
	{
		front = rear = size = 0; 
		if(iterator == null)
			throw new NullPointerException("A null value was passed for iterator.");
		
		while(iterator.hasNext() && size != queue.length)
			enqueue((Item) iterator.next()); 
		return true;
	}
	


	@Override
	public Iterator<Item> iterator() {
		// TODO Auto-generated method stub
		return new queueIterator();
	}
}
